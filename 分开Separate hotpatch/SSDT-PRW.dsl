
// For solving instant wake by hooking GPRW or XPRW
// support wake by usb

DefinitionBlock("", "SSDT", 2, "Y430P", "PRW", 0)
{
    External (XPRW, MethodObj)

    Method (GPRW, 2, NotSerialized)
    {
        If (0x6d == Arg0){If (0x04 == Arg1){Return (XPRW (0x09, Arg1))}}
        If (0x0d == Arg0){If (0x04 == Arg1){Return (XPRW (0x09, Arg1))}}
        Return (XPRW (Arg0, Arg1))
    }
}

//EOF
