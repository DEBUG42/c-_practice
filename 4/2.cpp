#include <iostream>
using namespace std;
// 定义一个计算类Caculator，包含加法和乘法功能
class Caculator{
    private:
        int a,b; // 私有成员变量a和b，用于存储整数
        double c,d; // 私有成员变量c和d，用于存储双精度浮点数
    public:
        Caculator(){} // 构造函数，初始化Caculator对象
        // 重载加法函数，用于整数相加
        int add(int a, int b){
            return a+b;
        }
        // 重载加法函数，用于双精度浮点数相加
        double add(double a, double b){
            return a+b;
        }
        // 乘法函数，用于整数相乘
        int multiply(int a, int b){
            return a*b;
        }
};
int main(){
    Caculator calc; // 创建Caculator类的一个对象calc
    cout <<"Add integeters:"<< calc.add(3,4) << endl; // 调用整数加法函数并输出结果
    cout <<"Add doubles:"<< calc.add(3.5,4.5) << endl; // 调用双精度浮点数加法函数并输出结果
    cout <<"Multiply integers:"<< calc.multiply(3,4) << endl; // 调用整数乘法函数并输出结果
    return 0; // 主函数返回0，表示程序正常结束
}