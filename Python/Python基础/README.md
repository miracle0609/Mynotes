[TOC]



 [gh-md-toc](https://github.com/ekalinin/github-markdown-toc)

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

### 保留字

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggio2xutbdj30qk06pq5l.jpg)

### 标识符

1. 不能用Pthon中的保留字
2. 由字母，下划线，数字
3. 区分大小写字母
4. `__add`表示类的私有成员;
5. `__init__()`构造函数;

### 变量

变量的定义与使用

弱类型(动态类型语言):

```python
>>> print(a)
123
>>> type(a)
<class 'int'>
>>> a = "hello world"
>>> print(a)
hello world
>>> type(a)
<class 'str'>
>>> id(a) #地址
139811477572656
>>> a = 123
>>> id(a)
9306048
>>> id(123)
9306048
>>> id(123)
9306048
>>> b = 123
>>> id(b)
9306048
>>> id("hello world")
139811477572656
>>> a = "hello world"
>>> id(a)
139811477572656
>>> 
```

### 变量和类型

在程序设计中，变量是一种存储数据的载体。计算机中的变量是实际存在的数据或者说是存储器中存储数据的一块内存空间，变量的值可以被读取和修改，这是所有计算和控制的基础。计算机能处理的数据有很多种类型，除了数值之外还可以处理文本、图形、音频、视频等各种各样的数据，那么不同的数据就需要定义不同的存储类型。Python中的数据类型很多，而且也允许我们自定义新的数据类型（这一点在后面会讲到），我们先介绍几种常用的数据类型。

- 整型：Python中可以处理任意大小的整数（Python 2.x中有`int`和`long`两种类型的整数，但这种区分对Python来说意义不大，因此在Python 3.x中整数只有int这一种了），而且支持二进制（如`0b100`，换算成十进制是4）、八进制（如`0o100`，换算成十进制是64）、十进制（`100`）和十六进制（`0x100`，换算成十进制是256）的表示法。
- 浮点型：浮点数也就是小数，之所以称为浮点数，是因为按照科学记数法表示时，一个浮点数的小数点位置是可变的，浮点数除了数学写法（如`123.456`）之外还支持科学计数法（如`1.23456e2`）。
- 字符串型：字符串是以单引号或双引号括起来的任意文本，比如`'hello'`和`"hello"`,字符串还有原始字符串表示法、字节字符串表示法、Unicode字符串表示法，而且可以书写成多行的形式（用三个单引号或三个双引号开头，三个单引号或三个双引号结尾）。
- 布尔型：布尔值只有`True`、`False`两种值，要么是`True`，要么是`False`，在Python中，可以直接用`True`、`False`表示布尔值（请注意大小写），也可以通过布尔运算计算出来（例如`3 < 5`会产生布尔值`True`，而`2 == 1`会产生布尔值`False`）。
- 复数型：形如`3+5j`，跟数学上的复数表示一样，唯一不同的是虚部的`i`换成了`j`。实际上，这个类型并不常用，大家了解一下就可以了。



```python
a = int(input('a = '))
b = int(input('b = '))
print('%d + %d = %d' % (a, b, a + b))
print('%d - %d = %d' % (a, b, a - b))
print('%d * %d = %d' % (a, b, a * b))
print('%d / %d = %f' % (a, b, a / b))#精确值
print('%d // %d = %d' % (a, b, a // b))#取整
print('%d %% %d = %d' % (a, b, a % b))#取余
print('%d ** %d = %d' % (a, b, a ** b))#幂次方
```

### 运算符

Python支持多种运算符，下表大致按照优先级从高到低的顺序列出了所有的运算符，运算符的优先级指的是多个运算符同时出现时，先做什么运算然后再做什么运算。除了我们之前已经用过的赋值运算符和算术运算符，我们稍后会陆续讲到其他运算符的使用。

| 运算符                                          | 描述                           |
| ----------------------------------------------- | ------------------------------ |
| `[]` `[:]`                                      | 下标，切片                     |
| `**`                                            | 指数                           |
| `~` `+` `-`                                     | 按位取反, 正负号               |
| `*` `/` `%` `//`                                | 乘，除，模，整除               |
| `+` `-`                                         | 加，减                         |
| `>>` `<<`                                       | 右移，左移                     |
| `&`                                             | 按位与                         |
| `^` `|`                                         | 按位异或，按位或               |
| `<=` `<` `>` `>=`                               | 小于等于，小于，大于，大于等于 |
| `==` `!=`                                       | 等于，不等于                   |
| `is` `is not`                                   | 身份运算符                     |
| `in` `not in`                                   | 成员运算符                     |
| `not` `or` `and`                                | 逻辑运算符                     |
| `=` `+=` `-=` `*=` `/=` `%=` `//=` `**=` `&=` ` | =` `^=` `>>=` `<<=`            |

