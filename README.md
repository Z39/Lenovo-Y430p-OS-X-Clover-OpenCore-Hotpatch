# 联想Y430P安装macOS Catalina 10.15& macOS Mojave 10.14& High Sierra 10.13 使用说明

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
 ![截图](Screen.JPG)   
## 支持列表

* 支持macOS Catalina 10.15& macOS Mojave 10.14& High Sierra 10.13
* ACPI补丁修复使用hotpatch方式，相关文件位于 `/CLOVER/ACPI/patched` 。
* 远景论坛ID：39军小兵张 [Link](http://i.pcbeta.com/space-uid-4472739.html)
* 安装视频教程及效果展示：[Link](https://space.bilibili.com/414418614/video)
* 长期维护更新QQ群：686848381 群已改为打赏群了，打赏入群5-10元吧。如果需要远程技术指导安装，30以上你看着给吧，不过我建议大家自己看我详细的新手安装文档，自己实操就更好了。

## 发布

最后发布的版本前往 [release page](https://github.com/Z39/Y430p-OS-X-Clover-Hotpatch/releases) 下载即可。
如果Github网络下载不太好，新增[蓝奏云](https://www.lanzous.com/b616223)  密码：8shm
## 关于打赏

如果您认可我的工作，请通过打赏支持我后续的更新(自觉打赏的人真少啊，免费的东西长久不了,现已改为需要密码解压，需微信或支付宝打赏入群。打赏记得留言备注你的qq号，然后申请入群时，填写你的留言为验证答案就是，我确认后会通过你的验证的。PS:之所以设置打赏，并不是为了赚大钱，当然大家打赏的多是有一些零花钱。主要是维护更新不易，每次系统一更新，有问题的话，就要工作时间之外花时间去调试，解决问题。普通群最多500人，无门槛的入群，不够用，有些机友对无门槛进入还不珍惜，进退群很随意，不看相关说明，上来就问问题的又多。不多说了，理解不理解的，就这样吧。

|                                 微信                                           |                         支付宝                                       |
| ---------------------------------------------------------- | ---------------------------------------------------- |
| ![微信打赏](微信打赏.png)                                         | ![支付宝打赏](支付宝打赏.png)                           |

|              大Y大G QQ群1（已满500勿加）                |             大Y大G QQ群2                                     |
| ----------------------------------------------------------| ---------------------------------------------------- |
| ![686848381](大Y大G群1.png)                                 | ![758104687](大Y大G群2.png)                          | 


## 黑苹果相关情况
- [x] 显卡 核显HD4600驱动 QE/CI AGPM
- [x]  USB 3.0 USB端口定制 
- [x]  亮度调节 FN+上下箭头调节
- [x]  声卡 定制无爆音版VoodooHDA万能声卡驱动
- [x]  CPU变频  
- [x]  电源电池睡眠唤醒（电源管理LPC ok，电池已修正能显示并更新剩余电量，开合盖唤醒/睡眠，关机重启正常断电）
- [x]  键盘 附件默认使用ApplePS2SmartTouchPad，兼容Synaptics和Elan，已更新自定义FN快捷键，看FN快捷键和手势说明
- [x]  触控板 自定义手势,看FN快捷键和手势说明
- [x] 有线网卡
- [x]  无线网卡 自带BCM43142无解需要更换，更换BCM94352HMB
- [x]  蓝牙 需要更换
- [x]  摄像头
- [x]  App Store/iCloud/iMessage/Facetime
- [x]  SIP 关闭SIP
- [x]  TRIM 固态默认开启
- [x]  无痛更新升级 支持在线升级
- [x]  读卡器
- [x] 外接显示器 HDMI视频/声音输出,VGA不支持
- [x] 自带独显屏蔽，光驱位加装独显的，如GT755M无解的，安装时需要拔除，如免驱的RX570的，可驱动使用。
- [x] 背光键盘直接能用
- [x] 光驱位早已改装硬盘，不过据景友反映光驱OK，刻录功能自测。

### 存在问题
* 1.声卡表现不完美，按照教程根据codec正确节点仿冒，开机进度条有爆音，该问题目前已确认只存在于Y410P/Y430P，Y510P的正常。目前已默认放入无爆音版万能声卡解决。
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

## 鸣谢
感谢intruder16、panybbib等大神


