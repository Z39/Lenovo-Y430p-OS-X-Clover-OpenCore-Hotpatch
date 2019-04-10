
// Automatic injection of IGPU properties

DefinitionBlock("", "SSDT", 2, "Y430P", "IGPU", 0)
{
    External(_SB.PCI0.IGPU, DeviceObj)

    Scope(_SB.PCI0.IGPU)
    {
        Method(_DSM, 4)
        {
            If (!Arg2) { Return (Buffer() { 0x03 } ) }
            Return (Package ()
            {
                "AAPL,slot-name", Buffer (){ "Graphics"},
                "name", Buffer (){ "Intel HD 4600"},
                "model", Buffer() { "Intel HD Graphics 4600" },                "hda-gfx", Buffer() { "onboard-1" },
                "AAPL00,DualLink", Buffer () { 0x01, 0x00, 0x00, 0x00 },                 "framebuffer-stolenmem", Buffer() { 0x00, 0x00, 0x30, 0x01 },                "framebuffer-portcount", Buffer() { 0x02, 0x00, 0x00, 0x00 },                "device-id", Buffer() { 0x12, 0x04, 0x00, 0x00 },                "disable-external-gpu", Buffer() { 0x01, 0x00, 0x00, 0x00 },                "framebuffer-con2-type", Buffer() { 0x00, 0x08, 0x00, 0x00 },                "framebuffer-fbmem", Buffer() { 0x00, 0x00, 0x90, 0x00 },                "framebuffer-patch-enable", Buffer() { 0x01, 0x00, 0x00, 0x00 },                "enable-hdmi20", Buffer() { 0x01, 0x00, 0x00, 0x00 },                "framebuffer-con1-type", Buffer() { 0x00, 0x08, 0x00, 0x00 },                "AAPL,ig-platform-id", Buffer() { 0x06, 0x00, 0x26, 0x0A },                "framebuffer-con2-index", Buffer() { 0xFF, 0xFF, 0xFF, 0xFF },                "framebuffer-con2-enable", Buffer() { 0x01, 0x00, 0x00, 0x00 },                "framebuffer-con1-enable", Buffer() { 0x01, 0x00, 0x00, 0x00 },                "framebuffer-unifiedmem", Buffer() { 0x00, 0x00, 0x00, 0x80 },
            })
        }
    }
}
//EOF