> **说明：** 在实际开发中，如果搞不清楚运算符的优先级，可以使用括号来确保运算的执行顺序。

### if语句的使用

在Python中，要构造分支结构可以使用`if`、`elif`和`else`关键字。所谓**关键字**就是有特殊含义的单词，像`if`和`else`就是专门用于构造分支结构的关键字，很显然你不能够使用它作为变量名（事实上，用作其他的标识符也是不可以）。下面的例子中演示了如何构造一个分支结构。

### while循环

```python
import random

answer = random.randint(1, 100)
counter = 0
while True:
    counter += 1
    number = int(input('请输入: '))
    if number < answer:
        print('大一点')
    elif number > answer:
        print('小一点')
    else:
        print('恭喜你猜对了!')
        break
print('你总共猜了%d次' % counter)
if counter > 7:
    print('你的智商余额明显不足')
```

### for-in循环

如果明确的知道循环执行的次数或者要对一个容器进行迭代（后面会讲到），那么我们推荐使用`for-in`循环，例如下面代码中计算1~100求和的结果（$\displaystyle\sum \limits_{n=1}^{100}n$）。

```python
sum = 0
for x in range(101):
    sum += x
print(sum)
```

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggkzxjash4j30o00bmta8.jpg)

- `range(101)`：可以用来产生0到100范围的整数，需要注意的是取不到101。
- `range(1, 101)`：可以用来产生1到100范围的整数，相当于前面是闭区间后面是开区间。
- `range(1, 101, 2)`：可以用来产生1到100的奇数，其中2是步长，即每次数值递增的值。
- `range(100, 0, -2)`：可以用来产生100到1的偶数，其中-2是步长，即每次数字递减的值。

### 序列

序列加法：将两种相同类型的序列加法（合并）

```python
>>> a = "hello world"
>>> type(a)
<class 'str'>
>>> a = list(a)
>>> type(a)
<class 'list'>
>>> print(a)
['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']
>>> a = tuple(a)
>>> print(a)
('h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd')
>>> a = set(a)
>>> print(a)
{' ', 'l', 'w', 'r', 'e', 'h', 'd', 'o'}
>>> 
```



|          | 列表 | 元组 | 字典 | 集合 |
| -------- | ---- | ---- | ---- | ---- |
|          | []   | ()   | {}   | {}   |
| 是否可变 | √    | ×    | √    | √    |
| 是否重复 | √    | √    | ×    | ×    |
| 是否有序 | √    | √    | ×    | ×    |



#### 列表

接下来我们要介绍的列表（`list`），也是一种结构化的、非标量类型，它是值的有序序列，每个值都可以通过索引进行标识，定义列表可以将列表的元素放在`[]`中，多个元素用`,`进行分隔，可以使用`for`循环对列表元素进行遍历，也可以使用`[]`或`[:]`运算符取出列表中的一个或多个元素。

如何定义列表、如何遍历列表以及列表的下标运算。

```python
list1 = [1, 3, 5, 7, 100]
print(list1) # [1, 3, 5, 7, 100]
# 乘号表示列表元素的重复
list2 = ['hello'] * 3
print(list2) # ['hello', 'hello', 'hello']
# 计算列表长度(元素个数)
print(len(list1)) # 5
# 下标(索引)运算
print(list1[0]) # 1
print(list1[4]) # 100
# print(list1[5])  # IndexError: list index out of range
print(list1[-1]) # 100
print(list1[-3]) # 5
list1[2] = 300
print(list1) # [1, 3, 300, 7, 100]
# 通过循环用下标遍历列表元素
for index in range(len(list1)):
    print(list1[index])
# 通过for循环遍历列表元素
for elem in list1:
    print(elem)
# 通过enumerate函数处理列表之后再遍历可以同时获得元素索引和值
for index, elem in enumerate(list1):
    print(index, elem)
```

如何向列表中添加元素以及如何从列表中移除元素。

