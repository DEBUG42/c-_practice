#include <iostream>
using namespace std;

// 形状类，定义了一个纯虚函数Show和一个静态成员变量sum
class Shape{
    public:
    virtual void Show()=0; //纯虚函数
    static double sum;
};

// 初始化静态成员变量sum
double Shape::sum=0;

// 圆形类，继承自Shape类，实现了Show函数，并定义了一个计算面积的函数Area
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

// 矩形类，继承自Shape类，实现了Show函数，并定义了一个计算面积的函数Area
// 同时，定义了一个友元函数以支持输入操作符重载
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

// 重载输入操作符以支持从标准输入读取矩形的长和宽
istream &operator>>(istream &in, Rectangle &r){
    cout<<"请输入长和宽：";
    in >> r.a >> r.b;
}

// 主函数，实现动态分配对象，并在使用完后释放内存
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
