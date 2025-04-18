#include <iostream>
using namespace std;
class Shape{
    public:
    virtual void Show()=0; //纯虚函数
    static double sum;
};
double Shape::sum=0;
class Circle : public Shape{
    public:
    void Show(){
        cout<<"Circle::Show"<<endl;
    }
    void Area(int a){
        cout<<"Circle::Area="<<3.14*a*a<<endl;
        Shape::sum+=3.14*a*a;
    }
};
class Rectangle : public Shape{
    public:
    int a;
    int b;
    void Show(){
        cout<<"Rectangle::Show"<<endl;
    }
    void Area(int a,int b){
        this->a=a;
        Rectangle::b=b;
        cout<<"Rectangle::Area="<<a*b<<endl;
        Shape::sum+=a * b;
    }
    friend istream &operator>>(istream &in, Rectangle &r);
};
istream &operator>>(istream &in, Rectangle &r){
    cout<<"请输入长和宽：";
    in >> r.a >> r.b;
}
int main(){
//实现动态分配对象，并在使用完后释放内存
Shape *p;
Circle c;
Rectangle r;
p=new Circle;
p->Show();
delete p;
p=new Rectangle;
p->Show();
delete p;
int a;
cout << "请输入圆的半径：";
cin >> a;
c.Area(a);
cout <<"输入矩形的长和宽：" << endl;
cin >> r.a >> r.b;
r.Area(r.a,r.b);
cout<<"sum="<<Shape::sum<<endl;
return 0;
delete p;
}
