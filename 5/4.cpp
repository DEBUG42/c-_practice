#include <iostream>
using namespace std;
class BaseA{
    public:
    void Show(int x){}
    virtual void Show(){}
};
class DerivedB : public BaseA{
    public:
    void Show(int x) {
        cout<<"派生类B的重载函数"<<endl;
    }
    virtual void Show() {
        cout<<"派生类B的虚函数"<<endl;
    }
};
int main(){
    DerivedB obj;
    obj.Show(10);
    obj.Show();
    BaseA *p=&obj;
    p->Show();
    p->Show(10);
}
