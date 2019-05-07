# 更新日志

[中文](Changelog_CN.md)

* 2019-05-01

* 1.无啥重要更新，主要是更新了一下clover版本和一些efi
* 2.调整了一些hotpatch补丁
* 3.更好地兼容10.14.4和10.14.5beta（这个好像是，哈哈）
* 4.XOSI,win版本更新至1903


* 2019-04-04

* 1.主要是自定义了小Y的FN快捷键功能和手势，具体见附件中的相关说明。
* 2.默认附件使用ApplePS2SmartTouchPad.kext，兼容Synaptics与elan，自定义修改在ApplePS2SmartTouchPad.kext包内
* 3.VoodooPS2Controller的话，所有修改在SSDT-FN.aml，hotpatch方式给VoodooPS2Controller.kext作自定义。
* 4.总结：使用以前旧版附件的，可直接替换新的修改版本的ApplePS2SmartTouchPad.kext，如使用原来修改版的VoodooPS2Controller.kext，需替换SSDT-FN.aml和官方VoodooPS2Controller.kext
* 5.所有修改调度只在本机Y410P，Synaptics上，具体效果功能自测
* 6.kext更新了AppleALC.kext至1.3.7，WhateverGreen.kext至1.2.8
* PS:第一次用这个release功能，好控制一下版本
* 说明一下：
* A.默认键控驱动使用ApplePS2SmartTouchPad.kext，兼容Synaptics与elan。另外Synaptics的有可换VoodooPS2Controller，两个不能共用。
* B.内有94352wifi和蓝牙驱动，AR9485和小米USB的可下载源代码中的附件。
* C.仓库里的有许多说明，新手请看一些必要的问题和注意说明。



