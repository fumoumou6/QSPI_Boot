# STM32H750VBT6 bootloader

~~~ 
反客科技H7核心板
~~~

~~~
环境: win10 + CLion + openocd + stm32cubemx
~~~

## 原理图
![](SCH/FK750M3-VBT6（半孔版）原理图_1.png)
![](SCH/FK750M3-VBT6（半孔版）原理图_2.png)


## 程序原理
~~~
1.初始化外设
2.开启spiflash内存映射模式
3.关闭MPU                          (note!!!)
4.关闭系统定时器,清零重载值和计数值   (note!!!)
5，设置app起始地址
6.设置主堆栈指针
7.跳转
~~~




## 参考反客科技提供的程序
~~~
反客科技淘宝店铺: https://shop212360197.taobao.com/?spm=a230r.1.0.0.204e2dc8LplcWh
~~~