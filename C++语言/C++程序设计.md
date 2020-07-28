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

### set

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int main() {
    set<int>s;
    s.insert(345);
    s.insert(65);
    s.insert(9956);
    s.insert(9000);
    cout << s.size() << endl;
    s.insert(65);
    cout << s.size() << endl;
    cout << *(s.begin()) << endl;
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << *iter << endl;
    }
    s.erase(s.begin());
    cout << *(s.begin()) << endl;
    return 0;
}
```

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef pair<string, int>PSI;
int main() {
    ios::sync_with_stdio(false);
    set<PSI> s;
    string name;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> name;
        //name = name.substr(name.find(".") + 1, name.size());
        name.erase(0, 3);
        s.insert(PSI(name, i));
    }
    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << iter->first << endl;
    }
    return 0;
}
```

```cpp

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
int main() {
    int n,a, sum, t = 0;
    cin >> n;
    set<PII>s;
    for(int i = 0; i < n; i++) {
        cin >> a;
        s.insert(PII(a, t++));
    }
    for(int i = 0; i < n - 1; i++) {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        sum += a+ b;
        s.insert(PII(a + b, t++));
    }
    cout << sum << endl;
    return 0;
}
```

```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<queue>
#include<vector>
using namespace std;

struct my_int{
    int num;
    bool operator< (const my_int & b) const {
        return this->num > b.num;
    }
};

int main() {
    priority_queue<my_int> q;
   // priority_queue<int, vector<int>, greater<int> > q;
    int n, w;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> w;
        q.push((my_int){w});
    }
    int s1, s2;
    int sum = 0;
    for(int i = 1; i <= n - 1; i++) {
        s1 =(int)q.top().num;
        q.pop();
        s2 =(int)q.top().num;
        q.pop();
        q.push((my_int){s1 + s2});
        sum += s1 + s2;
    }
    cout << sum << endl;
    return 0;
}

```

## 类和对象

**类型 = 类型<font color = red>数据</font> + 类型<font color = green>操作</font>**

![image-20200725154924208](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200725154924208.png)

