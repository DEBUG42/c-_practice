#include <iostream>
using namespace std;

// 定义基类Base
class Base{
    public:
    // 声明一个虚函数f
    virtual void f(){
        cout <<"调用Base::f()"<<endl;
        }
};

// 定义派生类Derived，继承自Base
class Derived:public Base{
    public:
    // 重写基类的虚函数f
    void f (){
        cout <<"调用Derived::f()"<<endl;
        }
};

// 主函数
int main(){
    // 创建Derived类的对象obj
    Derived obj;
    // 创建指向Base类的指针p，并指向对象obj
    Base *p=&obj;
    // 调用指针p所指向对象的虚函数f
    p->f();
    // 返回0，表示程序成功结束
    return 0;
}