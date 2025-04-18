#include <iostream>
using namespace std;

// 定义基类BaseA
class BaseA{
    public:
    // 定义一个带参数的Show函数
    void Show(int x){}
    // 定义一个虚函数Show
    virtual void Show(){}
};

// 定义派生类DerivedB，继承自BaseA
class DerivedB : public BaseA{
    public:
    // 重载基类的带参数Show函数
    void Show(int x) {
        cout<<"派生类B的重载函数"<<endl;
    }
    // 重写基类的虚函数Show
    virtual void Show() {
        cout<<"派生类B的虚函数"<<endl;
    }
};

// 主函数
int main(){
    DerivedB obj;
    // 调用DerivedB类的带参数Show函数
    obj.Show(10);
    // 调用DerivedB类的虚函数Show
    obj.Show();
    // 定义一个指向BaseA类型的指针，并指向DerivedB对象
    BaseA *p=&obj;
    // 通过基类指针调用虚函数Show，实际执行的是DerivedB类的Show函数
    p->Show();
    // 通过基类指针调用带参数的Show函数，实际执行的是BaseA类的Show函数
    p->Show(10);
}