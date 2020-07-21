# C++程序设计

## 从C到C++

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggyrsf1rjnj30lh0aedhm.jpg)

c++学习重点在于理解程序的运行流程

**编程范式**

|              | C语言 | C++语言 |
| :----------: | :---: | :-----: |
| 面向过程编程 |  `√`  |   `√`   |
| 面向对象编程 |  `×`  |   `√`   |
|   泛型编程   |  `×`  |   `√`   |
|  函数式编程  |  `×`  |   `√`   |

1. 代码开发
2. 测试
3. 维护

### **queue-类说明**

1. 头文件:`queue`
2. 命名空间:`std`
3. 声明`queue<data_type>q;`
4. `q.front(), q.empty(),q.push(),q.pop(),q.size()`

### **stack-类说明**

1. `q.top(), q.empty(),q.push(),q.pop(),q.size()`

### **string-类说明**

1. 头文件:`string`

2. `s1==s2, s1 < s2, s1 += s2, s1.length()`

   C语言中`strlen(str)`时间复杂度为O(n)

   C++中`str.length()`时间复杂度为O(1) <sup>长度是被存好的，此处是直接访问</sup>

### **hash_map-类说明(非标准)**

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggysx0pxjjj30lu0a0jup.jpg)

### **unordered_map类说明(c++11标准)**

![image.png](http://ww1.sinaimg.cn/large/006Uqzbtly1ggyt9qe6oij30nk09u0wt.jpg)

`unordered_map非排序映射[映射表]`

`map排序映射[红黑树]`

