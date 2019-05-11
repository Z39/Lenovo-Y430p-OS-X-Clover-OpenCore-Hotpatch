# Lenovo IdeaPad Y430P NoteBook for macOS Mojave & High Sierra

Hackintosh your Y430P Notebook

[English](README-EN.md) | [中文](README.md)

* Computer：Lenovo IdeaPad Y430P Laptop     
* CPU ：Intel Core i5-4210M@ 2.60G/Intel Haswell Core i7-4710MQ @ 2.50G (Haswell)
* Chipset ：Lenovo (Intel HM86 Chipset)                                                                           
* Graphics：HD4600 (using Intel GPU only)                                                                     
* Audio：ALC282 @ Intel Lynx Point High Definition Audio 
* Ethernet：Atheros QCA8171 Gigabit Ethernet     
* WiFi ：Broadcom BCM94352HMB 802.11AC(after replacing the original card)    
* Bluetooth：BCM20702 (4.0) (after replacing the original card)                
* BIOS Version：3.66      

## Features

* Support 10.13.x and 10.14.x
* ACPI fixes use hotpatch; related files are located in `/CLOVER/ACPI/patched`.## Releases

## Releases
The latest version can be downloaded on the[release page](https://github.com/Z39/Y430p-OS-X-Clover-Hotpatch/releases) 



## What Works
* Graphics with full acceleration QE/CI (using Intel GPU only) + HDMI Video
* Audio using AppleALC or VoodooHDA.kext(if you use VoodooHDA,pls remember let your Laptop sleep once and then wake it,HDMI sound output will work properly)
* Ethernet (LAN)
* WiFi / Bluetooth (after replacing the Intel card (incompatible) with a compatible one like Broadcom BCM4352 for example
* Sleep (also sleep on Lid Close)
* Brightness,Support use FN+Arrows﻿
* Battery
* Keyboard / Touchpad
* CPU Power Management
* Web-Cam
* All USB ports
* App Store/iCloud/iMessage/Facetime
* TRIM
* SIP (0ff)


## Problems
* VGA Port:This will not work at all. A workaround when projecting to VGA display is to buy and use (male)HDMI-to-(fem﻿ale)VGA adapter. 
* Nvidia GPU (built-in): This will have to be disabled as OS X does not support Optimus technology.
* Audio:There is a problem of pop when boot the notebook

## Links

- Clover EFI bootloader [Link](https://github.com/Dids/clover-builder/releases)

- FakeSMC [Link](https://bitbucket.org/RehabMan/os-x-fakesmc-kozlek/downloads/)

- VoodooPS2Controller [Link](https://bitbucket.org/RehabMan/os-x-acpi-battery-driver/)

- ACPIBatteryManager [Link](https://bitbucket.org/RehabMan/os-x-acpi-battery-driver/)

- BrcmPatchRAM [Link](https://bitbucket.org/RehabMan/os-x-brcmpatchram/downloads/)

- Lilu [Link](https://github.com/acidanthera/Lilu)

- AirportBrcmFixup [Link](https://github.com/acidanthera/AirportBrcmFixup)

- WhateverGreen [Link](https://github.com/acidanthera/WhateverGreen)

- AppleALC [Link](https://github.com/acidanthera/AppleALC)

- AtherosE2200Ethernet [Link](https://github.com/Mieze/AtherosE2200Ethernet)

- Enable macOS HiDPI [Link](https://github.com/xzhih/one-key-hidpi)

## Credits

- Thanks to RehabMan、intruder16、panybbib、ahmed_ais

