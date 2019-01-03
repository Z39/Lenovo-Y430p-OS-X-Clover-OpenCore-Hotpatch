# Lenovo IdeaPad Y430P NoteBook for macOS Mojave & High Sierra

Hackintosh your Y430P Notebook

[English](README.md) | [中文](README-CN.md)

## Features

* Support 10.13.x and 10.14.x
* ACPI fixes use hotpatch; related files are located in `/CLOVER/ACPI/patched`.

## What Works
* Graphics with full acceleration QE/CI (using Intel GPU only) + HDMI Video
* Audio using AppleALC
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


## Credits

- Thanks to RehabMan、intruder16、panybbib、ahmed_ais

