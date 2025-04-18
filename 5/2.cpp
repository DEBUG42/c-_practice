#include <iostream>
using namespace std;

// 定义基类 Base
class Base{
    public:
    // 定义虚函数 Show
    virtual void Show(){
        cout<<"调用Base::Show"<<endl;
    }
};

// 定义派生类 Derived，继承自 Base
class Derived : public Base{
    public:
    // 重写 Show 函数
    void Show(){
        cout<<"调用Derived::Show"<<endl;
        }
};

// 定义函数 Refers，接受 Base 类型的引用
void Refers(Base &obj){
    obj.Show();
}

// 主函数
int main(){
    // 创建 Base 类对象 obj1
    Base obj1;
    // 调用 Refers 函数，传入 obj1
    Refers(obj1);
    // 创建 Derived 类对象 obj2
    Derived obj2;
    // 调用 Refers 函数，传入 obj2
    Refers(obj2);
    return 0;
}