```python
list1 = [1, 3, 5, 7, 100]
# 添加元素
list1.append(200)
list1.insert(1, 400)
# 合并两个列表
# list1.extend([1000, 2000])
list1 += [1000, 2000]
print(list1) # [1, 400, 3, 5, 7, 100, 200, 1000, 2000]
print(len(list1)) # 9
# 先通过成员运算判断元素是否在列表中，如果存在就删除该元素
if 3 in list1:
	list1.remove(3)
if 1234 in list1:
    list1.remove(1234)
print(list1) # [1, 400, 5, 7, 100, 200, 1000, 2000]
# 从指定的位置删除元素
list1.pop(0)
list1.pop(len(list1) - 1)
print(list1) # [400, 5, 7, 100, 200, 1000]
# 清空列表元素
list1.clear()
print(list1) # []
```

和字符串一样，列表也可以做切片操作，通过切片操作我们可以实现对列表的复制或者将列表中的一部分取出来创建出新的列表，代码如下所示。

```python
fruits = ['grape', 'apple', 'strawberry', 'waxberry']
fruits += ['pitaya', 'pear', 'mango']
# 列表切片
fruits2 = fruits[1:4]
print(fruits2) # apple strawberry waxberry
# 可以通过完整切片操作来复制列表
fruits3 = fruits[:]
print(fruits3) # ['grape', 'apple', 'strawberry', 'waxberry', 'pitaya', 'pear', 'mango']
fruits4 = fruits[-3:-1]
print(fruits4) # ['pitaya', 'pear']
# 可以通过反向切片操作来获得倒转后的列表的拷贝
fruits5 = fruits[::-1]
print(fruits5) # ['mango', 'pear', 'pitaya', 'waxberry', 'strawberry', 'apple', 'grape']
```

下面的代码实现了对列表的排序操作。

```python
list1 = ['orange', 'apple', 'zoo', 'internationalization', 'blueberry']
list2 = sorted(list1)
# sorted函数返回列表排序后的拷贝不会修改传入的列表
# 函数的设计就应该像sorted函数一样尽可能不产生副作用
list3 = sorted(list1, reverse=True)
# 通过key关键字参数指定根据字符串长度进行排序而不是默认的字母表顺序
list4 = sorted(list1, key=len)
print(list1)
print(list2)
print(list3)
print(list4)
# 给列表对象发出排序消息直接在列表对象上进行排序
list1.sort(reverse=True)
print(list1)
```

变成字典

```python
>>> for index, item in enumerate(num):
...     print(index, item)
... 
0 0
1 2
2 4
3 6
4 8
5 10
```

扩容：

```python
>>> print(num)
[0, 2, 4, 6, 8, 10]
>>> num.append("fangsong")
>>> print(num)
[0, 2, 4, 6, 8, 10, 'fangsong']
>>> list1 = ["帅", "能力强", "高", "富"]
>>> num.extend(list1)
>>> print(num)
[0, 2, 4, 6, 8, 10, 'fangsong', '帅', '能力强', '高', '富']
>>> 
```

删除等

```python
>>> num.remove(6)
>>> print(num)
[2, 4, 8, 10, 'fangsong', '帅', '能力强', '高', '富']
>>> num.remove('fangsong')
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富']
>>> num.append(5)
>>> num.append(5)
>>> num.append(5)
>>> num.append(5)
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5, 5, 5, 5]
>>> num.remove(5)
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5, 5, 5]
>>> num.remove(5)
>>> num.remove(5)
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5]
>>> num.append(5)
>>> num.append(5)
>>> num.count(5)
3
>>> print(num)
[2, 4, 8, 10, '帅', '能力强', '高', '富', 5, 5, 5]
>>> 
```

随机列表:

```python
>>> import random
>>> randnum = [random.randint(10, 100) for i in range(10)]
>>> print(randnum)
[15, 26, 24, 14, 80, 40, 84, 32, 16, 93]
>>> print(randnum)
[15, 26, 24, 14, 80, 40, 84, 32, 16, 93]
>>> randnum = [random.randint(10, 100) for i in range(10)]
>>> print(randnum)
[60, 92, 89, 83, 37, 80, 43, 79, 54, 76]
>>> 
```

列表推导式:

newlist = [Expression for var in list]

```python
>>> num2 = [i for i in num if isinstance(i, int)]
>>> print(num2)
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100]
>>> 

```





#### 元组

