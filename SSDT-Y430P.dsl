// Instead of providing patched DSDT/SSDT, just include a single SSDT
// and do the rest of the work in config.plist

// Created by : z39
// Credits : RehabMan

DefinitionBlock("", "SSDT", 2, "Y430P", "_HACK", 0)
{
    External(_SB.PCI0, DeviceObj)
    External(_SB.PCI0.LPCB, DeviceObj)

    // All _OSI calls in DSDT are routed to XOSI...
    // XOSI simulates "Windows 2012" (which is Windows 8)
    // Note: According to ACPI spec, _OSI("Windows") must also return true
    //  Also, it should return true for all previous versions of Windows.
    Method(XOSI, 1)
    {
        // simulation targets
        // source: (google 'Microsoft Windows _OSI')
        //  http://download.microsoft.com/download/7/E/7/7E7662CF-CBEA-470B-A97E-CE7CE0D98DC2/WinACPI_OSI.docx
        Store(Package()
        {
            "Windows",              // generic Windows query
            "Windows 2009",         // Windows 7/Windows Server 2008 R2
            "Windows 2012",         // Windows 8/Windows Server 2012
            "Windows 2013",         // Windows 8.1/Windows Server 2012 R2
            "Windows 2015",         // Windows 10/Windows Server TP
            "Windows 2016",         // Windows 10, version 1607
            "Windows 2017",         // Windows 10, version 1703
            "Windows 2017.2",       // Windows 10, version 1709
            "Windows 2018",         // Windows 10, version 1803
            "Windows 2018.2",       // Windows 10, version 1809
            "Windows 2019",         // Windows 10, version 1903
            "Windows 2019.2"        // Windows 10, version 1909
         }, Local0)
        Return (Ones != Match(Local0, MEQ, Arg0, MTR, 0, 0))
    }

//  USB related
//

    Method(GPRW, 2)
    {
        If (0x6d == Arg0) { Return (Package() { 0x6d, Zero, }) }
        If (0x0d == Arg0) { Return (Package() { 0x0d, Zero, }) }
        External(XPRW, MethodObj)
        Return (XPRW(Arg0, Arg1))
    }

    // Override for USBInjectAll.kext
    Device(UIAC)
    {
        Name(_HID, "UIA00000")
        Name(RMCF, Package()
        {
            // XHC overrides
            "8086_8c31", Package()
            {
                //"port-count", Buffer() { 21, 0, 0, 0 },
                "ports", Package()
                {
                    "HS01", Package()    // Camera
                    {
                        "UsbConnector", 255,
                        "port", Buffer() { 0x01, 0, 0, 0 },
                    },
                    "HS02", Package()    // USB 2.0 far right
                    {
                        "UsbConnector", 0,
                        "port", Buffer() { 0x02, 0, 0, 0 },
                    },
                    "HS03", Package()    // HS component of USB 3.0 left
                    {
                        "UsbConnector", 3,
                        "port", Buffer() { 0x03, 0, 0, 0 },
                    },
                    "HS07", Package()    // Bluetooth 
                    {
                        "UsbConnector", 255,
                        "port", Buffer() { 0x07, 0, 0, 0 },
                    },
                    "HS10", Package()    // USB 2.0 near right
                    {
                        "UsbConnector", 0,
                        "port", Buffer() { 0x10, 0, 0, 0 },
                    },

                    "SSP2", Package()    // USB 3.0 near left
                    {
                        "UsbConnector", 3,
                        "port", Buffer() { 0x11, 0, 0, 0 },
                    },
                    "SSP4", Package()    // Card Reader
                    {
                        "UsbConnector", 255,
                        "port", Buffer() { 0x13, 0, 0, 0 },
                    },
                },
            },
        })
    }


//
// Disabling EHCI #1 (and EHCI #2)
//

    External(_SB.PCI0.EH01, DeviceObj)
    External(_SB.PCI0.EH02, DeviceObj)
    Scope(_SB.PCI0)
    {
        // registers needed for disabling EHC#1
        Scope(EH01)
        {
            OperationRegion(PSTS, PCI_Config, 0x54, 2)
            Field(PSTS, WordAcc, NoLock, Preserve)
            {
                PSTE, 2  // bits 2:0 are power state
            }
        }
        // registers needed for disabling EHC#1
        Scope(EH02)
        {
            OperationRegion(PSTS, PCI_Config, 0x54, 2)
            Field(PSTS, WordAcc, NoLock, Preserve)
            {
                PSTE, 2  // bits 2:0 are power state
            }
        }
        Scope(LPCB)
        {
            OperationRegion(RMLP, PCI_Config, 0xF0, 4)
            Field(RMLP, DWordAcc, NoLock, Preserve)
            {
                RCB1, 32, // Root Complex Base Address
            }
            // address is in bits 31:14
            OperationRegion(FDM1, SystemMemory, (RCB1 & Not((1<<14)-1)) + 0x3418, 4)
            Field(FDM1, DWordAcc, NoLock, Preserve)
            {
                ,13,    // skip first 13 bits
                FDE2,1, // should be bit 13 (0-based) (FD EHCI#2)
                ,1,
                FDE1,1, // should be bit 15 (0-based) (FD EHCI#1)
            }
        }
        Device(RMD1)
        {
            //Name(_ADR, 0)
            Name(_HID, "RMD10000")
            Method(_INI)
            {
                // disable EHCI#1
                // put EHCI#1 in D3hot (sleep mode)
                ^^EH01.PSTE = 3
                // disable EHCI#1 PCI space
                ^^LPCB.FDE1 = 1

                // disable EHCI#2
                // put EHCI#2 in D3hot (sleep mode)
                ^^EH02.PSTE = 3
                // disable EHCI#2 PCI space
                ^^LPCB.FDE2 = 1
            }
        }
    }

// Automatic injection of HDAU properties
    
    External(_SB.PCI0.HDAU, DeviceObj)
    
    Method(_SB.PCI0.HDAU._DSM, 4)
    {
        If (!Arg2) { Return (Buffer() { 0x03 } ) }
        Return (Package ()
        {
            "layout-id", Buffer() { 43, 0, 0, 0 },
            "hda-gfx", Buffer() { "onboard-1" },
        })
    }
    
    // Automatic injection of HDEF properties

    External(_SB.PCI0.HDEF, DeviceObj)
    
    Method(_SB.PCI0.HDEF._DSM, 4)
    {
        If (!Arg2) { Return (Buffer() { 0x03 } ) }
        Return(Package()
        {
            "layout-id", Buffer() { 43, 0, 0, 0 },
            "hda-gfx", Buffer() { "onboard-1" },
            "PinConfigurations", Buffer() { },
        })
    }

//
// For disabling the discrete GPU
//

    External(_SB.PCI0.PEG0.PEGP._OFF, MethodObj)
    External(_SB.PCI0.PEGP.DGFX._OFF, MethodObj)

    Device(RMD1)
    {
        Name(_HID, "RMD10000")
        Method(_INI)
        {
            // disable discrete graphics (Nvidia/Radeon) if it is present
            If (CondRefOf(\_SB.PCI0.PEG0.PEGP._OFF)) { \_SB.PCI0.PEG0.PEGP._OFF() }
            If (CondRefOf(\_SB.PCI0.PEGP.DGFX._OFF)) { \_SB.PCI0.PEGP.DGFX._OFF() }
        }
    }

//
// Display backlight implementation
//
// From SSDT-PNLF.dsl
// Adding PNLF device for IntelBacklight.kext or AppleBacklight.kext+AppleBacklightFixup.kext

#define FBTYPE_SANDYIVY 1
#define FBTYPE_HSWPLUS 2
#define FBTYPE_CFL 3

#define SANDYIVY_PWMMAX 0x710
#define HASWELL_PWMMAX 0xad9
#define SKYLAKE_PWMMAX 0x56c
#define CUSTOM_PWMMAX_07a1 0x07a1
#define CUSTOM_PWMMAX_1499 0x1499
#define COFFEELAKE_PWMMAX 0xffff

    External(RMCF.BKLT, IntObj)
    External(RMCF.LMAX, IntObj)
    External(RMCF.LEVW, IntObj)
    External(RMCF.GRAN, IntObj)
    External(RMCF.FBTP, IntObj)
    External(_SB.PCI0.IGPU, DeviceObj)

    Scope(_SB.PCI0.IGPU)
    {
        OperationRegion(RMP3, PCI_Config, 0, 0x14)
    }

    // For backlight control
    Device(_SB.PCI0.IGPU.PNLF)
    {
        Name(_ADR, Zero)
        Name(_HID, EisaId ("APP0002"))
        Name(_CID, "backlight")
        // _UID is set depending on PWMMax to match profiles in AppleBacklightFixup.kext Info.plist
        // 14: Sandy/Ivy 0x710
        // 15: Haswell/Broadwell 0xad9
        // 16: Skylake/KabyLake 0x56c (and some Haswell, example 0xa2e0008)
        // 17: custom LMAX=0x7a1
        // 18: custom LMAX=0x1499
        // 19: CoffeeLake 0xffff
        // 99: Other (requires custom AppleBacklightInjector.kext/AppleBackightFixup.kext)
        Name(_UID, 0)
        Name(_STA, 0x0B)

        Field(^RMP3, AnyAcc, NoLock, Preserve)
        {
            Offset(0x02), GDID,16,
            Offset(0x10), BAR1,32,
        }

        // IGPU PWM backlight register descriptions:
        //   LEV2 not currently used
        //   LEVL level of backlight in Sandy/Ivy
        //   P0BL counter, when zero is vertical blank
        //   GRAN see description below in INI1 method
        //   LEVW should be initialized to 0xC0000000
        //   LEVX PWMMax except FBTYPE_HSWPLUS combo of max/level (Sandy/Ivy stored in MSW)
        //   LEVD level of backlight for Coffeelake
        //   PCHL not currently used
        OperationRegion(RMB1, SystemMemory, BAR1 & ~0xF, 0xe1184)
        Field(RMB1, AnyAcc, Lock, Preserve)
        {
            Offset(0x48250),
            LEV2, 32,
            LEVL, 32,
            Offset(0x70040),
            P0BL, 32,
            Offset(0xc2000),
            GRAN, 32,
            Offset(0xc8250),
            LEVW, 32,
            LEVX, 32,
            LEVD, 32,
            Offset(0xe1180),
            PCHL, 32,
        }

        // INI1 is common code used by FBTYPE_HSWPLUS and FBTYPE_CFL
        Method(INI1, 1)
        {
            // INTEL OPEN SOURCE HD GRAPHICS, INTEL IRIS GRAPHICS, AND INTEL IRIS PRO GRAPHICS PROGRAMMER'S REFERENCE MANUAL (PRM)
            // FOR THE 2015-2016 INTEL CORE PROCESSORS, CELERON PROCESSORS AND PENTIUM PROCESSORS BASED ON THE "SKYLAKE" PLATFORM
            // Volume 12: Display (https://01.org/sites/default/files/documentation/intel-gfx-prm-osrc-skl-vol12-display.pdf)
            //   page 189
            //   Backlight Enabling Sequence
            //   Description
            //   1. Set frequency and duty cycle in SBLC_PWM_CTL2 Backlight Modulation Frequency and Backlight Duty Cycle.
            //   2. Set granularity in 0xC2000 bit 0 (0 = 16, 1 = 128).
            //   3. Enable PWM output and set polarity in SBLC_PWM_CTL1 PWM PCH Enable and Backlight Polarity.
            //   4. Change duty cycle as needed in SBLC_PWM_CTL2 Backlight Duty Cycle.
            // This 0xC value comes from looking what OS X initializes this
            // register to after display sleep (using ACPIDebug/ACPIPoller)
            If (0 == (2 & Arg0))
            {
                Local5 = 0xC0000000
                If (CondRefOf(\RMCF.LEVW)) { If (Ones != \RMCF.LEVW) { Local5 = \RMCF.LEVW } }
                ^LEVW = Local5
            }
            // from step 2 above (you may need 1 instead)
            If (4 & Arg0)
            {
                If (CondRefOf(\RMCF.GRAN)) { ^GRAN = \RMCF.GRAN }
                Else { ^GRAN = 0 }
            }
        }

        Method(_INI)
        {
            // IntelBacklight.kext takes care of this at load time...
            // If RMCF.BKLT does not exist, it is assumed you want to use AppleBacklight.kext...
            Local4 = 1
            If (CondRefOf(\RMCF.BKLT)) { Local4 = \RMCF.BKLT }
            If (!(1 & Local4)) { Return }

            // Adjustment required when using AppleBacklight.kext
            Local0 = ^GDID
            Local2 = Ones
            If (CondRefOf(\RMCF.LMAX)) { Local2 = \RMCF.LMAX }
            // Determine framebuffer type (for PWM register layout)
            Local3 = 0
            If (CondRefOf(\RMCF.FBTP)) { Local3 = \RMCF.FBTP }

            // Now fixup the backlight PWM depending on the framebuffer type
            // At this point:
            //   Local4 is RMCF.BLKT value, if specified (default is 1)
            //   Local0 is device-id for IGPU
            //   Local2 is LMAX, if specified (Ones means based on device-id)
            //   Local3 is framebuffer type

            // check Sandy/Ivy
            If (FBTYPE_SANDYIVY == Local3 || Ones != Match(Package()
            {
                // Sandy HD3000
                0x010b, 0x0102,
                0x0106, 0x1106, 0x1601, 0x0116, 0x0126,
                0x0112, 0x0122,
                // Ivy
                0x0152, 0x0156, 0x0162, 0x0166,
                0x016a,
                // Arrandale
                0x0046, 0x0042,
            }, MEQ, Local0, MTR, 0, 0))
            {
                if (Ones == Local2) { Local2 = SANDYIVY_PWMMAX }
                // change/scale only if different than current...
                Local1 = ^LEVX >> 16
                If (!Local1) { Local1 = Local2 }
                If (Local2 != Local1)
                {
                    // set new backlight PWMMax but retain current backlight level by scaling
                    Local0 = (^LEVL * Local2) / Local1
                    //REVIEW: wait for vblank before setting new PWM config
                    //For (Local7 = ^P0BL, ^P0BL == Local7, ) { }
                    Local3 = Local2 << 16
                    If (Local2 > Local1)
                    {
                        // PWMMax is getting larger... store new PWMMax first
                        ^LEVX = Local3
                        ^LEVL = Local0
                    }
                    Else
                    {
                        // otherwise, store new brightness level, followed by new PWMMax
                        ^LEVL = Local0
                        ^LEVX = Local3
                    }
                }
            }
            // check CoffeeLake
            ElseIf (FBTYPE_CFL == Local3 || Ones != Match(Package()
            {
                // CoffeeLake identifiers from AppleIntelCFLGraphicsFramebuffer.kext
                0x3e9b, 0x3ea5, 0x3e92, 0x3e91,
            }, MEQ, Local0, MTR, 0, 0))
            {
                if (Ones == Local2) { Local2 = COFFEELAKE_PWMMAX }
                INI1(Local4)
                // change/scale only if different than current...
                Local1 = ^LEVX
                If (!Local1) { Local1 = Local2 }
                If (Local2 != Local1)
                {
                    // set new backlight PWMMax but retain current backlight level by scaling
                    Local0 = (^LEVD * Local2) / Local1
                    //REVIEW: wait for vblank before setting new PWM config
                    //For (Local7 = ^P0BL, ^P0BL == Local7, ) { }
                    If (Local2 > Local1)
                    {
                        // PWMMax is getting larger... store new PWMMax first
                        ^LEVX = Local2
                        ^LEVD = Local0
                    }
                    Else
                    {
                        // otherwise, store new brightness level, followed by new PWMMax
                        ^LEVD = Local0
                        ^LEVX = Local2
                    }
                }
            }
            // otherwise must be Haswell/Broadwell/Skylake/KabyLake/KabyLake-R (FBTYPE_HSWPLUS)
            Else
            {
                if (Ones == Local2)
                {
                    // check Haswell and Broadwell, as they are both 0xad9 (for most common ig-platform-id values)
                    If (Ones != Match(Package()
                    {
                        // Haswell
                        0x0d26, 0x0a26, 0x0d22, 0x0412, 0x0416, 0x0a16, 0x0a1e, 0x0a1e, 0x0a2e, 0x041e, 0x041a,
                        // Broadwell
                        0x0bd1, 0x0bd2, 0x0BD3, 0x1606, 0x160e, 0x1616, 0x161e, 0x1626, 0x1622, 0x1612, 0x162b,
                    }, MEQ, Local0, MTR, 0, 0))
                    {
                        Local2 = HASWELL_PWMMAX
                    }
                    Else
                    {
                        // assume Skylake/KabyLake/KabyLake-R, both 0x56c
                        // 0x1916, 0x191E, 0x1926, 0x1927, 0x1912, 0x1932, 0x1902, 0x1917, 0x191b,
                        // 0x5916, 0x5912, 0x591b, others...
                        Local2 = SKYLAKE_PWMMAX
                    }
                }
                INI1(Local4)
                // change/scale only if different than current...
                Local1 = ^LEVX >> 16
                If (!Local1) { Local1 = Local2 }
                If (Local2 != Local1)
                {
                    // set new backlight PWMAX but retain current backlight level by scaling
                    Local0 = (((^LEVX & 0xFFFF) * Local2) / Local1) | (Local2 << 16)
                    //REVIEW: wait for vblank before setting new PWM config
                    //For (Local7 = ^P0BL, ^P0BL == Local7, ) { }
                    ^LEVX = Local0
                }
            }

            // Now Local2 is the new PWMMax, set _UID accordingly
            // The _UID selects the correct entry in AppleBacklightFixup.kext
            If (Local2 == SANDYIVY_PWMMAX) { _UID = 14 }
            ElseIf (Local2 == HASWELL_PWMMAX) { _UID = 15 }
            ElseIf (Local2 == SKYLAKE_PWMMAX) { _UID = 16 }
            ElseIf (Local2 == CUSTOM_PWMMAX_07a1) { _UID = 17 }
            ElseIf (Local2 == CUSTOM_PWMMAX_1499) { _UID = 18 }
            ElseIf (Local2 == COFFEELAKE_PWMMAX) { _UID = 19 }
            Else { _UID = 99 }
        }
    }

//
// Keyboard/Trackpad
//

    External(_SB.PCI0.LPCB.PS2K, DeviceObj)
    Scope (_SB.PCI0.LPCB.PS2K)
    {
        // Select specific keyboard map in VoodooPS2Keyboard.kext
        Method(_DSM, 4)
        {
            If (!Arg2) { Return (Buffer() { 0x03 } ) }
            Return (Package()
            {
                "RM,oem-id", "LENOVO",
                "RM,oem-table-id", "Haswell-Ideapad",//Lenovo Y410P/Y510P/Y430P
            })
        }

        Name(RMCF, Package()
        {
            "Controller", Package()
            {
                "WakeDelay", 0,
            },
            "Sentelic FSP", Package()
            {
                "DisableDevice", ">y",
            },
            "ALPS GlidePoint", Package()
            {
                "DisableDevice", ">y",
            },
            "Synaptics TouchPad", Package()
            {
                "MultiFingerVerticalDivisor", 9,
                "MultiFingerHorizontalDivisor", 9,
                "MomentumScrollThreshY", 12,
                "DynamicEWMode", ">y",
            },
            "Keyboard", Package()
            {
                "ActionSwipeDown","37 d, 2e d, 2e u, 37 u",//3FingersDown=Minimize app
                "ActionSwipeLeft","37 d, 21 d, 21 u, 37 u", //3FingersLeft=Backward
                "ActionSwipeRight","37 d, 1e d, 1e u, 37 u",//3FingersRight=Forward
                "ActionSwipeUp","3b d, 7e d, 7e u, 3b u",//3FingersUp=Mission control
                
                "Breakless PS2", Package()
                {
                    Package(){}, 
                },
                "MaximumMacroTime", 25000000,
                "Custom ADB Map", Package()
                {
                    Package(){},
                 },
                "Custom PS2 Map", Package()
                {
                    Package(){},
                    "1d=38", // 1d is PS2 for left control,38 is PS2 for left alt
                    "38=1d", // ctrl=Windows ctrl,alt=Windows alt
                    "e01d=e038", //e01d is PS2 for right control,e038 is PS2 for right alt
                    "e038=e01d", // ctrl=Windows ctrl,alt=Windows alt
                    "e037=64", // PrtSc=F13,via SysPrefs->Keyboard->Shortcuts
                },
                "Function Keys Special", Package()
                {
                    Package(){},
                    // The following 12 items map Fn+fkeys to Fn+fkeys
                    // The following 12 items map fkeys to fkeys
                     "3b=e05f",//F1=System Sleep
                     "3c=e05e",//F2=System Power / Keyboard Power
                     "3d=e005",//F3=brightness down
                     "3e=e006",//F4=brightness up
                     "3f=e02e",//F5=Volume Down
                     "40=e030",//F6=Volume Up
                     "41=e010",//F7=Scan Previous Track
                     "42=e022",//F8=Play/Pause
                     "43=e019",//F9=Scan Next Track
                     "44=e020",//F10=Mute
                },
                "Function Keys Standard", Package()
                {
                    Package(){},
                },
            },
        })
    }

    External (_SB.PCI0.LPCB.EC0, DeviceObj)    // (from opcode)
    External (_SB.PCI0.LPCB.PS2K, DeviceObj)    // (from opcode)
  

    Scope (_SB.PCI0.LPCB.EC0)
    {
        // _Q11 called on brightness down key
        Method (_Q11, 0, NotSerialized)  // _Qxx: EC Query
        {
            Notify (\_SB.PCI0.LPCB.PS2K, 0x20) // ELAN
            Notify (\_SB.PCI0.LPCB.PS2K, 0x0405) // Synaptics/ALPS
            Notify (\_SB.PCI0.LPCB.PS2K, 0x0205)
            Notify (\_SB.PCI0.LPCB.PS2K, 0x0285)
        }

        // _Q12 called on brightness up key
        Method (_Q12, 0, NotSerialized)  // _Qxx: EC Query
        {
            Notify (\_SB.PCI0.LPCB.PS2K, 0x10) // ELAN
            Notify (\_SB.PCI0.LPCB.PS2K, 0x0406) // Synaptics/ALPS
            Notify (\_SB.PCI0.LPCB.PS2K, 0x0206)
            Notify (\_SB.PCI0.LPCB.PS2K, 0x0286)
        }
   }


// Battery Status
//

    // Override for ACPIBatteryManager.kext
    
    External(_SB.BAT1, DeviceObj)
    Name(_SB.BAT1.RMCF, Package()
    {
        "StartupDelay", 10,
    })

    External (_SB.PCI0.LPCB.ECOK, MethodObj)
    External (_SB.PCI0.LPCB.EC0.ENDD, FieldUnitObj)
    External (_TZ.THLD, UnknownObj)
    External (_TZ.TZ00.PTMP, UnknownObj)
    // TMP is renamed to XTMP
    // calls to them will land here
    Scope (_TZ)
    {
        Method (_TMP, 0, Serialized)// _TMP: Temperature
        {
            If (\_SB.PCI0.LPCB.ECOK ())
            {
                Store (Zero, \_SB.PCI0.LPCB.EC0.ENI0)
                Store (0x84, \_SB.PCI0.LPCB.EC0.ENI1)
                Store (\_SB.PCI0.LPCB.EC0.ENDD, Local0)
            }
            Else
            {
                Store (\_TZ.TZ00.PTMP, Local0)
            }

            If (LGreaterEqual (Local0, THLD))
            {
                Return (\_TZ.TZ00.PTMP)
            }
            Else
            {
                Add (0x0AAC, Multiply (Local0, 0x0A), Local0)
                Store (Local0, \_TZ.TZ00.PTMP)
                Return (Local0)
            }
        }
    }
    
    External(_SB.PCI0.LPCB.EC0, DeviceObj)
    Scope (_SB.PCI0.LPCB.EC0)
    {
        // This is an override for battery methods that access EC fields
        // larger than 8-bit.

        OperationRegion (AMER, EmbeddedControl, Zero, 0xFF)
        Field (AMER, ByteAcc, Lock, Preserve)
        {
            Offset (0x5A), 
            Offset (0x5B), 
            Offset (0x5C), 
            Offset (0x5D), 
            ENI0,   8, 
            ENI1,   8
        }
        
        OperationRegion (RMEC, EmbeddedControl, Zero, 0xFF)
        Field (RMEC, ByteAcc, Lock, Preserve)
        {
            Offset (0x5D), 
            ERI0,   8, 
            ERI1,   8
        }

        External(FAMX, MutexObj)
        External (ERBD, FieldUnitObj)
        
        // FANG and FANW are renamed to XANG and XANW
        // calls to them will land here
        Method (FANG, 1, NotSerialized)
        {
            Acquire (FAMX, 0xFFFF)
            Store (Arg0, ERI0)
            Store (ShiftRight (Arg0, 0x08), ERI1)
            Store (ERBD, Local0)
            Release (FAMX)
            Return (Local0)
        }

        Method (FANW, 2, NotSerialized)
        {
            Acquire (FAMX, 0xFFFF)
            Store (Arg0, ERI0)
            Store (ShiftRight (Arg0, 0x08), ERI1)
            Store (Arg1, ERBD)
            Release (FAMX)
            Return (Arg1)
        }
    }
}
//EOF
