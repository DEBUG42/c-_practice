#include <iostream>
using namespace std;
class A{
    protected:
    int a;
    public:
    A(int x):a(x){}
    void Show(){
        cout << a << endl;
    }
};
class B
{
    protected:
    int b;
    public:
    B(int x):b(x){}
    void Show(){
        cout << b << endl;
    }
};
class C:public A,public B{
    public:
    C (int x, int y):A(x),B(y){}
    void Show(){cout << a << "," << b << endl;}
};
int main(){
    C obj(5,18);
    obj.Show();
    obj.A::Show();
    obj.B::Show();
    system("PAUSE");
    return 0;
}

