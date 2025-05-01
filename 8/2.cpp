#include <iostream>
using namespace std;

// 执行除法运算的函数，如果除数为0则抛出异常
double Division(double a, double b){
    if(b == 0)
        throw runtime_error("除数为0");
    else
        return a/b;
}

// 主函数，用于测试Division函数并处理可能抛出的异常
int main(){
    try{
    double a =1 ;
    double b = 0;
    cout<<"a/b"<<Division(a,b)<<endl;
    }
    catch(const runtime_error e){
        cout<<"异常信息："<<e.what()<<endl;
    }
    catch(char const *str){
        cout<<"异常信息："<<str<<endl;
    }
    system("pause");
    return 0;
}