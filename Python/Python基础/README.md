[TOC]

# Python基础

### Python简介

>Python 被称为“胶水”语言，可以同其他语言粘合着用。

#### Python的历史

>1. 1989年圣诞节：Guido von Rossum开始写Python语言的编译器。
>2. 1991年2月：第一个Python编译器（同时也是解释器）诞生，它是用C语言实现的（后面），可以调用C语言的库函数。在最早的版本中，Python已经提供了对“类”，“函数”，“异常处理”等构造块的支持，还有对列表、字典等核心数据类型，同时支持以模块为基础来构造应用程序。
>3. 1994年1月：Python 1.0正式发布。
>4. 2000年10月16日：Python 2.0发布，增加了完整的[垃圾回收](https://zh.wikipedia.org/wiki/垃圾回收_(計算機科學))，提供了对[Unicode](https://zh.wikipedia.org/wiki/Unicode)的支持。与此同时，Python的整个开发过程更加透明，社区对开发进度的影响逐渐扩大，生态圈开始慢慢形成。
>5. 2008年12月3日：Python 3.0发布，它并不完全兼容之前的Python代码，不过因为目前还有不少公司在项目和运维中使用Python 2.x版本，所以Python 3.x的很多新特性后来也被移植到Python 2.6/2.7版本中。

目前我们使用的`Python 3.7.x`的版本是在2018年发布的，Python的版本号分为三段，形如A.B.C。其中A表示大版本号，一般当整体重写，或出现不向后兼容的改变时，增加A；B表示功能更新，出现新功能时增加B；C表示小的改动（例如：修复了某个Bug），只要有修改就增加C。如果对Python的历史感兴趣，可以阅读名为[《Python简史》](http://www.cnblogs.com/vamei/archive/2013/02/06/2892628.html)的网络文章。

#### Python的优缺点

>Python的优点很多，简单的可以总结为以下几点。
>
>1. 简单明了，学习曲线低，比很多编程语言都容易上手。
>2. 开放源代码，拥有强大的社区和生态圈，尤其是在数据分析和机器学习领域。
>3. 解释型语言，天生具有平台可移植性，代码可以工作于不同的操作系统。
>4. 对两种主流的编程范式（面向对象编程和函数式编程）都提供了支持。
>5. 代码规范程度高，可读性强，适合有代码洁癖和强迫症的人群。
>
>Python的缺点主要集中在以下几点。
>
>1. 执行效率稍低，对执行效率要求高的部分可以由其他语言（如：C、C++）编写。
>2. 代码无法加密，但是现在很多公司都不销售卖软件而是销售服务，这个问题会被弱化。
>3. 在开发时可以选择的框架太多（如Web框架就有100多个），有选择的地方就有错误。

#### Python的应用领域

>目前Python在Web应用后端开发、云基础设施建设、DevOps、网络数据采集（爬虫）、自动化测试、数据分析、机器学习等领域都有着广泛的应用。运维－>自动化，人工智能，大数据处理，游戏开发。

### 安装Python解释器

>想要开始Python编程之旅，首先得在自己使用的计算机上安装Python解释器环境，下面将以安装官方的Python解释器为例，讲解如何在不同的操作系统上安装Python环境。官方的Python解释器是用C语言实现的，也是使用最为广泛的Python解释器，通常称之为CPython。除此之外，Python解释器还有Java语言实现的Jython、C#语言实现的IronPython以及PyPy、Brython、Pyston等版本，有兴趣的读者可以自行了解。

#### Windows环境

>可以在[Python官方网站](https://www.python.org/)下载到Python的Windows安装程序（exe文件），需要注意的是如果在Windows 7环境下安装Python 3.x，需要先安装Service Pack 1补丁包（可以通过一些工具软件自动安装系统补丁的功能来安装），安装过程建议勾选“Add Python 3.x to PATH”（将Python 3.x添加到PATH环境变量）并选择自定义安装，在设置“Optional Features”界面最好将“pip”、“tcl/tk”、“Python test suite”等项全部勾选上。强烈建议选择自定义的安装路径并保证路径中没有中文。安装完成会看到“Setup was successful”的提示。如果稍后运行Python程序时，出现因为缺失一些动态链接库文件而导致Python解释器无法工作的问题，可以按照下面的方法加以解决。
>
>如果系统显示api-ms-win-crt*.dll文件缺失，可以参照[《api-ms-win-crt*.dll缺失原因分析和解决方法》](https://zhuanlan.zhihu.com/p/32087135)一文讲解的方法进行处理或者直接在[微软官网](https://www.microsoft.com/zh-cn/download/details.aspx?id=48145)下载Visual C++ Redistributable for Visual Studio 2015文件进行修复；如果是因为更新Windows的DirectX之后导致某些动态链接库文件缺失问题，可以下载一个[DirectX修复工具](https://dl.pconline.com.cn/download/360074-1.html)进行修复。

#### Linux环境

Linux环境自带了Python 2.x版本，但是如果要更新到3.x的版本，可以在[Python的官方网站](https://www.python.org/)下载Python的源代码并通过源代码构建安装的方式进行安装，具体的步骤如下所示（以CentOS为例）。

1. 安装依赖库（因为没有这些依赖库可能在源代码构件安装时因为缺失底层依赖库而失败）。

```shell
yum -y install wget gcc zlib-devel bzip2-devel openssl-devel ncurses-devel sqlite-devel readline-devel tk-devel gdbm-devel db4-devel libpcap-devel xz-devel libffi-devel
```

2. 下载Python源代码并解压缩到指定目录。

```
wget https://www.python.org/ftp/python/3.7.6/Python-3.7.6.tar.xz
xz -d Python-3.7.6.tar.xz
tar -xvf Python-3.7.6.tar
```

3. 切换至Python源代码目录并执行下面的命令进行配置和安装。

```
cd Python-3.7.6
./configure --prefix=/usr/local/python37 --enable-optimizations
make && make install
```

4. 修改用户主目录下名为.bash_profile的文件，配置PATH环境变量并使其生效。

```
cd ~
vim .bash_profile
# ... 此处省略上面的代码 ...

export PATH=$PATH:/usr/local/python37/bin

# ... 此处省略下面的代码 ...
```

5. 激活环境变量。

```
source .bash_profile
```

`切换版本：`

Ubantu中默认python路径:

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggilw800fvj30m007mgna.jpg)

首先我们先看一下有没有关于Python的可选项：

```
$ update-alternatives --display pythonupdate-alternatives: 错误: 无 python 的候选项
```

那首先先建立python的组,并添加Python2和Python3的可选项

```
$ sudo update-alternatives --install /usr/bin/python python /usr/bin/python2.7 2 # 添加Python2可选项，优先级为2$ sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.4 1 #添加Python3可选项，优先级为1
```

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggilkrz1hsj30m607njt2.jpg)

