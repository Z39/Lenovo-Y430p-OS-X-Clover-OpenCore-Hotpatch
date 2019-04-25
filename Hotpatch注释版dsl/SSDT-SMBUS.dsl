
// Adding SMBUS device

DefinitionBlock("", "SSDT", 2, "Y430p", "SMBUS", 0)
{
    External(_SB.PCI0, DeviceObj)
    
    Scope(_SB.PCI0)
    {
        Device(SBUS.BUS0)
        {
            Name(_CID, "smbus")
            Name(_ADR, Zero)
            Device(DVL0)
            {
                Name(_ADR, 0x57)
                Name(_CID, "diagsvault")
                Method(_DSM, 4)
                {
                    If (!Arg2) { Return (Buffer() { 0x03 } ) }
                    Return (Package() { "address", 0x57 })
                }
            }
        }
    }
}
//EOF
