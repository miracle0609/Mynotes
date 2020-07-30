/*************************************************************************
	> File Name: 12.virtual.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年07月30日 星期四 11时07分42秒
 ************************************************************************/

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


string rand_name(int n) {
    string name = "";
    for(int i = 0; i < n; i++) {
        name = name + (char)(rand() % 26);
    }
    return name;
}

class Animal {
public :
    Animal(string name):name(name){}
    string tell_me_your_name(){
        return this->name;
    }
    virtual void run() {
        cout << "I don't know how to run" << endl;
    }
    virtual void say() = 0;
    virtual ~Animal() {
        cout << "Animal destructor" << endl;
    }
private:
    string name;
};

class Cat : public Animal{
public:
    Cat() : Animal(rand_name(5)){}
    void run() {
        cout << "I can run with four legs" << endl;
    }
    void say() {
        cout << " miaomiaomiao~~~" << endl;
    }
    ~Cat() {
        cout << "Cat destructor" << endl;
    }
};

class Bat : public Animal{
public:
    Bat() : Animal(rand_name(5) + "Bat") {}
    void run() {
        cout << "I can fly" << endl;
    }
    void say() {
        cout << "zzz zzz zzz" << endl;
    }
    ~Bat() {
        cout << "Bat destructor" << endl;
    }
};

int main() {
    Cat a;
    Bat b;
    cout << a.tell_me_your_name() << endl;
    a.run();
    cout << b.tell_me_your_name() << endl;
    b.run();
    Animal **arr = new Animal*[10];
    for(int i = 0; i < 10; i++) {
        if(rand() % 2) {
            arr[i] = new Cat();
        } else {
            arr[i] = new Bat();
        }
    }
    for(int i = 0; i < 10; i++) {
        cout << arr[i]->tell_me_your_name() << endl;
        arr[i]->run();
        arr[i]->say();
    }
    for(int i = 0; i < 10; i++) {
        delete arr[i];
    }
    delete [] arr;
    return 0;
}
