   * 
   * [Deep-Learning](#deep-learning)
      * [1. 从数据挖掘到人工智能](#1-从数据挖掘到人工智能)
         * [1.1 人工智能萌芽与生长](#11-人工智能萌芽与生长)
            * [1.1.1 计算机翻译系统的进化](#111-计算机翻译系统的进化)
            * [1.1.2 人工智能医学专家系统](#112-人工智能医学专家系统)
            * [1.1.3 人工智能医学机器学习系统](#113-人工智能医学机器学习系统)
         * [1.2 数据驱动的人工智能](#12-数据驱动的人工智能)
            * [1.2.1 Volume](#121-volume)
            * [1.2.2 Variety](#122-variety)
            * [1.2.3 Value](#123-value)
            * [1.2.4 Velocity](#124-velocity)
            * [1.2.5 计算硬件的告诉演进](#125-计算硬件的告诉演进)
            * [1.2.6 计算系统的并行化](#126-计算系统的并行化)
      * [2.人工智能能做什么](#2人工智能能做什么)
         * [2.1 典型的数据挖掘问题](#21-典型的数据挖掘问题)
            * [2.1.2 拟合](#212-拟合)
            * [2.1.2 分类](#212-分类)
            * [2.1.3 聚类](#213-聚类)
            * [2.1.4 异常检测](#214-异常检测)
         * [2.2 复杂的人工智能问题](#22-复杂的人工智能问题)
      * [3. 深度学习的普遍应用](#3-深度学习的普遍应用)
         * [3.1 人工智能的茁壮成长](#31-人工智能的茁壮成长)
            * [3.1.1 从人工神经元到深度神经网络](#311-从人工神经元到深度神经网络)
            * [3.1.2为什么要学习深度学习?](#312为什么要学习深度学习)
         * [3.2 深度学习正在驱动时代的发展](#32-深度学习正在驱动时代的发展)
         * [3.3 深度学习正在改变我们的生活方式](#33-深度学习正在改变我们的生活方式)
         * [3.4 深度学习是强大的医学人工智能](#34-深度学习是强大的医学人工智能)
         * [3.5 病例人工智能的图灵测试](#35-病例人工智能的图灵测试)

# Deep-Learning

`Deep Learning and TensorFlow`

`TensorFlow`™是一个基于[数据流编程](https://baike.baidu.com/item/数据流编程/22735640)（`dataflow` programming）的符号数学系统，被广泛应用于各类[机器学习](https://baike.baidu.com/item/机器学习/217599)（machine learning）算法的编程实现，其前身是[谷歌](https://baike.baidu.com/item/谷歌/117920)的神经网络算法库`DistBelief`

![image-20200726140841818](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726140841818.png)`AUC`（Area Under Curve）被定义为[ROC曲线](https://baike.baidu.com/item/ROC曲线)下与坐标轴围成的面积，显然这个面积的数值不会大于1。又由于`ROC`曲线一般都处于y=x这条直线的上方，所以`AUC`的取值范围在0.5和1之间。`AUC`越接近1.0，检测方法真实性越高;等于0.5时，则真实性最低，无应用价值。



![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/13291551-cf985efcac032cc1.png)![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/13291551-4f0b788202ec8d1a.png)

![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/13291551-ed00385f21ddf3f6.png)

## 1. 从数据挖掘到人工智能

### 1.1 人工智能萌芽与生长

![image-20200726142209999](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726142209999.png)

#### 1.1.1 计算机翻译系统的进化

![image-20200726143241950](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726143241950.png)

#### 1.1.2 人工智能医学专家系统

![image-20200726143813995](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726143813995.png)

#### 1.1.3 人工智能医学机器学习系统

![image-20200726143910610](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726143910610.png)

### 1.2 数据驱动的人工智能

![image-20200726144229891](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144229891.png)

#### 1.2.1 Volume

![image-20200726144406007](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144406007.png)

#### 1.2.2 Variety

![image-20200726144547209](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144547209.png)

#### 1.2.3 Value

![image-20200726144627399](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144627399.png)

####  1.2.4 Velocity

![image-20200726144709748](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144709748.png)

#### 1.2.5 计算硬件的告诉演进

![image-20200726144757543](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726144757543.png)

#### 1.2.6 计算系统的并行化

数据中心

![image-20200726145040514](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145040514.png)

## 2.人工智能能做什么

### 2.1 典型的数据挖掘问题

* 拟合-Regression
* 分类-Classification
* 聚类-Clustering
* 异常检测-Anomaly Detection

#### 2.1.2 拟合

![image-20200726145513535](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145513535.png)

![image-20200726150336307](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150336307.png)

#### 2.1.2 分类

![image-20200726145547054](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145547054.png)

![image-20200726150320647](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150320647.png)

#### 2.1.3 聚类

![image-20200726145720206](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145720206.png)

#### 2.1.4 异常检测

![image-20200726145818575](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726145818575.png)

![image-20200726150303847](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150303847.png)

### 2.2 复杂的人工智能问题

![image-20200726150236110](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150236110.png)

## 3. 深度学习的普遍应用

### 3.1 人工智能的茁壮成长

![image-20200726150509680](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150509680.png)

#### 3.1.1 从人工神经元到深度神经网络

![image-20200726150655987](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150655987.png)

#### 3.1.2为什么要学习深度学习?

![image-20200726150945184](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726150945184.png)

### 3.2 深度学习正在驱动时代的发展

![image-20200726151120694](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151120694.png)

### 3.3 深度学习正在改变我们的生活方式

![image-20200726151538590](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151538590.png)

![image-20200726151550630](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151550630.png)

### 3.4 深度学习是强大的医学人工智能

![image-20200726151637205](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151637205.png)

### 3.5 病例人工智能的图灵测试

![image-20200726151727945](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726151727945.png)

左边是机器。右边是人画出来的





## tensorflow基本概念

### Tensor and Varibale

![image-20200728124412119](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728124412926.png)

```python
import tensorflow as tf
z = tf.add(3, 4)
print(z)
sess = tf.Session()
print(sess)
result = sess.run(z)
print(result)
```

![image-20200728124828195](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728124828195.png)

### Graph and Session

#### Graph

![image-20200728125043832](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728125043832.png)

#### Session

![image-20200728125249011](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728125249011.png)

```python
a = tf.constant(3)
b = tf.constant(4)
z = tf.add(a, b)
print(z)
import tensorflow as tf
with tf.Session() as sess:
    writer = tf.summary.FileWriter('./graphs', sess.graph)
    print(sess)
    result = sess.run(z)
    print(result)
    writer.close
```

>tensorboard --logdir=./graphs --port=8008

#### TensorBoard

![image-20200728131648074](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728131648074.png)

![image-20200728131630528](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728131630528.png)

![image-20200728131712094](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200728131712094.png)

![image-20200802141537746](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802141537746.png)





两个向量a = [a1, a2,…, an]和b = [b1, b2,…, bn]的点积定义为：

a·b=a1b1+a2b2+……+anbn。

```c++
#!/usr/bin/env python
# coding=utf-8
import tensorflow as tf
print(tf.__version__)
import numpy as np

tf.reset_default_graph()
x = tf.placeholder(tf.float32, None)#[None, 1000]
y = tf.placeholder(tf.float32, None)#[None, 1000]
z = tf.add(x, y)

o = x * y
print(o)

with tf.Session() as sess:
    writer = tf.summary.FileWriter('./graphs/',sess.graph)
    print(sess.run([z, o], feed_dict={x : np.array([1.0, 2.0]), y : np.array([3.0, 4.0])}))
    writer.close()

```

![image-20200802143842287](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802143842287.png)

一个加法一个乘法

### 克罗内克积

数学上，**克罗内克积**是两个任意大小的矩阵间的运算。克罗内克积是[张量积](https://baike.baidu.com/item/张量积/7540845)的特殊形式，以德国数学家利奥波德·克罗内克命名。

![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/9a11ca04ce3305ddac60890565b4a87a.svg)

 如果*A*是一个*m*×*n*的矩阵，而*B*是一个*p*×*q*的矩阵，**克罗内克积**则是一个*mp*×*nq*的[分块矩阵](https://baike.baidu.com/item/分块矩阵)



![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ee5fe7b01d153a176997ba71b612920a.svg)





![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ea0ed842bbe8e34a6e80603b6434ece9.svg)



## 从拟合到深度神经网络

### 拟合与优化-寻找正解

![image-20200802144529147](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802144529147.png)

数学拟合，第二定律中`a = F / m`

#### **数学模型**

![image-20200802145057763](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802145057763.png)

当成本函数最小的时候为趋近０，所以yi = h(xi)![image-20200802145349480](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802145349480.png)

因此使用二次元方式来预测，

#### **梯度下降**

梯度下降是迭代法的一种,可以用于求解最小二乘问题(线性和非线性都可以)。在求解机器学习算法的模型参数，即无约束优化问题时，梯度下降（Gradient Descent）是最常采用的方法之一，另一种常用的方法是最小二乘法。在求解损失函数的最小值时，可以通过梯度下降法来一步步的迭代求解，得到最小化的损失函数和模型参数值。反过来，如果我们需要求解损失函数的最大值，这时就需要用梯度上升法来迭代了。在机器学习中，基于基本的梯度下降法发展了两种梯度下降方法，分别为随机梯度下降法和批量梯度下降法。

![image-20200802150528235](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802150528235.png)**梯度下降法(gradient descent)**是一个[最优化](https://baike.baidu.com/item/最优化)算法，常用于机器学习和[人工智能](https://baike.baidu.com/item/人工智能/9180)当中用来递归性地逼近最小偏差模型。

举一个非常简单的例子，如求函数

![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/d28f3598a7e36298452ecfe451a35ab5.svg)

 的最小值。

利用梯度下降的方法解题步骤如下：

1、求梯度，![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/8a81c05d8c450aadab9085e9ab71d281.svg)
2、向梯度相反的方向移动![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)，如下![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/771a2ba34fe23edd9669812df6c5d16e.svg)，其中，![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/74822649bb220e0bdde84e9532b80130.svg) 为步长。如果步长足够小，则可以保证每一次迭代都在减小，但可能导致收敛太慢，如果步长太大，则不能保证每一次迭代都减少，也不能保证收敛。

3、循环迭代步骤2，直到![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg) 的值变化到使得![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg)
在两次迭代之间的差值足够小，比如0.00000001，也就是说，直到两次迭代计算出来的![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg)基本没有变化，则说明此时![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg) 已经达到局部最小值了。
4、此时，输出![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)，这个![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)就是使得函数![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/ff00f7b7211e5b5454eccf5df11db931.svg)最小时的![img](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/4675185d7b4028ecceae6b1456352cd4.svg)的取值 。

#### **牛顿法**

![image-20200802151330296](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802151330296.png)

#### 动量的作用

![image-20200802151806253](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802151806253.png)



#### 用多少数据优化参数?

![image-20200802152821772](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802152821772.png)

![image-20200802153217774](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802153217774.png)

#### 学习速率的重要性

![image-20200802153834028](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802153834028.png)

![image-20200802154116159](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802154116159.png)



### 神经网络

#### 特征提取

![image-20200802163525078](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802163525078.png)

#### 神经元

![image-20200802163722940](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802163722940.png)

#### sigmoid和激活函数

![image-20200802164108623](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164108623.png)

#### ReLU

![image-20200802164207983](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164207983.png)

#### ReLU变种

![image-20200802164410721](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164410721.png)



#### 神经网络

![image-20200802164516539](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164516539.png)

![image-20200802164643407](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164643407.png)

![image-20200802164735315](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164735315.png)

#### 两种重要得神经网络

![image-20200802164943119](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802164943119.png)

#### 正则化的目的

![image-20200802165229494](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165229494.png)

#### 模型的容量

![image-20200802165350998](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165350998.png)

![image-20200802165625188](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165625188.png)

#### 修改成本函数

![image-20200802165700290](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165700290.png)

#### Early-Stopping

![image-20200802165819192](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165819192.png)

#### 参数共享

![image-20200802165846916](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802165846916.png)

#### 实战经验

![image-20200802170021995](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200802170021995.png)



### 第一个演示拟合代码

```python
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt 
%pylab inline

def plot_points(x, y, title_name):
    plt.title(title_name)#头标题
    plt.xlabel('x')#横坐标x
    plt.ylabel('y')#纵坐标y
    plt.scatter(x, y)#苗出点
    plt.show()#展示出来
    
def plot_line(w, b, title_name):
    plt.title(title_name)
    plt.xlabel('x')
    plt.ylabel('y')
    x = np.linspace(0.0, 2.0, num=100)
    y = w * x + b
    plt.plot(x, y)
    plt.show()
    
train_X = np.array([30.0, 40.0, 60.0, 80.0, 10.0, 120.0, 140.0])
train_Y = np.array([320.0, 360.0, 400.0, 455.0, 490.0, 560.0, 580.0])
train_X /= 100.0#缩放
train_Y /= 100.0
plot_points(train_X, train_Y, title_name = 'Training Points')#描绘

x = tf.placeholder(tf.float32, None)#x
y = tf.placeholder(tf.float32, None)#y
w = tf.Variable(np.random.randn(), name='weight')#随机的w, name方便找到
b = tf.Variable(np.random.randn(), name='bias')#随机的b
y_pred = tf.add(tf.multiply(w, x), b)#y = wx + b;
#---计算图已经完成---
#---优化---
n_samples = train_X.shape[0]#参考的个数n
cost = tf.reduce_sum(tf.pow((y_pred - y), 2)) / n_samples #成本函数
learning_rate = 0.01#优化器
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)#通过什么方法进行优化，通过minmize进行最小化cost成本

training_epoch = 1000#训练多少个epoch
display_step = 50#每隔多少算一次loss,ｂｕｃｈａｎｇ

with tf.Session() as sess:
    sess.run(tf.initialize_all_variables())#所有的参数初始化
    for epoch in range(training_epoch):
        for (x_train, y_train) in zip(train_X, train_Y):
            _, loss, current_w, current_b = sess.run([optimizer, cost, w, b], feed_dict={x: x_train, y: y_train})
        if epoch % display_step == 0:
            print('Iteration: %04d | Loss: %.6f | W:%.6f | b: %.6f'
                 %(epoch + 1, loss, current_w, current_b))
            plot_line(current_w, current_b, 'Model Paramenter')
    print('Training loss: %.6f | w: %.6f | b: %.6f' % (loss, sess.run(w), sess.run(b)))
```



