#include <iostream>
using namespace std;
// 定义一个返回两个整数中较大值的函数
int Max(int x, int y){return (x>y)?x:y;}
int main(){
    // 调用Max函数，传入两个double类型的值，并将返回值赋给double类型的变量d
    double d=Max(1.8,2.3);
    // 调用Max函数，传入两个int类型的值，并将返回值赋给long类型的变量b
    long b =Max(1,2);
    // 输出double类型的变量d的值
    cout<<"double类型的d值为：" << d << endl;
    // 输出long类型的变量b的值
    cout<<"long类型的b值为：" << b << endl;
    // 暂停程序以查看输出结果
    system("pause");
    // 返回0，表示程序正常结束
    return 0;
}