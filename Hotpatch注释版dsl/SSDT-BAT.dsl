
// Battery Fixes

DefinitionBlock("", "SSDT", 2, "Y430P", "BAT", 0)
{
    // Override for ACPIBatteryManager.kext
    
    External(_SB_.BAT1, DeviceObj)
    Name(_SB.BAT1.RMCF, Package()
    {
        "StartupDelay", 10,
    })

    External (_SB.PCI0.LPCB.ECOK, MethodObj)
    External (_SB.PCI0.LPCB.EC0.ENDD, FieldUnitObj)
    External (_TZ.THLD, UnknownObj)
    External (_TZ.TZ00.PTMP, UnknownObj)
    
    Scope (_TZ)
    {
        Method (_TMP, 0, Serialized)  // _TMP: Temperature
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
    External (FAMX, MutexObj)
    External (ERBD, FieldUnitObj)
    
    Scope (_SB.PCI0.LPCB.EC0)
    {
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

// EOF
