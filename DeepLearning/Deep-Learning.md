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