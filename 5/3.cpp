#include <iostream>
using namespace std;
class Base{
    private:
    int m;
    public:
    Base(int a):m(a){}
    virtual void Show(){
        cout<<"m="<<m<<endl;
    }
};
class Derived : public Base{
    private:
    int n;
    public:
    Derived(int a,int b):Base(a),n(b){}
    void Show(){
        cout<<n<<","<<endl;
        Base::Show();
    }
};
int main(){
    Base *p;
    Base obj1(168);
    p=&obj1;
    p->Show();
    Derived obj2(158,158);
    p=&obj2;
    p->Show();
    p->Base::Show();
    return 0;
}
