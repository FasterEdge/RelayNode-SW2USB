<div align="center">
<img src="https://avatars.githubusercontent.com/u/245985800?s=200&v=4" style="width:100px;" width="100"/>
<h2>RelayNode - SW2USB</h2>
<h3>串口转 USB 继电器节点（嘉立创 EDA 专业版硬件工程）</h3>
</div>

### 一、简介

**RelayNode-SW2USB** 是 FasterEdge 生态的硬件节点：以 **PY32F003** 为控制核心的**串口转 USB 继电器控制板**。硬件工程使用**嘉立创 EDA 专业版**（.eprj2）绘制，可与 [MCU-PY32F003](https://github.com/FasterEdge/MCU-PY32F003) 固件配合，作为 FasterEdge Modbus/OneKey 能力的执行末端。

- ✅ 嘉立创 EDA 专业版工程（`sw2usb_main.eprj2`），单文件可打开
- ✅ 主控 **PY32F003**（Cortex-M0+，FasterEdge MCU 平台之一）
- ✅ 继电器输出 + 串口/USB 控制通路
- ✅ BOM 精简（单芯片方案）

### 二、目录结构

```
RelayNode-SW2USB/
├── sw2usb_main.eprj2           # 嘉立创 EDA 专业版工程文件（原理图+PCB）
├── sw2usb_main_backup/         # EDA 自动备份（.epro2 快照）
├── hardware/                   # 硬件相关导出/备份
├── software/                   # 固件占位（固件见 MCU-PY32F003）
├── BOM.txt                     # 元器件清单
├── LICENSE                     # Apache-2.0
└── README.md
```

### 三、使用说明

1. 下载安装**嘉立创 EDA 专业版**（立创EDA专业版）
2. 打开 `sw2usb_main.eprj2` 工程（原理图 / PCB 均已绘制）
3. 查看 BOM（`BOM.txt`）：PY32F003 × 1，按需补配继电器/连接器
4. 固件：烧录 [MCU-PY32F003](https://github.com/FasterEdge/MCU-PY32F003) 的 Keil/PlatformIO 工程，串口 115200 交互

**串口命令示例（配合 MCU-PY32F003 固件）：**

```
ability_ModbusAbility set_unit_id 3
ability_ModbusAbility write_holding 0,1      # 继电器开
ability_ModbusAbility write_holding 0,0      # 继电器关
ability_GpioAbility write 10,1
```

### 四、版本

- **1.0.20260829**（与 FasterEdge 各平台版本同步）

### 五、姊妹项目

- **[FasterEdge MCU - PY32F003](https://github.com/FasterEdge/MCU-PY32F003)**：本板主控固件（Keil / PlatformIO）
- **[FasterEdge MCU - CH32V003](https://github.com/FasterEdge/MCU-CH32V003)**：可替代主控（RISC-V）
- **[FasterEdge](https://github.com/FasterEdge/FasterEdge)**：框架主仓库
