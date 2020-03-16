#　shell基础





[TOC]



#### 第一个SHELL脚本

```shell
#!/bin/bash  #下面代码告诉由什么解释
echo 'Hello HaiZei' ＃简单输出
```

```
bash a.sh 或chmod + x a.sh
```

#### 变量与局部变量

* 变量的定义：

```shell
a=12
a=helloword
a=`pwd`
a=$a:a　＃拼接
```

"$"变量引用,"[]"是用来限制$范围，

* 局部变量：

```shell
local a=12
```

#### 特殊变量

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-32-11%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-41-30%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



特殊变量列表

| **变量** | **含义**                                                     |
| :------: | :----------------------------------------------------------- |
|    $0    | 当前脚本的文件名                                             |
|    $n    | 传递给脚本或函数的参数。n 是一个数字，表示第几个参数。例如，第一个参数是$1，第二个参数是$2。 |
|    $#    | 传递给脚本或函数的参数个数。                                 |
|    $*    | 传递给脚本或函数的所有参数。                                 |
|    $@    | 传递给脚本或函数的所有参数。被双引号(" ")包含时，与 $* 稍有不同，下面将会讲到。 |
|    $?    | 上个命令的退出状态，或函数的返回值。                         |
|    $$    | 当前 Shell 进程 ID。对于 Shell 脚本，就是这些脚本所在的进程 ID。 |



例如，$表示当前 Shell 进程的 ID，即 pid，看下面的代码：

```
echo $$
echo $?
```

运行结果

```
29949
0
```

请看下面的脚本：

```shell
#!/bin/bash

echo "File Name: $0"
echo "First Parameter : $1"
echo "First Parameter : $2"
echo "Quoted Values: $@"
echo "Quoted Values: $*"
echo "Total Number of Parameters : $#"
```

运行结果：

```shell
$./test.sh Zara Ali
File Name : ./test.sh
First Parameter : Zara
Second Parameter : Ali
Quoted Values: Zara Ali
Quoted Values: Zara Ali
Total Number of Parameters : 2
```

**$* 和 $@ 的区别**

$* 和 $@ 都表示传递给函数或脚本的所有参数，不被双引号(" ")包含时，都以"$1" "$2" … "$n" 的形式输出所有参数。

但是当它们被双引号(" ")包含时，"$*" 会将所有的参数作为一个整体，以"$1 $2 … $n"的形式输出所有参数；"$@" 会将各个参数分开，以"$1" "$2" … "$n" 的形式输出所有参数。



```shell
#!/bin/bash 
echo "\$*=" $*
echo "\"\$\"=" "$*"
echo "\$@=" $@
echo "\"\$@\"=" "$@"

echo "print each param from \$*"
for var in $*
do
    echo "$var"
done

echo "print each param from \$@"
for var in $@
do
    echo "$var"
done
echo "print each param from \"\$*\""
for var in "$*"
do
    echo "$var"
done

echo "print each param from \"\$@\""
for var in "$@"
do
    echo "$var"
done
```



运行结果

```shell
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ./test.sh "a" "b" "c" "d"
$*= a b c d
"$"= a b c d
$@= a b c d
"$@"= a b c d
print each param from $*
a
b
c
d
print each param from $@
a
b
c
d
print each param from "$*"
a b c d
print each param from "$@"
a
b
c
d

```

#### 变量，参数展开

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-53-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

变量替换可以根据变量的状态（是否为空、是否定义等）来改变它的值

可以使用的变量替换形式：

|      形式       | 说明                                                         |
| :-------------: | :----------------------------------------------------------- |
|     ${var}      | 变量本来的值                                                 |
|  ${var:-word}   | 如果变量 var 为空或已被删除(unset)，那么返回 word，但不改变 var 的值 |
|  ${var:=word}   | 如果变量 var 为空或已被删除(unset)，那么返回 word，并将 var 的值设置为 word。 |
| ${var:?message} | 如果变量 var 为空或已被删除(unset)，那么将消息 message 送到标 准错误输出，可以用来检测变量 var 是否可以被正常赋值。若此替换出现在 Shell 脚本中，那么脚本将停止运行。 |
|  ${var:+word}   | 如果变量 var 被定义，那么返回 word，但不改变 var 的值。      |

#### 算术运算符

先来看一个使用算术运算符的例子：

```shell
#!/bin/sh

a=10
b=20
val=`expr $a + $b`
echo "a + b : $val"

val=`expr $a - $b`
echo "a - b : $val"

val=`expr $a \* $b`
echo "a * b : $val"

val=`expr $b / $a`
echo "b / a : $val"

val=`expr $b % $a`
echo "b % a : $val"

if [ $a == $b ]
then
   echo "a is equal to b"
fi

if [ $a != $b ]
then
   echo "a is not equal to b"
fi
```

运行结果：

```shell
a + b : 30
a - b : -10
a * b : 200
b / a : 2
b % a : 0
a is not equal to b
```

注意：

- 乘号(*)前边必须加反斜杠()才能实现乘法运算；
- if...then...fi 是条件语句.

| 运算符 | 说明                                          | 举例                          |
| :----- | :-------------------------------------------- | :---------------------------- |
| +      | 加法                                          | `expr $a + $b` 结果为 30。    |
| -      | 减法                                          | `expr $a - $b` 结果为 10。    |
| *      | 乘法                                          | `expr $a \* $b` 结果为  200。 |
| /      | 除法                                          | `expr $b / $a` 结果为 2。     |
| %      | 取余                                          | `expr $b % $a` 结果为 0。     |
| =      | 赋值                                          | a=$b 将把变量 b 的值赋给 a。  |
| ==     | 相等。用于比较两个数字，相同则返回 true。     | [ $a == $b ] 返回 false。     |
| !=     | 不相等。用于比较两个数字，不相同则返回 true。 | [ $a != $b ] 返回 true。      |

