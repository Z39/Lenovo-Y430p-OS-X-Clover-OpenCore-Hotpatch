
// USBInjectAll configuration/override

DefinitionBlock ("", "SSDT", 2, "Y430p", "UIAC-ALL", 0)
{
    Device(UIAC)
    {
        Name(_HID, "UIA00000")

        Name(RMCF, Package()
        {
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
                    "HS02", Package()    // USB 2.0 right
                    {
                        "UsbConnector", 0,
                        "port", Buffer() { 0x02, 0, 0, 0 },
                    },
                    "HS03", Package()    // HS component of USB 3.0 near left
                    {
                        "UsbConnector", 3,
                        "port", Buffer() { 0x03, 0, 0, 0 },
                    },
                    "HS07", Package()    // Bluetooth 
                    {
                        "UsbConnector", 255,
                        "port", Buffer() { 0x07, 0, 0, 0 },
                    },
                    "HS10", Package()    // HS component of USB 2.0 far left
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
                        "port", Buffer() { 0x13, 0, 0, 0 }
                    }
                }
            }
        })
    }
    
    // Disabling EHCI #1 (and EHCI #2)
    External(_SB.PCI0.EH01, DeviceObj)
    External(_SB.PCI0.EH02, DeviceObj)
    External(_SB.PCI0.LPCB, DeviceObj)

    // registers needed for disabling EHC#1
    Scope(_SB.PCI0.EH01)
    {
        OperationRegion(RMP1, PCI_Config, 0x54, 2)
        Field(RMP1, WordAcc, NoLock, Preserve)
        {
            PSTE, 2  // bits 2:0 are power state
        }
    }
    
    // registers needed for disabling EHC#1
    Scope(_SB.PCI0.EH02)
    {
        OperationRegion(RMP1, PCI_Config, 0x54, 2)
        Field(RMP1, WordAcc, NoLock, Preserve)
        {
            PSTE, 2  // bits 2:0 are power state
        }
    }
    
    Scope(_SB.PCI0.LPCB)
    {
        OperationRegion(RMP1, PCI_Config, 0xF0, 4)
        Field(RMP1, DWordAcc, NoLock, Preserve)
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
    
    Device(_SB.PCI0.RMD2)
    {
        Name(_HID, "RMD20000")
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

// EOF