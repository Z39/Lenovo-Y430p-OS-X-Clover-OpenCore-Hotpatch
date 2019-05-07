# 联想Y430P安装macOS Mojave & High Sierra 使用说明

让你的Y430P笔记本吃上黑苹果

[English](README-EN.md) | [中文](README.md)


* Computer：Lenovo IdeaPad Y430P Laptop     
* CPU ：Intel Core i5-4210M@ 2.60G/Intel Haswell Core i7-4710MQ @ 2.50G (Haswell)
* Chipset ：Lenovo (Intel HM86 Chipset)                                                                           
* Graphics：HD4600 (using Intel GPU only)                                                                     
* Audio：ALC282 @ Intel Lynx Point High Definition Audio 
* Ethernet：Atheros QCA8171 Gigabit Ethernet     
* WiFi ：Broadcom BCM94352HMB 802.11AC (原装无解，更换)      
* Bluetooth：BCM20702 (4.0)  (原装无解，更换)              
* BIOS Version：3.66                   

## 支持列表

* 支持10.13.x 和 10.14。
* ACPI补丁修复使用hotpatch方式，相关文件位于 `/CLOVER/ACPI/patched` 。
* 远景论坛ID：39军小兵张 [Link](http://i.pcbeta.com/space-uid-4472739.html)
* 安装视频教程及效果展示：[Link](https://space.bilibili.com/414418614/video)
* 有问题可加QQ群：686848381 验证答案：ALC282

## 发布

最后发布的版本前往 [release page](https://github.com/Z39/Y430p-OS-X-Clover-Hotpatch/releases) 下载即可。
如果Github网络下载不太好，新增[蓝奏云](https://www.lanzous.com/b616223/#8shm) 
## 关于打赏

如果您认可我的工作，请通过打赏支持我后续的更新

|                                 微信                                           |                         支付宝                                       |
| ---------------------------------------------------------- | ---------------------------------------------------- |
| ![微信打赏](微信打赏.png)                                         | ![支付宝打赏](支付宝打赏.png)                           |

### 显卡
* 屏蔽独显，HD4600正常，QE/CI OK,有水波纹效果，AGPM（显卡变频）正常,修复HD4600开机第二阶段花屏、开机后鼠标卡顿、播放视频卡死机等显卡问题。PS:小Y存在高低分屏的区别，高分屏容易花屏，最好注入自己的EDID。

### USB
* USB端口定制，所有usb端口跟win一样显示在usb3.0总线上，USB 3.0可用，外接HUB/键鼠可用并正确识别。

### 亮度调节
* （小太阳ok，能保存亮度）（配合VoodooPS2Controller或ApplePS2SmartTouchPad FN+上下箭头键调节）采用R大新方法：SSDT-PNLF.aml配合AppleBacklightFixup.kext调节亮度表，新WhateverGreen.kext已经有AppleBacklightFixup.kext的功能，故可不需要AppleBacklightFixup.kext。

### 声卡
* 根据小Y codec信息制作的ALC282仿冒声卡（Clover已默认放入AppleALC方法驱动，不再需要其他操作，Clover会自动驱动声卡），音质不错无杂音，扬声器耳机等正常有声，插拔自动切换正常，内外置麦克风ok，睡眠唤醒后有声音，缺点嘛就是开机进度条时有些正常爆音。另外，HD4600外接HDMI声音输出已开启。ps:已提交官方applealc,Y410P注入ID为41，Y430P为43，Y510P为51,是不是很好记，当然这个注入ID不用管，附件已默认注入。

### CPU
* 完美变频，一般8个变频档位。

### 电源睡眠唤醒
* （电源管理LPC ok，电池已修正能显示并更新剩余电量，睡眠唤醒正常并支持USB鼠标唤醒，关机重启正常断电）

### 键盘
* VoodooPS2Controller或ApplePS2SmartTouchPad输入正常，附件默认使用ApplePS2SmartTouchPad，兼容Synaptics和Elan。
* VoodooPS2Controller默认注入调换control和command键，符合windows ctrl快键键使用习惯。请仔细确认自己的键控类型，Synaptics触控版的可使用VoodooPS2Controller.kext或者ApplePS2SmartTouchPad.kext。Elan触控版可使用ApplePS2SmartTouchPad.kext或者ApplePS2ElanTouchpad.kext。只能使用一个键控kext驱动，不要混用,否则驱动冲突会导致键盘失灵。clover默认放入VoodooPS2Controller.kext，Elan触控版的请删除并放入附件中提供的对应kext。
* 已更新自定义FN快捷键和触控板手势

### 触控板
*手势嘛，实测支持三指，当然是没白苹果那么厉害，（在键盘-快捷键中找到想要实现的功能，在修改快捷键时直接三指滑动你想要的方向就可以了。比如我们要模拟白苹果的三指向上扫调出调度中心）。键控类型同上一条。
* 已更新自定义FN快捷键和触控板手势

### 有线网卡
* OK

### 无线网卡
* 原BCM43142无解，更换为BCM94352HMB，5G OK，隔空投送OK，隔空播放OK,10.14新加入从iPhone或iPad导入可用，HandOff能用但不稳定。小Y白名单中有BCM94352，如换其他无线网卡，需要刷BIOS白名单，群文件有刷修改BIOS教程。换USB wifi的请自行解决驱动。

### 蓝牙
* 蓝牙（ok）蓝牙设备能用


### 摄像头
* ok

### App Store/iCloud/iMessage/Facetime
* 添加了白果三码洗白，ok


### SIP
* 关闭SIP,CsrActiveConfig值注入0x3ff，可进FireWolf OS X MAC PE

### TRIM
* 固态硬盘默认开启TRIM

### 无痛更新升级
* macOS系统无痛更新升级，支持白果一样在线商店系统更新，支持跨大版本升级

### 读卡器
* 读卡器 插Card Reader(相机之类的那种卡) OK

### 关于背光
* 小Y的背光键盘直接能用

### 外接显示器
* 显示器HDMI外接可用，VGA不支持。HDMI视频输出OK，HDMI声音输出OK。ps:4K，HD4600外接好像带不太动。

### 独显
* 默认HD4600+GT755M屏蔽独显，尽管苹果早已出了装备GT755M的imac,但至今GT755M黑苹果好像也没什么好消息。另外加了SLI GT755M的朋友请自行解决（好像外网有两块GT755M能识别SLI GT755M的）

### 光驱
* 光驱位早已改装硬盘，不过据景友反映光驱OK，刻录功能自测。

### 存在问题
* 1.声卡表现不完美，按照教程根据codec正确节点仿冒，开机进度条有爆音，该问题目前已确认只存在于Y410P/Y430P，Y510P的正常。
* 2.关于重启不断电问题，已确认存在Y410P/Y510P,Y430P无问题。Y410P/Y510P使用最新附件，BIOS设置Boot uefi only模式可解决重启不断电问题，但会有开机一闪花屏的问题和睡眠唤醒后再使用重启的话依然重启不断电。具体请看附件内附说明。

## kexts等更新链接

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
## 更新日志

详细更新日志请看 [更新日志中文版](Changelog_CN.md)。
## 鸣谢
感谢intruder16、panybbib等大神