注意：条件表达式要放在方括号之间，并且要有空格，例如 [$a==$b] 是错误的，必须写成 [ $a == $b ]。



#### 字符串展开

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-54-19%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2019-54-48%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 输入输出-READ

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-26-40%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



#### 输入输出-ECHO

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-27-54%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

如果表达式中包含特殊字符，Shell 将会进行替换。例如，在双引号中使用变量就是一种替换，转义字符也是一种替换。

举个例子：

```shell
#!/bin/bash

a=10
echo -e "Value of a is $a \n"
```

运行结果：

```shell
Value of a is 10
```

这里 -e 表示对转义字符进行替换。如果不使用 -e 选项，将会原样输出：

```shell
Value of a is 10\n
```

<font color = red>可以使用 echo 命令的 -E 选项禁止转义，默认也是不转义的；使用 -n 选项可以禁止插入换行符。</font>



#### 输入输出-PRINTF

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-28-44%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

- printf命令不用加括号
- format-string可以没有引号，但最好加上，单引号双引号相似。
- 参数多于格式控制符（％）时，format-string可以重用，可以将所有参数都转换。
- arguments使用空格分隔，不用逗号。

```shell
$ printf "%d %s\n" 1 "abc"
1 abc
```



#### 函数

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-29-20%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

在 Shell中，调用函数时可以向其传递参数。在函数体内部，通过 $n 的形式来获取参数的值，例如，$1 表示第一个参数，$2 表示第二个参数...

带参数的函数示例：

```shell
#!/bin/bash
funWithParam(){
    echo "The value of the first parameter is $1 !"
    echo "The value of the second parameter is $2 !"
    echo "The value of the tenth parameter is $10 !"
    echo "The value of the tenth parameter is ${10} !"
    echo "The value of the eleventh parameter is ${11} !"
    echo "The amount of the parameters is $# !"  # 参数个数
    echo "The string of the parameters is $* !"  # 传递给函数的所有参数
}
funWithParam 1 2 3 4 5 6 7 8 9 34 73
```

运行脚本：

```shell
The value of the first parameter is 1 !
The value of the second parameter is 2 !
The value of the tenth parameter is 10 !
The value of the tenth parameter is 34 !
The value of the eleventh parameter is 73 !
The amount of the parameters is 12 !
The string of the parameters is 1 2 3 4 5 6 7 8 9 34 73 !"
```

注意，$10 不能获取第十个参数，获取第十个参数需要 ${10}。当 n>=10 时，需要使用 ${n} 来获取参数。

另外，还有几个特殊变量用来处理参数，前面已经提到：

| 特殊变量 | 说明                                              |
| :------- | :------------------------------------------------ |
| $#       | 传递给函数的参数个数。                            |
| $*       | 显示所有传递给函数的参数。                        |
| $@       | 与 $* 相同，但是略有区别，请查看 Shell 特殊变量。 |
| $?       | 函数的返回值。                                    |





#### 流程控制-IF

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-30-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)



```shell
#!/bin/bash

a=10
b=20
if [ $a == $b ]
then
    echo "a=b"
else 
    echo "a!=b"
fi
```

if与[]有空格，内都有空格

- if ... fi 语句；
- if ... else ... fi 语句；
- if ... elif ... else ... fi 语句。

**1)** if ... else 语句

```shell
if [ expression ]
then
   Statement(s) to be executed if expression is true
fi

```

**2)** if ... else ... fi 语句

```shell
if [ expression ]
then
   Statement(s) to be executed if expression is true
else
   Statement(s) to be executed if expression is not true
fi
```

```shell
#!/bin/sh

a=10
b=20

if [ $a == $b ]
then
   echo "a is equal to b"
else
   echo "a is not equal to b"
fi
```

执行结果：

```sh
a is not equal to b
```

**3)** if ... elif ... fi 语句

```shell
if [ expression 1 ]
then
   Statement(s) to be executed if expression 1 is true
elif [ expression 2 ]
then
   Statement(s) to be executed if expression 2 is true
elif [ expression 3 ]
then
   Statement(s) to be executed if expression 3 is true
else
   Statement(s) to be executed if no expression is true
fi
```

if ... else 语句也经常与 test 命令结合使用，如下所示：

```shell
num1=$[2*3]
num2=$[1+5]
if test $[num1] -eq $[num2]
then
    echo 'The two numbers are equal!'
else
    echo 'The two numbers are not equal!'
fi
```

输出：

```shell
The two numbers are equal!
```

test 命令用于检查某个条件是否成立，与方括号([ ])类似。





#### 关系运算符

关系运算符只支持数字，不支持字符串，除非字符串的值是数字。

先来看一个关系运算符的例子：

```shell
#!/bin/sh

a=10
b=20
if [ $a -eq $b ]
then
   echo "$a -eq $b : a is equal to b"
else
   echo "$a -eq $b: a is not equal to b"
fi

if [ $a -ne $b ]
then
   echo "$a -ne $b: a is not equal to b"
else
   echo "$a -ne $b : a is equal to b"
fi

if [ $a -gt $b ]
then
   echo "$a -gt $b: a is greater than b"
else
   echo "$a -gt $b: a is not greater than b"
fi

if [ $a -lt $b ]
then
   echo "$a -lt $b: a is less than b"
else
   echo "$a -lt $b: a is not less than b"
fi

if [ $a -ge $b ]
then
   echo "$a -ge $b: a is greater or  equal to b"
else
   echo "$a -ge $b: a is not greater or equal to b"
fi

if [ $a -le $b ]
then
   echo "$a -le $b: a is less or  equal to b"
else
   echo "$a -le $b: a is not less or equal to b"
fi
```

