#include <iostream>
using namespace std;

// 定义一个进行除法运算的函数，接受两个double类型的参数
double Division(double a, double b){
    // 检查除数是否为0，若是则抛出异常
    if(b == 0)
        throw "除数为0";
    else
        return a/b;
}

// 主函数，程序的入口点
int main(){
    // 使用try块尝试执行可能抛出异常的代码
    try{
        double a = 1, b = 0;
        // 调用Division函数并输出结果
        cout <<"a/b"<< Division(a, b) << endl;
    }
    // 捕获runtime_error类型的异常并输出异常信息
    catch(const runtime_error& e){
        cout <<"异常信息："<< e.what() << endl;
    }
    // 捕获char类型的异常并输出异常信息
    catch(char const*str){
        cout <<"异常信息："<< str << endl;
    }
    // 等待用户按键后继续执行
    system("pause");
    // 返回0，表示程序正常结束
    return 0;
}
