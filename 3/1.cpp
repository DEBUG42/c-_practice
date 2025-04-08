#include <iostream>
using namespace std;
class A{
    public:
    A(){cout <<"构造A"<<endl;}
    ~A(){cout <<"析构A"<<endl;}
};
class B:public A{
    public:
    B(){cout <<"构造B"<<endl;}
    ~B(){cout <<"析构B"<<endl;}
};
class C:public B{
    public:
    C(){cout <<"构造C"<<endl;}
    ~C(){cout <<"析构C"<<endl;}
};
int main(void){
    C obj;
    system("PAUSE");    //调用库函数system（），输出系统提示信息
    return 0;
}