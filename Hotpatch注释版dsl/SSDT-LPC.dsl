
// Fix unsupported 8-series LPC devices
// list of 8-series LPC device-ids not natively supported 0x8c46 0x8c49 0x8c4a 0x8c4c 0x8c4e 0x8c4f 0x8c50 0x8c52 0x8c54 0x8c56 0x8c5c 0x8cc3
// inject 0x8c4b for unsupported LPC device-id

DefinitionBlock("", "SSDT", 2, "Y430P", "LPC", 0)
{
    External(_SB.PCI0.LPCB, DeviceObj)

    Scope(_SB.PCI0.LPCB)
    {
        Method (_DSM, 4, NotSerialized)
        {
            If (!Arg2) { Return (Buffer() { 0x03 } ) }
            Return (Package () 
            { 
                "compatible", "pci8086,8c4b",
                "AAPL,slot-name", "Built In",
                "device_type", Buffer () {"LPC Controller"},
                "name", Buffer () {"Intel HM86 Chipset - LPC Interface Controller"},
                "model", Buffer () {"Intel HM86 Chipset - LPC Interface Controller"}
            })
        }
    }
}

// EOF