比列表访问和处理速度快

Python的元组与列表类似，不同之处在于元组的元素不能修改。元组使⽤⼩括号，列表使⽤⽅括号。

```python
>>> string = "hello world"
>>> string = tuple(string)
>>> type(string)
<class 'tuple'>
>>> string
('h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd')
>>> 
```

![img](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/ipython-timeit.png)

1. 访问元祖

   ```python
   >>> tuple=('hello', 100, 3.14)
   >>> tuple[0]
   'hello'
   >>> tuple[1]
   100
   >>> tuple[2]
   3.14
   ```

2. 修改元祖

   ```python
   >>> tuple[2] = 180
   Traceback (most recent call last):
     File "<stdin>", line 1, in <module>
   TypeError: 'tuple' object does not support item assignment
   >>> 
   
   
   >>> p = (1, 2)
   >>> p = (3, 4)
   >>> p
   (3, 4)
   >>> p = (3, 4, 5)
   >>> p
   (3, 4, 5)
   ```

   说明不能修改元素

3. count, index

   ```python
   >>> a = ('a', 'b', 'c', 'a', 'b')
   >>> a.index('a', 1, 3) # 注意是左闭右开区间
   Traceback (most recent call last):
       File "<stdin>", line 1, in <module>
   ValueError: tuple.index(x): x not in tuple
   >>> a.index('a', 1, 4)
   3
   >>> a.count('b')
   2
   >>> a.count('d')
   0
   ```

4. 比较

   如果比较的元素是同类型的,则比较其值,返回结果。

   如果两个元素不是同一种类型,则检查它们是否是数字。

   - 如果是数字,执行必要的数字强制类型转换,然后比较。
   - 如果有一方的元素是数字,则另一方的元素"大"(数字是"最小的")
   - 否则,通过类型名字的字母顺序进行比较。

   如果有一个列表首先到达末尾,则另一个长一点的列表"大"。

   如果我们用尽了两个列表的元素而且所 有元素都是相等的,那么结果就是个平局,就是说返回一个 0。

   ```python
   #!/usr/bin/python
   
   tuple1, tuple2 = (123, 'xyz'), (456, 'abc')
   
   print cmp(tuple1, tuple2);
   print cmp(tuple2, tuple1);
   tuple3 = tuple2 + (786,);
   print cmp(tuple2, tuple3)
   tuple4 = (123, 'xyz')
   print cmp(tuple1, tuple4)
   ```

   ```python
   -1
   1
   -1
   0
   ```

5. 长度

   以下实例展示了 len()函数的使用方法：

   ```python
   #!/usr/bin/python
   
   tuple1, tuple2 = (123, 'xyz', 'zara'), (456, 'abc')
   
   print "First tuple length : ", len(tuple1);
   print "Second tuple length : ", len(tuple2);
   ```

   以上实例输出结果如下：

   ```python
   First tuple length :  3
   Second tuple length :  2
   ```

6. Max

   以下实例展示了 max()函数的使用方法：

   ```python
   #!/usr/bin/python
   
   tuple1, tuple2 = (123, 'xyz', 'zara', 'abc'), (456, 700, 200)
   
   print "Max value element : ", max(tuple1);
   print "Max value element : ", max(tuple2);
   ```

   以上实例输出结果如下：

   ```
   Max value element :  zara
   Max value element :  700
   ```

#### 字典

类似哈希结构

字典是另一种可变容器模型，且可存储任意类型对象。

字典的每个键值 **key=>value** 对用冒号 **:** 分割，每个键值对之间用逗号 **,** 分割，整个字典包括在花括号 **{}** 中 ,格式如下所示：

>d = {key1 : value1, key2 : value2 }

```python
>>> num = {}
>>> type(num)
<class 'dict'> #类型
```

由两个list创建字典

```python
>>> list1 = list(range(10))
>>> list1
[0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
>>> list2 = ["Marry", "shengdeng", "Zege"]
>>> list2
['Marry', 'shengdeng', 'Zege']
>>> dictionary = dict(zip(list1, list2))
>>> dictionary[0]
'Marry'
>>> dictionary[1]
'shengdeng'
>>> dictionary[2]
'Zege'
>>> dictionary[3]
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 3
>>> 

```