![img](https://github.com/jackfrued/Python-100-Days/raw/master/Day01-15/res/oop-zhihu.png)

### 访问权限

![image-20200725155708004](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200725155708004.png)

注：友元方法

学习C++重点：运行时的bug编程编译时的bug

### C语言与C++中struct

```cpp
//c语言//
//声明 
struct stu
{
    ...
};
//定义 
struct stu student;
```

```cpp
//c++//
//声明
struct stu
{
    ...
};
//定义
1.struct stu student;
2.stu student;
```

![image-20200726205745836](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726205745836.png)

```c++
class People{
    public:
    int x, y;
};

struct People2{
    int x, y;
};
```

如果想在c语言中直接用结构体名定义变量，需要用到 typedef 

```c++
//typedef的一般用法
typedef type new_type;
```

**特别的**当type为用户自定义类型时，type 和 new_type 可以相同。

用于结构体时 

```cpp
typedef struct stu
{
    ...
}Stu;
//定义
1.Stu student;
2.struct stu student;
```

### 第一个class小例子

```c++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;

class People{
    friend int main();//友元#隔壁老宋
    int x, y;
public :
    void set(int x);
    void say();
};

struct People2{
    int x, y;
};

void People::set(int x) {
    cout << "set functiona : " << this << endl;
    this->x = x;
    return;
}

void People::say() {
    cout << x << " " << y << endl;
    return;
}

int main() {
    People a;
    People2 b;
    a.y = 18432;//友元
    cout << "a pbject : " << &a << endl;
    a.set(3);
    b.x = 4;
    a.say();
    cout << b.x << endl;
    return 0;
}
```



## 封装

### 构造函数与析构函数

![image-20200726181013896](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726181013896.png)



```c++
class People {
public:
    People(){}
    People(string name) {//有参构造
        this->name = name;
    }
    /*People() { 默认构造函数
        arr = new int[10];
        cout << "default constructor" << endl;
    }*/
    ~People() {
        cout << "destructor" << endl;
    }
    string name;
    //int *arr;
};

int main() {
    People b("fangsong");
    People a = string("string");
    //a.arr[9] = 12
    cout << a.name << endl;
    return 0;
}
```

**拷贝构造为什么要用&**

![image-20200726185155194](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726185155194.png)

```c++
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class People {
public :
    People() {}
    //People() = default; //  //隐藏规则变为显示规则，易于代码维护
   //People() = delete;
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(int x) {
        cout << "int param constructor" << endl;
        this->x = x;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
        this->x = a.x;
    }
    
    void operator=(const People &a) {
        cout << "operator =" << endl;
        this->name = a.name;
        this->x = a.x;
        return ;
    }

    ~People() {
        cout << "destructor" << endl;
    }
    string name;
    int x;
};

void incr(int &a) {
    a += 1;
    return ;
}

int add(People a, People b) {
    return a.x + b.x;
}

int main() {
    int n = 7;
    incr(n);
    cout << n << endl;
    cout << add(4, 5) << endl;
    People a("hug");
    People b = string("hug");
    People c(543);
    People d = 678;
    cout << a.name << endl;
    cout << b.name << endl;
    cout << c.x << endl;
    cout << d.x << endl;
    c = 987;
    cout << c.x << endl;
    d = string("duanchenyang");
    cout << d.name << endl;
    People e = a;
    cout << e.name << endl;
    cout << e.x << endl;
    c = a;
    cout << c.name << endl;
    cout << c.x << endl;
    return 0;
}
```

### 类属性方法

static

![image-20200726193613579](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726193613579.png)

类属性与类方法中，类属性可以记录类对象的个数，类方法中不能访问this指针;

### CONST方法

![image-20200726194132004](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726194132004.png)

不去修改对象中的值

const类型对象只能调用const类型方法

### 类属性与const代码演示

```c++
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

class Point {
public :
    Point() {
        cout << "constructor : " << this << endl;
        Point::total_cnt += 1;
    }
    Point(const Point &a) : Point() {
        cout << "copy constructor : " << this << endl;
        this->x = a.x;
        this->y = a.y;
    }
    Point(double z) : Point() {
        cout << "convert constructor : " << this << endl;
        this->x = 99, this->y = 99;
    }
    Point(int x, int y) : Point() {
        cout << "param constructor : " << this << endl;
        this->x = x;
        this->y = y;
    }

    void operator=(const Point &a) {
        cout << "operator= : " << this << endl;
        this->x = a.x, this->y = a.y;
        return ;
    }
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void seek() const {
        seek_cnt += 1;
        cout << x << " " << y << endl;
    }

    void s() const{
        cout << seek_cnt << endl;
    }

    static int T() { return Point::total_cnt; }

    ~Point() {
        cout << "destructor : " << this << endl;
        Point::total_cnt -= 1;
    }

private:
    int x, y;
    mutable int seek_cnt = 0;
    static int total_cnt;
};
int Point::total_cnt = 0;

void test() {
    Point a;
    cout << Point::T() << endl;
    return ;
}
int main() {
    Point a;
    cout << a.T() << endl;
    test();
    Point b;
    cout << b.T() << endl;
    Point c(3, 4);
    cout << c.T() << endl;
    Point d(3.4);
    cout << d.T() << endl;
    c = 5.6;
    cout << c.T() << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &c << endl;
    cout << &d << endl;
    d.seek();
    c.seek();
    const Point e(6, 7);
    e.seek();
    e.seek();
    e.seek();
    e.seek();
    e.s();
    return 0;
}
```



![image-20200726202545004](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726202545004.png)

![image-20200726202933371](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726202933371.png)

对象放在栈区，类放在堆区，全局是堆区



### 深拷贝与浅拷贝

```c++

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

class A {
public :
    A() {
        this->arr = new int[100];
    }
    A(const A &obj) : x(obj.x), y(obj.y) {
        this->arr = new int[100];
        memcpy(this->arr, obj.arr, sizeof(int) * 100);
    }
    int *arr;
    int x, y;
};

int main() {
    A a;
    a.x = 3, a.y = 6;
    a.arr[0] = 123;
    A b = a;
    b.arr[0] = 456;
    cout << a.arr[0] << " " << b.arr[0] << endl;
    cout << b.x << " " << b.y << endl;
    b.x = 6;
    cout << a.x << " " << a.y << endl;
    cout << b.x << " " << b.y << endl;
    return 0;
}
```

### 类型转换

```c++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
class BigInt{
    public :
    BigInt() {}
    BigInt(int x) {
        num.push_back(x);
        process_digit();
    }
    friend ostream &operator<<(ostream &, const BigInt &);
    private:
    vector<int>num;
    void process_digit() {
        for(int i = 0; i < num.size(); i++) {
            if(num[i] < 10) continue;
            if(i + 1 == num.size())num.push_back(0);
            num[i + 1] = num[i]/10;
            num[i] %= 10;
        }
        return;
    }
};

ostream &operator<<(ostream &out, const BigInt &a) {
    for(int i = a.num.size() - 1; i >= 0; i--) {
        out << a.num[i];
    }
    return out;
}

void func(BigInt a) {
    cout << "func : " << a << endl;
}

int main() {
    BigInt a;
    a = 1234;
    cout << a << endl;
    func(5670);
    return 0;
}
```



### 返回值优化

![image-20200726210134448](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210134448.png)

![image-20200726210240902](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210240902.png)

![image-20200726210611028](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210611028.png)

![image-20200726210710988](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210710988.png)

![image-20200726210804996](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210804996.png)

![image-20200726210955727](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726210955727.png)





```cpp
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;


class People{
public:
    People(string name) {
        cout << "param constructor" << endl;
        this->name = name;
    }
    People(const People &a) {
        cout << "copy constructor" << endl;
        this->name = a.name;
    }
private:
    string name;
};
People func() {
    People temp_a("fangsong");
    return temp_a;
}


int main() {
    People a = func();
    return 0;
}
```

```cpp
g++ -fno-elide-constructors//关闭优化
```

![image-20200726211911968](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200726211911968.png)

### 运算符重载

![image-20200727190130791](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727190130791.png)

```c++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;

namespace haizei {
    
class istream{
public :
    istream &operator>>(int &n){
        std::cin >> n;
        return *this;
    }
private:

};

class ostream {
public :
    ostream &operator<<(int &n) {
        std::cout << n;
        return *this;
    }
    ostream &operator<<(const char *msg) {
        std::cout<< msg;
        return *this;
    }
private:

};
istream cin;
ostream cout;
};

haizei::ostream &operator<<(haizei::ostream &out, double &z) {
    std::cout << z;
    return out;
}

ostream &operator+(ostream &out,const int &z){
    out << z;
    return out;
}

int main() {
    int n, m;
    haizei::cin >> n >> m;
    haizei::cout << n <<" "<< m << "\n";
    double k = 5.6;
    haizei::cout << k << "\n";
    cout + 8 + 9 + 10;
    cout + k;
    (((((cout + 8 )<< " ") + 9) << " ") + 10) << endl;
    return 0;
}
```

```c++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;

class Point{
public:
    Point() : __x(0), __y(0){}
    Point(int x, int y) : __x(x), __y(y){}
    int x() const {return __x;}
    int y() const {return __y;}
    Point operator+(const Point &a) {
    /*this<---a
     * a<----b 
     */
    return Point(x() + a.x(), y() + a.y());
    }
    Point &operator+=(const Point &a) {
        __x += a.x();
        __y += a.y();
        return *this;
    }
    Point &operator++(){
        __x +=1;
        __y +=1;
        return *this;
    }
    Point operator++(int) {
        Point temp(*this);
        __x += 1;
        __y += 1;
        return temp;
    }
private:
    int __x, __y;
};

ostream &operator<<(ostream &out, const Point &a) {
    cout << "Point (" << a.x() << "," <<a.y() << ")";
    return out;
};



int main() {
    Point a(4, 5), b(3, 4), c(1, 1);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << a << " " << b << endl;
    cout << a + b << endl;
    cout << ++(c += b) << endl;
    cout << c << endl;
    cout << c++ << endl;
    cout << c << endl;
    int n = 6, m = 7;
    (n += m) ++;
    cout << n << endl;
    return 0;
}
```



```c++
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;

class A{
public:
    A() {
        arr = new int[10];
    }
    A(const A &a) : A() {
        for(int i = 0; i < 10; i++) {
            this->arr[i] = a.arr[i];
        }
        this->x = a.x;
        this->y = a.y;
        return;
    }
    int x, y;
    int *arr;
};

class B{
public :
    B() : obj(nullptr) {
        arr = new int[10];
        arr[3] = 9973;
    }
    B(A *obj) : B() {
        this->obj = obj;
    }
    int operator() (int a, int b) {
        return a + b;
    }
    int &operator[](int ind) {
        return arr[ind];
    }
    void operator[](const char *msg) {
        cout << msg << endl;
        return;
    }
    A *operator->() {
        return obj;
    }
    A &operator*() {
        return *obj;
    }
    ~B() {
        delete arr;
    }
private:
    int *arr;
    A *obj;
};

ostream &operator <<(ostream &out, const A &a) {
    out << "A（" << a.x << " ," << a.y << ")" << endl;
    return out;
}

int main() {
    B add;
    cout << add(3, 4) << endl;
    cout << add[3] << endl;
    add[3] = 8876;
    cout << add[3] << endl;
    add["hello world"];

    A a, b(a);
    a.x = 67, a.y = 99;
    B p = &a;
    cout << p->x << " " << p->y << endl;
    cout << *p << endl;
    
    a.arr[3] = 9973;
    b.arr[3] = 6687;
    cout << a.arr[3] << endl;
    cout << b.arr[3] << endl;
    return 0;
}
```



## 继承

```c++
class Animal{
  public :
    string name() {retrun this->name;}
  private:
    string __name;
};
class Cat : public Animal {  
};
```

### 继承-子类的访问权限

![image-20200727122409900](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727122409900.png)

|           | public                                            | protected                                         | private                                           |
| --------- | ------------------------------------------------- | ------------------------------------------------- | ------------------------------------------------- |
| public    | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> |
| protected | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> | <button style="background-color:green">√</button> |
| private   | <button style="background-color:red">×</button>   | <button style="background-color:red">×</button>   | <button style="background-color:red">×</button>   |

### 继承-对外的访问权限

|           |                public                |              protected               |             private              |
| :-------: | :----------------------------------: | :----------------------------------: | :------------------------------: |
|  public   |   <font color = blue>public</font>   | <font color = green>protected</font> | <font color = red>private</font> |
| protected | <font color = green>protected</font> | <font color = green>protected</font> | <font color = red>private</font> |
|  private  |       <font color=red>×</font>       |      <font color = red>×</font>      |    <font color = red>×</font>    |

子类继承过来的对外

### 继承-构造函数

![image-20200727114849386](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727114849386.png)

### 菱形继承

![image-20200727125950494](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727125950494.png)

所以才引出：允许一个实体类，多个接口类

### 继承下的拷贝构造

![image-20200727132324997](http://test-fangsong-imgsubmit.oss-cn-beijing.aliyuncs.com/img/image-20200727132324997.png)