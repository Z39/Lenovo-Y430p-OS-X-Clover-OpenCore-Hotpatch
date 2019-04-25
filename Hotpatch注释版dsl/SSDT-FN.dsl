
// Replace Q11 & Q12 key functions for brightness
// Keyboard/Trackpad
DefinitionBlock ("", "SSDT", 2, "Y430P", "FN", 0x00000000)
{
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
       // Select specific keyboard map in VoodooPS2Keyboard.kext
        Scope (\_SB.PCI0.LPCB.PS2K)
        {
            Method (_DSM, 4, NotSerialized)  // _DSM: Device-Specific Method
            {
                If (LNot (Arg2))
                {
                    Return (Buffer ()
                    {
                         0x03                                           
                    })
                }

                Return (Package ()
                {
                    "RM,oem-id", 
                    "LENOVO", 
                    "RM,oem-table-id", 
                    "Haswell-Ideapad"
                })
            }

            Name (RMCF, Package ()
            {
                "Controller", 
                Package ()
                {
                    "WakeDelay", 
                    Zero
                }, 

                "Sentelic FSP", 
                Package ()
                {
                    "DisableDevice", 
                    ">y"
                }, 

                "ALPS GlidePoint", 
                Package ()
                {
                    "DisableDevice", 
                    ">y"
                }, 

                "Synaptics TouchPad", 
                Package ()
                {
                    "MultiFingerVerticalDivisor", 
                    0x09, 
                    "MultiFingerHorizontalDivisor", 
                    0x09, 
                    "MomentumScrollThreshY", 
                    0x0C, 
                    "DynamicEWMode", 
                    ">y",
                    
                }, 

                "Keyboard", 
                Package ()
                {
                    
                    "ActionSwipeDown","37 d, 2e d, 2e u, 37 u",//3FingersDown=Minimize app
                    "ActionSwipeLeft","37 d, 21 d, 21 u, 37 u", //3FingersLeft=Backward
                    "ActionSwipeRight","37 d, 1e d, 1e u, 37 u",//3FingersRight=Forward
                    "ActionSwipeUp","3b d, 7e d, 7e u, 3b u",//3FingersUp=Mission control
                                        
                    "Breakless PS2", 
                    Package ()
                    {
                        Package (){}
                    }, 

                    "Custom ADB Map", 
                    Package ()
                    {
                        Package (){}, 
                                     
                    }, 

                    "Custom PS2 Map", 
                    Package ()
                    {
                        Package (){}, 
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
                    // The following 12 items map Fn+fkeys to fkeys
                        
                    // The following 12 items map fkeys to Fn+fkeys
                        
 
                    
                 }
            },
        })
    }
  }
}

// EOF