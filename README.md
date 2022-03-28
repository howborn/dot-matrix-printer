# 点阵打字机

![预览图](https://github.com/howborn/dot-matrix-printer/blob/master/整体.jpg)

之前在学校 DIY 的点阵打字机，现整理收集到 github，包含硬件电路和软件程序代码。

## 机架

打字机机架通过拆解改造家里老式擦带录音机而来，包含 X 与 Y 轴方向各 1 台步进电机，Z 轴 1 台永磁电机。

![机架](https://github.com/howborn/dot-matrix-printer/blob/master/3.Photos/侧面.jpg)

## [硬件电路](https://github.com/howborn/dot-matrix-printer/blob/master/1.Hardware)

硬件电路基于 STC89C32 单片机作为控制 CPU，通过串口通信来接受电脑上位机的指令，实现点阵打字功能。

![3D](https://github.com/howborn/dot-matrix-printer/blob/master/1.Hardware/3D.jpg)

部分电路原理图：

![CPU电路](https://github.com/howborn/dot-matrix-printer/blob/master/1.Hardware/CPU电路.jpg)

![电机驱动电路](https://github.com/howborn/dot-matrix-printer/blob/master/1.Hardware/电机驱动电路.jpg)

![串口电路](https://github.com/howborn/dot-matrix-printer/blob/master/1.Hardware/串口电路.jpg)

## [软件源码](https://github.com/howborn/dot-matrix-printer/blob/master/2.Software)

只找到了下位机源码。
