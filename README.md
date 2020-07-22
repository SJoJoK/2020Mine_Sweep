# Mine_Sweep

* 组员：孙嘉锴、陈崇轩、陆佳誉
* 校园生活和教育娱乐

## 项目描述

### 总体目标

本项目主要实现一个简洁的扫雷游戏，并在此基础上提供自定义雷区，排行榜，作弊模式等新功能。

软件运行在Windows系统下，各版本的Windows都可以运行。

### 功能分析

1. 基础扫雷功能

   用户在雷区的某一方块上，可点击左键或右键进行相应的操作

   * 左键

     点击左键进行试探，若是地雷则游戏失败，否则，若与该方块邻接的方块内有地雷，则显示邻接方块地雷总数，若与该方块邻接的方块内无地雷，则递归显示直至邻接方块有地雷的方块

   * 右键

     点击右键进行标记，按照无标记->红旗->问号->无标记循环。当红旗与含地雷的方块一一对应时，游戏胜利

2. 自定义雷区

     用户可自行设计雷区的行列数，以及地雷总数。

     程序内置三种不同的难度可供用户切换。

3. 排行榜

     以达到胜利所需时间为准，存储游戏玩家的排行榜

4. 作弊模式

     显示所有地雷

## 开发工具与项目管理

|   名称   |    工具     |
| :------: | :---------: |
| 版本控制 | Git, GitHub |
| 构建工具 |  qmake+jom  |
| 持续集成 |   Jenkins   |
| 编程语言 |   C++ 17    |
| 软件框架 |    MVVM     |
| 交流协作 |    钉钉     |
| 图形界面 |     Qt      |
| 文档编辑 |  Markdown   |

## 开发计划与分工

### 开发计划

|  日期   |                             工作                             |
| :-----: | :----------------------------------------------------------: |
| 7月8日  |                 确定分工，选择工具，搭好框架                 |
| 7月9日  |                 熟悉MVVM模式，实现“重启”功能                 |
| 7月10日 |                    绘制雷区，实现左键点击                    |
| 7月11日 |                实现右键点击，基本实现游戏功能                |
| 7月12日 | 实现难度切换，时间显示，红旗显示以及创作者显示，完全实现游戏功能 |
| 7月13日 |         实现自定义雷区，作弊模式以及排行榜，满足需求         |

### 分工

|  姓名  |                    工作                    |
| :----: | :----------------------------------------: |
| 孙嘉锴 | 分工，管理Git，搭建框架，写Comoon层与App层 |
| 陈崇轩 |           写ViewModel层与Model层           |
| 陆佳誉 |                  写View层                  |

## 构建方式

首先使用qmake生成Makefile文件

```bash
qmake.exe Mine_sweeping.pro -spec win32-msvc "CONFIG+=qtquickcompiler"
```

接着使用jom.exe即可，例：

Release

```bash
F:\Qt\Tools\QtCreator\bin\jom.exe -f Makefile.Release
```

Debug

```bash
F:\Qt\Tools\QtCreator\bin\jom.exe -f Makefile.Debug
```

## 具体实现

### MVVM

* Common
  * Block类，代表雷区
  * Square类，代表方块
  * Parameter，各命令的参数类
* Model
  * 存储雷区
  * 所有操作的具体实现，反映在雷区上
* ViewModel
  * 持有Model
  * 接受Model层Fire的消息并Fire至View层
  * 编写不同Command的SetParameter和Exec
* View
  * 根据绑定的数据进行绘制
  * 根据用户的输入执行不同的命令
  * 接受ViewModel层Fire的消息，执行对应操作
* App
  * 初始化工作以及绑定

### 迭代
- [x] 第一轮
  - [x]  熟悉MVVM模式，实现"重启"
- [x] 第二轮
  - [x]  绘制雷区
  - [x]  左键点击功能
- [x] 第三轮
  - [x]  右键点击
  - [x]  胜负判断
- [x] 第四轮
  - [x]  难度切换
  - [x]  时间显示
  - [x]  红旗显示
  - [x]  创作者显示
- [x] 第五轮
  - [x]  自定义雷区
  - [x]  作弊模式
  - [x]  排行榜



## 项目展示

* 开始游戏（默认初级难度）

  ![image-20200713223955734](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713223955734.png)

* 开启作弊（显示所有地雷）

  ![image-20200713224024335](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224024335.png)

* 关闭作弊，正常游戏

  ![image-20200713224119955](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224119955.png)

* 游戏失败

  ![image-20200713224139082](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224139082.png)

* 切换难度

  ![image-20200713224337223](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224337223.png)

  

* 游戏胜利，留名

  ![image-20200713224548655](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224548655.png)

* 查看排行榜

  ![image-20200713224606388](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224606388.png)

* 自定义雷区

  ![image-20200713224705715](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224705715.png)

![image-20200713224733002](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224733002.png)

* 查看创作者

  ![image-20200713224746186](C:\Users\45098\AppData\Roaming\Typora\typora-user-images\image-20200713224746186.png)