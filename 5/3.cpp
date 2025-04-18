#include <iostream>
using namespace std;
class Base{
    private:
    int m;
    public:
    Base(int a):m(a){} // 构造函数，初始化成员变量m
    virtual void Show(){
        cout<<"m="<<m<<endl; // 输出成员变量m的值
    }
};
class Derived : public Base{
    private:
    int n;
    public:
    Derived(int a,int b):Base(a),n(b){} // 构造函数，调用基类构造函数初始化m，并初始化Derived类的成员变量n
    void Show(){
        cout<<n<<","<<endl; // 输出成员变量n的值
        Base::Show(); // 调用基类的Show方法
    }
};
int main(){
    Base *p; // 声明一个指向Base类的指针
    Base obj1(168); // 创建Base类的对象obj1，并初始化m为168
    p=&obj1; // 将指针p指向obj1
    p->Show(); // 调用obj1的Show方法
    Derived obj2(158,158); // 创建Derived类的对象obj2，并初始化m和n为158
    p=&obj2; // 将指针p指向obj2
    p->Show(); // 调用obj2的Show方法，由于多态性，会调用Derived类重写的Show方法
    p->Base::Show(); // 强制调用基类Base的Show方法
    return 0;
}