1. 访问字典中值

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   print "dict['Name']: ", dict['Name']
   print "dict['Age']: ", dict['Age']
   ```

   ```python
   dict['Name']:  Zara
   dict['Age']:  7
   ```

   如果用字典里没有的键访问数据，会输出错误如下：

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   print "dict['Alice']: ", dict['Alice']
   ```

   ```python
   dict['Alice']: 
   Traceback (most recent call last):
     File "test.py", line 5, in <module>
       print "dict['Alice']: ", dict['Alice']
   KeyError: 'Alice'
   ```

2. 修改字典

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   dict['Age'] = 8 # 更新
   dict['School'] = "RUNOOB" # 添加
    
    
   print "dict['Age']: ", dict['Age']
   print "dict['School']: ", dict['School']
   ```

   ```python
   dict['Age']:  8
   dict['School']:  RUNOOB
   ```

3. 删除字典元素

   能删单一的元素也能清空字典，清空只需一项操作。

   显示删除一个字典用del命令，如下实例：

   ```python
   #!/usr/bin/python
   # -*- coding: UTF-8 -*-
    
   dict = {'Name': 'Zara', 'Age': 7, 'Class': 'First'}
    
   del dict['Name']  # 删除键是'Name'的条目
   dict.clear()      # 清空字典所有条目
   del dict          # 删除字典
    
   print "dict['Age']: ", dict['Age'] 
   print "dict['School']: ", dict['School']
   ```

   但这会引发一个异常，因为用del后字典不再存在：

   ```python
   dict['Age']:
   Traceback (most recent call last):
     File "test.py", line 8, in <module>
       print "dict['Age']: ", dict['Age'] 
   TypeError: 'type' object is unsubscriptable
   ```

4. 字典键的特性

   1）不允许同一个键出现两次。创建时如果同一个键被赋值两次，后一个值会被记住，如下实例：

   ```python
   #!/usr/bin/python
    
   dict = {'Name': 'Zara', 'Age': 7, 'Name': 'Manni'} 
    
   print "dict['Name']: ", dict['Name']
   ```

   ```
   dict['Name']:  Manni
   ```

   2）键必须不可变，所以可以用数字，字符串或元组充当，所以用列表就不行，如下实例：

   ```python
   #!/usr/bin/python
    
   dict = {['Name']: 'Zara', 'Age': 7} 
    
   print "dict['Name']: ", dict['Name']
   ```

   ```
   Traceback (most recent call last):
     File "test.py", line 3, in <module>
       dict = {['Name']: 'Zara', 'Age': 7} 
   TypeError: list objects are unhashable
   
   
   ```

5. 内置方法

| 1    | [dict.clear()](https://www.runoob.com/python/att-dictionary-clear.html) 删除字典内所有元素 |
| ---- | ------------------------------------------------------------ |
| 2    | [dict.copy()](https://www.runoob.com/python/att-dictionary-copy.html) 返回一个字典的浅复制 |
| 3    | [dict.fromkeys(seq, val\)](https://www.runoob.com/python/att-dictionary-fromkeys.html) 创建一个新字典，以序列 seq 中元素做字典的键，val 为字典所有键对应的初始值 |
| 4    | [dict.get(key, default=None)](https://www.runoob.com/python/att-dictionary-get.html) 返回指定键的值，如果值不在字典中返回default值 |
| 5    | [dict.has_key(key)](https://www.runoob.com/python/att-dictionary-has_key.html) 如果键在字典dict里返回true，否则返回false |
| 6    | [dict.items()](https://www.runoob.com/python/att-dictionary-items.html) 以列表返回可遍历的(键, 值) 元组数组 |
| 7    | [dict.keys()](https://www.runoob.com/python/att-dictionary-keys.html) 以列表返回一个字典所有的键 |
| 8    | [dict.setdefault(key, default=None)](https://www.runoob.com/python/att-dictionary-setdefault.html) 和get()类似, 但如果键不存在于字典中，将会添加键并将值设为default |
| 9    | [dict.update(dict2)](https://www.runoob.com/python/att-dictionary-update.html) 把字典dict2的键/值对更新到dict里 |
| 10   | [dict.values()](https://www.runoob.com/python/att-dictionary-values.html) 以列表返回字典中的所有值 |
| 11   | [pop(key,default\])](https://www.runoob.com/python/python-att-dictionary-pop.html) 删除字典给定键 key 所对应的值，返回值为被删除的值。key值必须给出。 否则，返回default值。 |
| 12   | [popitem()](https://www.runoob.com/python/python-att-dictionary-popitem.html) 返回并删除字典中的最后一对键和值。 |

[3].  [dict.fromkeys(seq, val\)](https://www.runoob.com/python/att-dictionary-fromkeys.html) 方法

```python
#!/usr/bin/python
# -*- coding: UTF-8 -*-
 
