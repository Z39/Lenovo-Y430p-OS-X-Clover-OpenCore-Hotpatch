
// Override for host defined _OSI to handle "Darwin"...

DefinitionBlock("", "SSDT", 2, "Y430P", "XOSI", 0)
{
    // All _OSI calls in DSDT are routed to XOSI...
    // XOSI simulates "Windows 2012" (which is Windows 8)
    // Note: According to ACPI spec, _OSI("Windows") must also return true
    //  Also, it should return true for all previous versions of Windows.
    Method(XOSI, 1)
    {
        Store(Package()
        {
            "Windows",              // generic Windows query
            "Windows 2009",         // Windows 7/Windows Server 2008 R2
            "Windows 2012",         // Windows 8/Windows Server 2012
            "Windows 2013",         // Windows 8.1/Windows Server 2012 R2
            "Windows 2015",         // Windows 10/Windows Server TP
            "Windows 2016",         // Windows 10, version 1607
            "Windows 2017",         // Windows 10, version 1703
            "Windows 2017.2",       // Windows 10, version 1709
            "Windows 2018",         // Windows 10, version 1803
            "Windows 2018.2",       // Windows 10, version 1809

        }, Local0)
        Return (Ones != Match(Local0, MEQ, Arg0, MTR, 0, 0))
    }
}

// EOF
