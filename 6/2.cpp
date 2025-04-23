
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    // 定义整数变量a并赋值为22
    int a=22;
    // 设置输出格式以显示数字的进制前缀
    cout.setf(ios::showbase);

    // 设置输出格式为十进制
    cout.setf(ios::dec);
    cout <<"dec:"<<setw(6)<<a<<endl;
    // 取消十进制输出格式
    cout.unsetf(ios::dec);

    // 设置输出格式为八进制
    cout.setf(ios::oct);
    cout <<"oct:"<<setw(6)<<a<<endl;
    // 取消八进制输出格式
    cout.unsetf(ios::oct);
    
    // 设置输出格式为十六进制
    cout.setf(ios::hex);
    cout <<"hex:"<<setw(6)<<a<<endl;
    // 取消十六进制输出格式
    cout.unsetf(ios::hex);


}