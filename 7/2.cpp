#include <iostream>
using namespace std;

// 定义一个用于比较两个整数并返回较大值的函数
int Max(int x, int y) {return (x > y)? x : y;}

// 定义一个用于比较两个长整数并返回较大值的函数
long Max(long x, long y) {return (x > y)? x : y;}

// 定义一个用于比较两个双精度浮点数并返回较大值的函数
double Max(double x, double y) {return (x > y)? x : y;}

// 主函数，程序的入口
int main() {
//重载出现问题
    double d = Max (1.8, 2.3);
    long b = Max(1,2);
    cout << "double类型的d值为：" << d << endl;
    cout << "long类型的b值为：" << b << endl;
    system("pause");
    return 0;
}