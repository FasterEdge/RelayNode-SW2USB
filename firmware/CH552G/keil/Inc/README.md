# CH552G Keil 说明

本目录提供 CH552G SOP-16 的 Keil C51 入口代码。`User/main.c` 使用 WCH CH55x SDK 的系统和 USB 初始化接口；USB HID 描述符、端点配置和 `usb_hid_send_report()` 由 WCH CH55x USB Device/HID library 提供。

由于 WCH SDK 头文件、启动文件和 USB 描述符属于工具链/SDK 内容，未将第三方 SDK 二进制或库文件复制进仓库。请在 Keil 工程中加入对应 CH552/CH554 SDK 的 `CH552.H`、启动文件、USB Device 基础文件和 HID 类文件。

四路输入映射：P1.1/P1.2/P1.3/P1.4，分别对应 SW1/SW2/SW3/SW4；输入低电平表示开关闭合。HID 报告 ID 为 1，数据长度 1 字节，bit0..bit3 对应 SW1..SW4。
