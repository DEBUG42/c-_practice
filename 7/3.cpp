#include <iostream>
using namespace std;

// 定义一个二维点类
class Point2D{
    public:
    int x;
    int y;
    
    // 构造函数，支持默认参数
    Point2D(int a=0, int b=0){
        x = a;
        y = b;
        cout<<"调用Point2D的构造函数"<<endl;
    }
    
    // 类型转换运算符，将Point2D对象转换为int类型
    operator int(){cout<<"调用Point2D的类类型转换函数"<<endl;return x+y;}
};

// 定义一个三维点类
class Point3D{
    public:
    int x; 
    int y;
    int z;
    
    // 构造函数，支持默认参数
    Point3D(int a=0, int b=0, int c=0){
        x = a;
        y = b;
        z = c;
        cout<<"调用Point3D的构造函数"<<endl;
    }
    
    // 转换构造函数，将Point2D对象转换为Point3D对象
    Point3D(const Point2D& p2D) : x(p2D.x), y(p2D.y), z(0) {
        cout << "调用Point3D的转换构造函数" << endl;
    }
    
    // 类型转换运算符，将Point3D对象转换为Point2D对象
    operator Point2D(){cout<<"调用Point3D的类类型转换函数1"<<endl;return Point2D(x,y);}
    
    // 类型转换运算符，将Point3D对象转换为int类型
    operator int(){cout<<"调用Point3D的类类型转换函数2"<<endl;return x+y+z;}

};

// 主函数
int main(){
    Point2D p2D1 = 2; // 创建一个Point2D对象，并调用构造函数
    Point3D p3D1 = 3; // 创建一个Point3D对象，并调用构造函数
    int a = p2D1;     // 将Point2D对象转换为int类型
    Point3D p3D2 = p2D1; // 使用转换构造函数将Point2D对象转换为Point3D对象
    Point2D p2D3 = p3D2; // 使用类型转换运算符将Point3D对象转换为Point2D对象
    cout<<"a="<<a<<endl; // 输出a的值
    return 0;
}