运行结果：

```shell
10 -eq 20: a is not equal to b
10 -ne 20: a is not equal to b
10 -gt 20: a is not greater than b
10 -lt 20: a is less than b
10 -ge 20: a is not greater or equal to b
10 -le 20: a is less or  equal to b
```

| 运算符 | 说明                                                  | 举例                       |
| :----- | :---------------------------------------------------- | :------------------------- |
| -eq    | 检测两个数是否相等，相等返回 true。                   | [ $a -eq $b ] 返回 true。  |
| -ne    | 检测两个数是否相等，不相等返回 true。                 | [ $a -ne $b ] 返回 true。  |
| -gt    | 检测左边的数是否大于右边的，如果是，则返回 true。     | [ $a -gt $b ] 返回 false。 |
| -lt    | 检测左边的数是否小于右边的，如果是，则返回 true。     | [ $a -lt $b ] 返回 true。  |
| -ge    | 检测左边的数是否大等于右边的，如果是，则返回 true。   | [ $a -ge $b ] 返回 false。 |
| -le    | 检测左边的数是否小于等于右边的，如果是，则返回 true。 | [ $a -le $b ] 返回 true。  |



| 运算符 | 说明                                                | 举例                                     |
| :----- | :-------------------------------------------------- | :--------------------------------------- |
| !      | 非运算，表达式为 true 则返回 false，否则返回 true。 | [ ! false ] 返回 true。                  |
| -o     | 或运算，有一个表达式为 true 则返回 true。           | [ $a -lt 20 -o $b -gt 100 ] 返回 true。  |
| -a     | 与运算，两个表达式都为 true 才返回 true。           | [ $a -lt 20 -a $b -gt 100 ] 返回 false。 |



| 运算符 | 说明                                      | 举例                     |
| :----- | :---------------------------------------- | :----------------------- |
| =      | 检测两个字符串是否相等，相等返回 true。   | [ $a = $b ] 返回 false。 |
| !=     | 检测两个字符串是否相等，不相等返回 true。 | [ $a != $b ] 返回 true。 |
| -z     | 检测字符串长度是否为0，为0返回 true。     | [ -z $a ] 返回 false。   |
| -n     | 检测字符串长度是否为0，不为0返回 true。   | [ -z $a ] 返回 true。    |
| str    | 检测字符串是否为空，不为空返回 true。     | [ $a ] 返回 true。       |



#### 流程控制-WHILE

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-31-26%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 流程控制-FOR

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-32-03%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

```
for 变量 in 列表
do
    command1
    command2
    ...
    commandN
done
```

* 例如

```
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done
```

运行结果：

```shell
The value is: 1
The value is: 2
The value is: 3
The value is: 4
The value is: 5
```

* 顺序输出字符串中的字符：

```shell
for str in 'This is a string'
do
    echo $str
done
```

运行结果：

```
This is a string
```

* 显示主目录下以 .bash 开头的文件：

```
#!/bin/bash

for FILE in $HOME/.bash*
do
   echo $FILE
done
```

运行结果：

```
/root/.bash_history
/root/.bash_logout
/root/.bash_profile
/root/.bashrc
```





#### 流程控制-UNTIL

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-32-25%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 流程控制-CASE

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-33-34%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### Shell 字符串

字符串是 shell 编程中最常用最有用的数据类型（除了数字和字符串，也没啥其它类型好用了），字符串可以用单引号，也可以用双引号，也可以不用引号。单双引号的区别跟 PHP 类似。

* 单引号

```shell
str='this is a string'
```

单引号字符串的限制： 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的； 单引号字串中不能出现单引号（对单引号使用转义符后也不行）。

* 双引号

```shell
your_name='qinjx'
str="Hello, I know your are \"$your_name\"! \n"
```

双引号的优点： 双引号里可以有变量 双引号里可以出现转义字符

* 拼接字符串

```shell
your_name="qinjx"
greeting="hello, "$your_name" !"
greeting_1="hello, ${your_name} !"

echo $greeting $greeting_1
```

* 获取字符串长度

```shell
string="abcd"
echo ${#string} #输出4
```

* 提取子字符串

```shell
string="alibaba is a great company"
echo ${string:1:4} #输出 liba
```

* 查找子字符串

```shell
string="alibaba is a great company"
echo `expr index "$string" is`
```



####　数组

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-34-13%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

#### 数组操作

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-34-45%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

