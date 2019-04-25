
// Add the missing IMEI device

DefinitionBlock("", "SSDT", 2, "Y430p", "IMEI", 0)
{
    External(_SB.PCI0, DeviceObj)

    Scope (_SB.PCI0)
    {
        Device (IMEI)
        {
            Name (_ADR, 0x00160000)  // _ADR: Address
        }
    }
}
//EOF
