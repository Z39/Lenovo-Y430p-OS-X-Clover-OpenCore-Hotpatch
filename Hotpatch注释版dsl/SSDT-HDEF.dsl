
// Automatic injection of HDEF properties

DefinitionBlock("", "SSDT", 2, "Y430P", "HDEF", 0)
{
    External(_SB.PCI0.HDEF, DeviceObj)
    
    Method(_SB.PCI0.HDEF._DSM, 4)
    {
        If (!Arg2) { Return (Buffer() { 0x03 } ) }
        Return(Package()
        {
            "AAPL,slot-name", "Built In", 
            "name", Buffer () {"Realtek ALC282 Audio Controller"},
            "model", Buffer () {"Realtek ALC282 Audio Controller"},
            "layout-id", Buffer() { 41, 0, 0, 0 },
            "hda-gfx", Buffer() { "onboard-1" },
            "PinConfigurations", Buffer() { },
        })
   }
}

// EOF