![](linux3.14%E7%AC%94%E8%AE%B0.assets/2020-03-12%2021-35-16%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

* 读取数组

读取数组元素值的一般格式是：

```shell
    ${array_name[index]}
```

使用@或*可以获取数组中的所有元素，例如：

```shell
${array_name[*]}
${array_name[@]}
```

* 获取数组的长度

获取数组长度的方法与获取字符串长度的方法相同，例如：

```shell
# 取得数组元素的个数
length=${#array_name[@]}
# 或者
length=${#array_name[*]}
# 取得数组单个元素的长度
lengthn=${#array_name[n]}
```

# 命令系统



#### man手册使用

```
man ls
man ssh
```

在man中，常见的几个数字含义：

| 代号 | 代表的含义                                     | 举例               |
| ---- | ---------------------------------------------- | ------------------ |
| １   | 用户在shell环境下可以操作的命令或可执行文件    | `man 1 ls`         |
| ２   | 系统内核可以调用的函数和工具                   | `man 2 reboot`     |
| ３   | 一些常用的函数和函数库，大部分ｃ的函数库       | `man 3 readdir`    |
| ４   | 设备文件的说明，通常实在`/dev`下的设备         | `man 4 null`       |
| ５   | 配置文件或某些文件格式                         | `man 5 interfaces` |
| ６   | 游戏                                           | `man 6 lol`        |
| ７   | 惯例与协议等，例如`linux` 文件系统，网络协议等 | `man 7 tcp`        |
| ８   | 系统管理员可用的命令                           | `man 8 reboot`     |
| ９   | 跟kernel有用的文件                             |                    |

#### shell通配符

* ?

  代表单个任意字符, 就是.cpp什么的前面是单个字符的

  几个？代表几个字符的文件

```bash
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls
8.cpp 19.cpp 20.cpp
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls ?.cpp
8.cpp
```

* *

  代表任意几个字符

 ```bash
 fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls
 fangsong@fangsong-FX503VD:~/Mycode/2.f$ ls *.cpp
 8.cpp  19.cpp 20.cpp
 ```

* `[list]`匹配list中的任意单一字符

* `[!list]`匹配除list中的任意单一字符
* `[c1-c2]`匹配`c1-c2`中的任意单一字符

* `{string,string2,...}`匹配`string`或其中一个字符串

#### Shell任务控制
1.`&`
在命令的后面加上`&`表示后台执行的意思
```
command &
```
2.`;`
在命令之间用`;`项链，表示顺序执行的意思
```
command1 ;command2
```
3.`&&`
命令之间以`&&`相连时，只有前一个命令成功执行则执行第二个命令
```
command1 && command2
```
4.`||`
命令之间以`||`相连时，如果前一个命令执行失败，则执行第二个命令
```
command1 || command2
```
5.``
命令中如果包含另一个命令，则用符号｀｀将它包起来，优先执行｀｀中的子命令，然后将其结果代入父命令继续执行
```shell
command1 ` command2`
```
6.`ctrl + z`
暂时挂起
7.`bg`
挂起的命令后台执行
8.`fg`
后台执行的命令前台执行
9.`jobs`
查看后台所有挂起的任务及编号

```shell
fangsong@fangsong-FX503VD:~$ ping baidu.com
PING baidu.com (39.156.69.79) 56(84) bytes of data.
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=1 ttl=51 time=20.6 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=2 ttl=51 time=22.4 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=3 ttl=51 time=21.9 ms
^Z
[1]+  已停止               ping baidu.com
fangsong@fangsong-FX503VD:~$ jobs
[1]+  已停止               ping baidu.com
fangsong@fangsong-FX503VD:~$ fg
ping baidu.com
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=4 ttl=51 time=21.7 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=5 ttl=51 time=21.9 ms
64 bytes from 39.156.69.79 (39.156.69.79): icmp_seq=6 ttl=51 time=21.6 ms
^C
--- baidu.com ping statistics ---
6 packets transmitted, 6 received, 0% packet loss, time 360ms
rtt min/avg/max/mdev = 20.600/21.683/22.444/0.584 ms
```

#### 管道，重定向

管道｜

1.`>`
重定向符
2.`>>`
作用与>基本相同，不同的是>>将内容追加到文件的末尾，而>内容覆盖原文件
3.`<`
与>相反，是从文件到命令的重定向。他讲文件的内容输出到命令作为输入
4.`<<`
？

```shell
Num=`cat /dev/urandom | head -n 10 | cksum | cut -d ' ' -f 1`
```

此处就是管道，将前面的输出作为输入给后面

```shell
fangsong@fangsong-FX503VD:~/Mycode/2.f$ ./a.out < in.txt
```

```shell
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat > a.log <<EOF
> fs
> EOF
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat a.log
fs
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat >> a.log <<EOF
> fangsong
> EOF
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat a.log
fs
fangsong
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat > a.log <<EOF #EOF结束标志
> 0
> EOF #也可以换成其他的东西XXX
fangsong@fangsong-FX503VD:~/Mycode/2.f$ cat a.log
0
fangsong@fangsong-FX503VD:~/Mycode/2.f$ 
```

# 系统信息的获取

#### 系统信息

>uptime 打印系统运行时长和平均负载
>
>who显示当前登录系统用户信息
>
>last显示用户最近登录用户信息
>
>date显示或设置系统时间与日期
>
>w当前登录用户列表及正在执行的任务
>
>whoami打印当前有效的用户名称
>
>uname打印当前系统信息
>
>cal显示日历

#### uptime

```shell
fangsong@fangsong-FX503VD:~$ uptime
 08:26:41 up 11 min,  1 user,  load average: 0.75, 1.41, 0.97
```

#### w

```
-h :不打印头信息
-s :是hi用端输出格式
-f :切换FROM项
```

```shell
fangsong@fangsong-FX503VD:~$ w
 08:28:23 up 12 min,  1 user,  load average: 0.86, 1.27, 0.97
USER     TTY      来自           LOGIN@   IDLE   JCPU   PCPU WHAT
fangsong :0       :0               08:17   ?xdm?   1:46   0.01s /usr/lib/gdm3/g
fangsong@fangsong-FX503VD:~$ w -h
fangsong :0       :0               08:17   ?xdm?   1:49   0.01s /usr/lib/gdm3/g
fangsong@fangsong-FX503VD:~$ w -s
 08:28:39 up 13 min,  1 user,  load average: 0.75, 1.23, 0.96
USER     TTY      来自            空闲等待
fangsong :0       :0               ?xdm?  /usr/lib/gdm3/gdm-x-session --run-s
fangsong@fangsong-FX503VD:~$ w -f
 08:28:48 up 13 min,  1 user,  load average: 0.63, 1.19, 0.95
USER     TTY        LOGIN@   IDLE   JCPU   PCPU WHAT
fangsong :0        08:17   ?xdm?   1:49   0.01s /usr/lib/gdm3/gdm-x-session --r
fangsong@fangsong-FX503VD:~$ 

```

| USER       | TTY                  | FROM       | LOGIN@   | IDLE     | JCPU                                                   | PCPU             | WHAT                     |
| ---------- | -------------------- | ---------- | -------- | -------- | ------------------------------------------------------ | ---------------- | ------------------------ |
| 登录用户名 | 登录后系统分配的端号 | 登录主机名 | 登录时间 | 空闲时间 | 和终端相连的所有进程所占用时间，当前正在执行的后台作业 | 当前进程占用时间 | 当前进程正在执行的的命令 |

#### who

```shell
fangsong@fangsong-FX503VD:~$ who -H #显示各栏标题新系列
名称   线路       时间           备注
fangsong :0           2020-03-15 08:17 (:0)
fangsong@fangsong-FX503VD:~$ who -q#登录用户总人数
fangsong
# 用户数=1
fangsong@fangsong-FX503VD:~$ who -a
           系统引导 2020-03-15 08:15
           运行级别 5 2020-03-15 08:16
fangsong ? :0           2020-03-15 08:17   ?          1763 (:0)
fangsong@fangsong-FX503VD:~$ who -u#显示空闲时间
fangsong :0           2020-03-15 08:17   ?          1763 (:0)

```

#### LAST

显示用户最近登录用户信息

```shell
fangsong@fangsong-FX503VD:~$ last -n 5#指定输出记录数
fangsong :0           :0               Sun Mar 15 08:17   still logged in
reboot   system boot  5.0.0-38-generic Sun Mar 15 08:15   still running
fangsong :0           :0               Sat Mar 14 10:08 - down   (13:37)
reboot   system boot  5.0.0-38-generic Sat Mar 14 10:06 - 23:45  (13:38)
fangsong :0           :0               Fri Mar 13 16:55 - 00:41  (07:45)

wtmp begins Mon Nov 25 15:04:07 2019

```

#### uname

```shell
fangsong@fangsong-FX503VD:~$ uname -a#全部信息
Linux fangsong-FX503VD 5.0.0-38-generic #41-Ubuntu SMP Tue Dec 3 00:27:35 UTC 2019 x86_64 x86_64 x86_64 GNU/Linux
fangsong@fangsong-FX503VD:~$ uname -m#电脑类型
x86_64
fangsong@fangsong-FX503VD:~$ uname -n#网络上主机的名称
fangsong-FX503VD
fangsong@fangsong-FX503VD:~$ uname -v#os版本
#41-Ubuntu SMP Tue Dec 3 00:27:35 UTC 2019
fangsong@fangsong-FX503VD:~$ uname -p#处理器类型
x86_64
fangsong@fangsong-FX503VD:~$ uname -i#硬件
x86_64
fangsong@fangsong-FX503VD:~$ uname -o#操作系统名称
GNU/Linux
```

#### date

ntp协议：标准的时间

```shell
fangsong@fangsong-FX503VD:~$ date
2020年 03月 15日 星期日 08:43:00 CST
fangsong@fangsong-FX503VD:~$ date +%s
1584232994
fangsong@fangsong-FX503VD:~$ date +%S
22
fangsong@fangsong-FX503VD:~$ date +%T
08:43:31
fangsong@fangsong-FX503VD:~$ date +%H+%M+%S
08+43+55
```

# 基本系统



#### 目录结构

![2020-03-15 09-33-20屏幕截图.png](https://github.com/fangsong0517/Figure-bed/blob/master/2020-03-15%2009-33-20%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png?raw=true)
![2020-03-15 09-43-10屏幕截图.png](https://github.com/fangsong0517/Figure-bed/blob/master/2020-03-15%2009-43-10%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png?raw=true)
![2020-03-15 09-43-36屏幕截图.png](https://github.com/fangsong0517/Figure-bed/blob/master/2020-03-15%2009-43-36%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png?raw=true)

# 文件与目录操作



#### CD切换工作目录

```shell
cd /etc #直接切换到/etc目录
cd .. #切换到上层目录
cd . #切换到当前目录
cd #回到自己的家目录
cd ~#回到自己的家目录
cd -#回到上次的工作目录
```

#### PWD

```shell
L 显示逻辑工作目录
P 显示物理工作目录
```

#### MkDIR创建目录

```shell
-p 自动创建父目录
-m 设置权限
```

#### RMDIR删除目录

```shell
p删除祖先
```

#### CP

```shell
-i :若文件存在，询问用户
-r :递归赋值
-a ：pdr的集合
-p: 连同文件属性一起复制
-d:若源文件为链接文件的属性，则赋值链接文件的属性
-s:拷贝为软连接
-l:拷贝为硬链接
-u：原文件比目的文件新才拷贝
```

#### RM

```shell
-i :互动模式
-r :递归删除
-f：force
```

#### MV

```shell
-i :互动模式
-f：force
-u:源文件跟新才会移动
```

#### CAT

```shell
-A:相当于-VET
-v:列出看不到的字符
-E:显示断行符为￥
-T：显示TAB为^I
-b:列出行号
-n:列出行号，空行也编号
```

#### NL输出行号显示文件

```shell
-b a:相当于cat -a
-b t:相当于cat -b
-n ln:行号在屏幕的最左边显示
-n rn:行号在自己字段的最右边显示
-n rz:行号在自己字段的最右边显示，前面自动补0
-w <num>：行号所占位数
```

#### HEAD查看头几行

```shell
head [-n num] <file>
-n num:显示前几行
-n -num:除后几行外，其他都显示
```

#### TAIL查看末尾几行

```shell
tail [-n num] <file>
-n num:显示文件后num行
-n +num:除前几行外，其他都显示
```

#### TAIL查看末尾几行

```shell
tail [-n num] <file>
-n num:显示文件后num行
-n +num:除前几行外，其他都显示
```

#### 文件时间及隐藏属性

> 文件的三个时间
>
> >mtime :内容数据改动时才更新这个时间
> >
> >ctime:文件的权限，文件改动更新这个时间
> >
> >atime:文件的内容被取用access时，更新这个时间

```shell
ls -l --time=ctime /etc/hostname
```

ls -l #是行列表形式
--time=ctime# 显示这个时间为ctime, --后面通常加原型
每个文件都有这三种属性

#### 修改文件时间与新建文件

>touch [-acdmt] <file>
>
>>-a:仅修改访问时间
>>-c:金修改文件的时间，若文件不存在，不新建
>>-d:修改文件日期
>>-m:金修改mtime
>>-t:修改文件时间[yymmddhhmm]

#### 文件隐藏属性

>chattr [+-=] [ASacdistu] <file_or_dir>
>
>A:不修改atime 
>S:同步写入 //不缓存直接写到磁盘上，例如银行
>a:只能增加数据　//通常用在日志上
>c:自动压缩，解压 
>d:不会被dump程序备份
>i:不能删除修改建立连接 //写死了
>s:文件删除时，直接从磁盘删除
>u:文件删除时，文件内容存在磁盘中

#### 文件的特殊权限

> set_uid    s占位符       作用二进制程序文件，费脚本　　　　　用户在执行该程序时获取程序所有者权限
> set_git　s占位符        目录和二进制文件　　　　　　　　　　用户在该目录下，有效组变为目录所属组
> sticky Bit　t占位符　　目录　　　　　　　　　再改目录下，用户只能删除自己穿就爱你的内容

 

# 文件与目录操作、实现ls命令

#### 如何在Linux中查找文件

| 命令   | 功能                 | 命令    | 功能           |
| ------ | -------------------- | ------- | -------------- |
| which  | 寻找可执行文件       | whereis | 寻找特定文件   |
| locate | 搜索文件(可部分查找) | find    | 多样化高级查找 |

* which寻找可执行文件

```shell
fangsong@fangsong-FX503VD:~$ ls -a `which ping`
/usr/bin/ping
```

* whereis寻找特定文件

  -b:查找二进制文件

  -m:查找man手册

  -s:查找source源文件

```shell
fangsong@fangsong-FX503VD:~$ whereis ping
ping: /usr/bin/ping /usr/share/man/man8/ping.8.gz
```

* locate模糊定义

  -i:忽略大小写

  -r:后面可接正则表达式

```shell
fangsong@fangsong-FX503VD:~$ locate prime.cpp
/home/fangsong/Mycode/1.c语言/4/1.prime.cpp
/home/fangsong/Mycode/2.EP/prime.cpp
/home/fangsong/Mycode/2.f/prime.cpp
```

* find高级查找

  find [path] [option] [action]

  与时间相关的参数：-atime -ctime -mtime

  -mtime n : ｎ天前的"一天之内"修改的文件 amin

  -mtime +n: n天之前，不包含ｎ，修改过的文件

  -mtime -n:ｎ天之内，包含ｎ，修改过的文件

  -newer file:比file 还要新的文件

  与用户或者用户组相关的参数：

  -uid n:用户UID为ｎ

  -gid n:群组GID为ｎ

  -user name:用户名为name

  -group name:群组名为name

  nouser:文件所有者不存在

  nogroup:文件所有组不存在

  与文件权限名称有关的参数：

  -name filename: 文件名为filrname

  -size [+-] SIZE:查找比SIZE大或小的

  -type TYPE：f b c d l s p

  -perm mode : mode 刚好等于的文件

  -perm -mode: 全部包含mode的文件

```shell
find -exec ls -l {} \;

find . -name "*.cpp" -mtime -1 -exec wc -l {} \ #一天前.cpp文件的统计行数
```

查找家目录下所有.cpp,.c,.sh,.h的行数总和

```shell
find ~ -name "*.cpp" -o -name "*.c" -o -name "*.h" -o -name "*.sh" | xargs wc -l
```





#### 实现ls需要用到的函数

##### opendir()

**头文件**
　　#include<sys/types.h>
　　#include<dirent.h>
**函数原型**
　　DIR* opendir (const char * path ); （获取path子目录下的所由文件和目录的列表，如果path是个文件则返回值为NULL）
**功能**
　　<font color= red>打开一个目录，在失败的时候返回一个空的指针。</font>
**返回值(DIR)**
       DIR 结构体的原型为：struct_dirstream
       在Linux系统中：

```c
 typedef struct __dirstream DIR;

       struct __dirstream
       {
         void *__fd; /* `struct hurd_fd' pointer for descriptor.   */
         char *__data; /* Directory block.   */
         int __entry_data; /* Entry number `__data' corresponds to.   */
         char *__ptr; /* Current pointer into the block.   */
         int __entry_ptr; /* Entry number `__ptr' corresponds to.   */
         size_t __allocation; /* Space allocated for the block.   */
         size_t __size; /* Total valid data in the block.   */
         __libc_lock_define (, __lock) /* Mutex lock for this structure.   */
        };
```

##### readdir()

**头文件**
#include<dirent.h>
**函数原型**
struct dirent* readdir(DIR* dir_handle); （个人理解循环读取dir_handle,目录和文件都读）
**功能**
<font color = red>读取opendir 返回值的那个列表</font>
**返回值**
返回dirent结构体指针，dirent结构体成员如下，（文件和目录都行）

```c
struct dirent
　　{
　　long d_ino; /* inode number 索引节点号 */
　　off_t d_off; /* offset to this dirent 在目录文件中的偏移 */
　　unsigned short d_reclen; /* length of this d_name 文件名长 */
　　unsigned char d_type; /* the type of d_name 文件类型 */
　　char d_name [NAME_MAX+1]; /* file name (null-terminated) 文件名，最长255字符 */
　　}
```

##### perror()

<font color = red>将上一个函数发生错误的原因输出</font>

##### closedir()

```c
#include<sys/types.h>
#include<dirent.h>
int closedir(DIR *dir);
```

​     closedir()关闭参数dir所指的目录流。关闭成功则返回0，失败返回-1，错误原因存于errno 中。EBADF 参数dir为无效的目录流。注意：目录文件作为一种文件，再打开必须关闭，否则会由于文件的进程打开文件过多而不能打开新的文件。因此opendir函数和closedir函数同样是配对出现的

##### stat函数

 作用：<font color = red>获取文件信息</font>

 头文件：include <sys/types.h> #include <sys/stat.h> #include <unistd.h>

 函数原型：```int stat(const char *path, struct stat *buf)```

 返回值：成功返回0，失败返回-1；

 参数：文件路径（名），struct stat 类型的结构体

struct stat 结构体详解：

```c
struct stat
{
    dev_t     st_dev;     /* ID of device containing file */文件使用的设备号
    ino_t     st_ino;     /* inode number */    索引节点号 
    mode_t    st_mode;    /* protection */  文件对应的模式，文件，目录等
    nlink_t   st_nlink;   /* number of hard links */    文件的硬连接数  
    uid_t     st_uid;     /* user ID of owner */    所有者用户识别号
    gid_t     st_gid;     /* group ID of owner */   组识别号  
    dev_t     st_rdev;    /* device ID (if special file) */ 设备文件的设备号
    off_t     st_size;    /* total size, in bytes */ 以字节为单位的文件容量   
    blksize_t st_blksize; /* blocksize for file system I/O */ 包含该文件的磁盘块的大小   
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */ 该文件所占的磁盘块  
    time_t    st_atime;   /* time of last access */ 最后一次访问该文件的时间   
    time_t    st_mtime;   /* time of last modification */ /最后一次修改该文件的时间   
    time_t    st_ctime;   /* time of last status change */ 最后一次改变该文件状态的时间   
};
```


stat结构体中的st_mode 则定义了下列数种情况：

    S_IFMT   0170000    文件类型的位遮罩
    S_IFSOCK 0140000    套接字
    S_IFLNK 0120000     符号连接
    S_IFREG 0100000     一般文件
    S_IFBLK 0060000     区块装置
    S_IFDIR 0040000     目录
    S_IFCHR 0020000     字符装置
    S_IFIFO 0010000     先进先出
    
    S_ISUID 04000     文件的(set user-id on execution)位
    S_ISGID 02000     文件的(set group-id on execution)位
    S_ISVTX 01000     文件的sticky位
    
    S_IRUSR(S_IREAD) 00400     文件所有者具可读取权限
    S_IWUSR(S_IWRITE)00200     文件所有者具可写入权限
    S_IXUSR(S_IEXEC) 00100     文件所有者具可执行权限
    
    S_IRGRP 00040             用户组具可读取权限
    S_IWGRP 00020             用户组具可写入权限
    S_IXGRP 00010             用户组具可执行权限
    
    S_IROTH 00004             其他用户具可读取权限
    S_IWOTH 00002             其他用户具可写入权限
    S_IXOTH 00001             其他用户具可执行权限
    
    上述的文件类型在POSIX中定义了检查这些类型的宏定义：
    S_ISLNK (st_mode)    判断是否为符号连接
    S_ISREG (st_mode)    是否为一般文件
    S_ISDIR (st_mode)    是否为目录
    S_ISCHR (st_mode)    是否为字符装置文件
    S_ISBLK (s3e)        是否为先进先出
    S_ISSOCK (st_mode)   是否为socket
    若一目录具有sticky位(S_ISVTX)，则表示在此目录下的文件只能被该文件所有者、此目录所有者或root来删除或改名，在linux中，最典型的就是这个/tmp目录啦。

st_mode 的结构

st_mode 主要包含了 3 部分信息：

15-12 位保存文件类型

11-9 位保存执行文件时设置的信息

8-0 位保存文件访问权限

##### getpwuid()

头文件：#include <sys/types.h>  #include <pwd.h>

getpwuid函数是通过用户的uid查找用户的passwd数据。如果出错时，它们都返回一个空[指针](https://baike.baidu.com/item/指针/2878304)并设置errno的值，用户可以根据perror函数查看出错的信息。

函数说明

<font color =red>查找用户的passwd数据</font>

```c
和系统数据相关的passwd 结构 
和系统数据相关的一个结构passwd定义如下 
/* The passwd structure.      */ 
struct passwd 
{ 
      char *pw_name;       /* 用户名*/ 
      char *pw_passwd;     /* 密码.*/ 
      __uid_t pw_uid;      /* 用户ID.*/ 
      __gid_t pw_gid;      /*组ID.*/ 
      char *pw_gecos;      /*真实名*/ 
      char *pw_dir;        /* 主目录.*/ 
      char *pw_shell;      /*使用的shell*/ 
}; 

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <pwd.h> 
int main (void) 
{ 
       struct passwd *passwd; 
       passwd=getpwuid(getuid()); 
       /** passwd=getcwnam("phpos"); **/ 
       printf("Username:%s/n",passwd->pw_name); 
       printf("Password:%s/n",passwd->pw_passwd); 
       printf("uid:%d/n",passwd->pw_uid); 
       printf("gid:%d/n",passwd->pw_gid); 
       printf("shell:%s/n",passwd->pw_shell); 
       printf("dir:%s/n",passwd->pw_dir); 
       return 0; 
} 
```

##### getgrgid()

**C语言getgrgid()函数：从组文件中取得指定gid的数据**

头文件：

```
#include <grp.h>  #include <sys/types.h>
```

定义函数：

```
strcut group * getgrgid(gid_t gid);
```

函数说明：getgrgid()用来依参数gid 指定的组识别码逐一搜索组文件, 找到时便将该组的数据以group 结构返回. 返回值：返回 group 结构数据, 如果返回NULL 则表示已无数据, 或有错误发生.

通过gid,找到该组的相关信息,并以group结构体返回其信息, 头文件:#include <grp.h>,#include <sys/types.h> 参数     文件所属组的组id; 返回值:成功返回group结构体,错误返回NULL; group结构体: struct group { char *gr_name; /*组名称*/ char *gr_passwd; /* 组密码*/ gid_t gr_gid; /*组识别码*/ char **gr_mem; /*组成员账号*/ } 看个例子:

范例

```
/* 取得gid＝3 的组数据 */
#include <grp.h>
#include <sys/types.h>
main()
{
  strcut group *data;
  int i = 0;
  data = getgrgid(3);
  printf("%s:%s:%d:", data->gr_name, data->gr_passwd, data->gr_gid);
    while(data->gr_mem[i])
    printf("%s, ", data->mem[i++]);
    printf("\n");
}
```

```c
    struct passwd  
    {  
        char * pw_name; /* Username, POSIX.1 */  
        char * pw_passwd; /* Password */  
        __uid_t pw_uid; /* User ID, POSIX.1 */  
        __gid_t pw_gid; /* Group ID, POSIX.1 */  
        char * pw_gecos; /* Real Name or Comment field */  
        char * pw_dir; /* Home directory, POSIX.1 */  
        char * pw_shell; /* Shell Program, POSIX.1 */  
    };  

    struct group
    {
        char *gr_name;  /* Group name */
        char *gr_passwd;  /* password */
        __gid_t gr_gid;  /* Group ID */
        char **gr_mem;  /* Member list */
    }
    #endif//0
```













# 数据提取操作

* 数据提取操作

| 命令  | 说明         | 命令  | 说明             |
| ----- | ------------ | ----- | ---------------- |
| cut   | 切分         | grep  | 检索             |
| sort  | 排序         | wc    | 统计字符字数行数 |
| uniq  | 去重         | tee   | 双重导向         |
| split | 文件切分     | xargs | 参数代换         |
| tr    | 替换压缩删除 |       |                  |

* cut切分
  cut [-dfc] <file>
  -d c:以字符分割
  -f num：显示ｎｕｍ字段内容【ｎ- ;n - m; -m】
  -c num: 字节
  -b num: 字符

* grep检索
  grep [-acinv] <string> <file>
  -a: 将二进制文件以普通文件形式搜寻数据
  -c : 统计搜寻到的次数
  -i：忽略大小写
  -n：顺序输出行号
  -v：反向输出（输出没找到的）

* sort排序

  sort [-fnMnrtuk] <file_or_stdio>

  -f:忽略大小写

  -b:忽略最前面的空格符

  -M:以月份名称排序

  -n:以纯数字方式排序

  -r:反向排序

  -u:uniq

  -t:分隔符，默认[TAB]

  -k:以那个区间排序

  

* wc统计字符字数，行数

  wc [-lwm] <file_or_stdin>

  -l: 仅列出行号

  -w:仅列出多少字

  -m:仅列出多少字符

* uniq去重

  uniq [-ic]

  -i :忽略大小写字符的不同

  -c:进行计数

* split文件切分

  split [-bl] <file> PREFIX

  -b SIZE: 切分为ＳＩＺＥ大小的文件

  -l ｎｕｍ：以ｎｕｍ行为大小切

```shell
ls /etc | splist -l 10  
```

* xargs参数xargs替换

  -0：将特殊字符还原为普通字符

  -eEOF:当xargs读到ＥＯＦ时停止

  -p:执行指令前询问

  -n num:每次执行command时需要的参数个数

```shell
cat /etc/passwd | cut -d ":" -f 1 | xargs -n 1 -efangsong id
```

* tr替换压缩删除  

  tr [cdst] <字符集>　<字符集>

  c 取代所有不属于第一字符集的字符

  d 删除所有属于第一字符集的字符

  s 将连续重复的字符以单独一个字符表示

  t 先删除第一字符集比第二字符集字符集多的字符

```shell
 cat fangsong | tr [0-9] [a-z]
 cat fangsong | tr -d [0-9]
 cat fangsong | tr -s [a-z]
 cat fangsong | tr -t [0-9] [a-z]

 文件夹下文件名大写变小写
ls | tr [a - z] [A  - Z]
for i in `ls`; do
>mv $i `echo $i` | tr [a-z] [A-Z]
>done
```

如何统计文件中单词的个数，逆序输出

```shell
 cat fangsong | tr -s -c [a-z] ' ' | tr ' ' '\n' | sort | uniq -c | sort -n -r | head -n 20
 先把不是字符的去掉，然后把空格替换为'\n',然后排序去重然后逆序输出前二十行
```



