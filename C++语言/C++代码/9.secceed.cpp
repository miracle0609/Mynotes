/*************************************************************************
	> File Name: 9.secceed.cpp
	> Author:fangsong
	> Mail: 2035756541@qq.com
	> Created Time: 2020年07月27日 星期一 13时24分50秒
 ************************************************************************/
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

#define P_ADD(obj, a) cout << #obj "." #a " = " << &(obj.a)

class Animal {
public:
    Animal(string name) : __name(name) {
        cout << "Animal constructor " << this << endl;
    }
    string name() { return this->__name; }

    int x, y;
    string __name;
    ~Animal() {
        cout << "Animal destructor " << this << endl;
    }
};

class Cat : public Animal {
public :
    Cat() : Animal("hello kitty") {
        arr = new int[100];
        cout << "Cat constructor " << this << endl;
    }
    void say() {
        cout << "my name is " << this->name() << endl;
    }
    int z;
    int *arr;
    ~Cat() {
        delete[] arr;
        cout << "Cat destructor " << this << endl;
    }
};

ostream &operator<<(ostream &out, const Animal &a) {
    out << "<class Animal> " << &a << endl;
    P_ADD(a, x) << endl;
    P_ADD(a, y) << endl;
    P_ADD(a, __name) << endl;
    return out;
}

ostream &operator<<(ostream &out, const Cat &a) {
    out << "<class Cat> " << &a << endl;
    P_ADD(a, x) << endl;
    P_ADD(a, y) << endl;
    P_ADD(a, __name) << endl;
    P_ADD(a, z) << endl;
    return out;
}

int main() {
    Animal a("any");
    Cat c;
    c.say();
    cout << sizeof(a) << " " << sizeof(c) << endl;
    cout << c << endl;
    Animal *p = new Cat();
    cout << "Animal * : " << p->name() << endl;
    delete p;
    
    Animal &q = c;
    cout << q << endl;
    
    return 0;
}
