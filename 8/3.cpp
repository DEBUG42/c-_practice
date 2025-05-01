#include <iostream>
using namespace std;

// 定义一个进行除法运算的函数，接收两个double类型的参数a和b
double Division(double a, double b) {
    // 检查除数b是否为0，如果是则抛出运行时错误
    if (b == 0) {
        throw runtime_error("除数为0");
    }
    else
        // 如果b不为0，返回a除以b的结果
        return a / b;
}

int main() {
    // 主函数开始，尝试执行可能抛出异常的操作
    try{
    double a = 1;
    double b = 0;
    // 调用Division函数并输出结果，如果发生异常则跳转到catch块
    cout << "a/b" << Division(a, b) << endl;
    }
    // 捕获runtime_error类型的异常并输出异常信息
    catch(const runtime_error& e)
    {
        cout << "异常信息：" << e.what() << endl;
    }
    // 捕获char const*类型的异常并输出异常信息
    catch(char const* str){
        cout << "异常信息：" << str << endl;
    }
    // 暂停程序，等待用户输入
    system("pause");
    // 返回0表示程序成功结束
    return 0;
}