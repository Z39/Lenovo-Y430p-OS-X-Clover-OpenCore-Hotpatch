
// add BCM94352HMB

DefinitionBlock ("", "SSDT", 2, "Y430P", "WIFI", 0x00003000)
{

    
    External (_SB.PCI0.RP05.PXSX, DeviceObj)    // (from opcode)
   
    Scope (_SB.PCI0.RP05.PXSX)
    {         
        Device (ARPT)
        {Name (_ADR, Zero)  // _ADR: Address
         Name (_PRW, Package ()  // _PRW: Power Resources for Wake
         {0x09, 0x04})
          Method (_DSM, 4, NotSerialized)  // _DSM: Device-Specific Method
          {
            If (!Arg2) { Return (Buffer() { 0x03 } ) }
            Return (Package ()
            {
                "compatible","pci14e4,43a0",
            })
          }
       }    
    }
    
   }

//EOF