
// Automatic injection of EH02 properties
// Not needed since we disabled EH02

DefinitionBlock("", "SSDT", 2, "Y430P", "EH02", 0)
{
    // inject properties for EH02
    
    External(_SB.PCI0.EH02, DeviceObj)
    
    If (CondRefOf(_SB.PCI0.EH02))
    {
        Method(_SB.PCI0.EH02._DSM, 4)
        {
            If (!Arg2) { Return (Buffer() { 0x03 } ) }
            Return (Package()
            {
                "subsystem-id", Buffer() { 0x70, 0x72, 0x00, 0x00 },
                "subsystem-vendor-id", Buffer() { 0x86, 0x80, 0x00, 0x00 },
                "AAPL,current-available", Buffer() { 0x34, 0x08, 0, 0 },
                "AAPL,current-extra", Buffer() { 0x98, 0x08, 0, 0, },
                "AAPL,current-extra-in-sleep", Buffer() { 0x40, 0x06, 0, 0, },
                "AAPL,max-port-current-in-sleep", Buffer() { 0x34, 0x08, 0, 0 },
            })
        }
    }
}

// EOF