seq = ('Google', 'Runoob', 'Taobao')
 
dict = dict.fromkeys(seq)
print "新字典为 : %s" %  str(dict)
 
dict = dict.fromkeys(seq, 10)
print "新字典为 : %s" %  str(dict)
```

```
新字典为 : {'Google': None, 'Taobao': None, 'Runoob': None}
新字典为 : {'Google': 10, 'Taobao': 10, 'Runoob': 10}
```

[4].[dict.get(key, default=None)](https://www.runoob.com/python/att-dictionary-get.html) 方法

```python
#!/usr/bin/python

dict = {'Name': 'Runoob', 'Age': 27}

print "Value : %s" %  dict.get('Age')
print "Value : %s" %  dict.get('Sex', "Never")
```

```
Value : 27
Value : Never
```

[5].[dict.has_key(key)](https://www.runoob.com/python/att-dictionary-has_key.html) 方法

```python
#!/usr/bin/python

dict = {'Name': 'Zara', 'Age': 7}

print "Value : %s" %  dict.has_key('Age')
print "Value : %s" %  dict.has_key('Sex')
```

```
Value : True
Value : False
```

[6].    [dict.items()](https://www.runoob.com/python/att-dictionary-items.html) 

```python
#!/usr/bin/python
# coding=utf-8
 
dict = {'Google': 'www.google.com', 'Runoob': 'www.runoob.com', 'taobao': 'www.taobao.com'}
 
print "字典值 : %s" %  dict.items()
 
# 遍历字典列表
for key,values in  dict.items():
    print key,values
```

```
字典值 : [('Google', 'www.google.com'), ('taobao', 'www.taobao.com'), ('Runoob', 'www.runoob.com')]
Google www.google.com
taobao www.taobao.com
Runoob www.runoob.com
```

[7].[dict.keys()](https://www.runoob.com/python/att-dictionary-keys.html)

```python
#!/usr/bin/python

dict = {'Name': 'Zara', 'Age': 7}

print "Value : %s" %  dict.keys()
```

```
Value : ['Age', 'Name']
```

#### 集合

自动去重

```python

```

Python中的集合跟数学上的集合是一致的，不允许有重复元素，而且可以进行交集、并集、差集等运算。

![img](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/python-set.png)



可以按照下面代码所示的方式来创建和使用集合。

```python
# 创建集合的字面量语法
set1 = {1, 2, 3, 3, 3, 2}
print(set1)
print('Length =', len(set1))
# 创建集合的构造器语法(面向对象部分会进行详细讲解)
set2 = set(range(1, 10))
set3 = set((1, 2, 3, 3, 2, 1))
print(set2, set3)
# 创建集合的推导式语法(推导式也可以用于推导集合)
set4 = {num for num in range(1, 100) if num % 3 == 0 or num % 5 == 0}
print(set4)
```

向集合添加元素和从集合删除元素。

```python
set1.add(4)
set1.add(5)
set2.update([11, 12])
set2.discard(5)
if 4 in set2:
    set2.remove(4)
print(set1, set2)
print(set3.pop())
print(set3)
```

集合的成员、交集、并集、差集等运算。

```python
# 集合的交集、并集、差集、对称差运算
print(set1 & set2)
# print(set1.intersection(set2))
print(set1 | set2)
# print(set1.union(set2))
print(set1 - set2)
# print(set1.difference(set2))
print(set1 ^ set2)
# print(set1.symmetric_difference(set2))
# 判断子集和超集
print(set2 <= set1)
# print(set2.issubset(set1))
print(set3 <= set1)
# print(set3.issubset(set1))
print(set1 >= set2)
# print(set1.issuperset(set2))
print(set1 >= set3)
# print(set1.issuperset(set3))
```

> **说明：** Python中允许通过一些特殊的方法来为某种类型或数据结构自定义运算符（后面的章节中会讲到），上面的代码中我们对集合进行运算的时候可以调用集合对象的方法，也可以直接使用对应的运算符，例如`&`运算符跟intersection方法的作用就是一样的，但是使用运算符让代码更加直观。

