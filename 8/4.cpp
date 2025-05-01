#include <iostream>
#include <vector>
using namespace std;

// 函数Test接收一个整数向量和一个索引, 返回向量中该索引对应的元素
int Test(vector<int> vec,int i){return vec.at(i);}

int main(){
    try{
        vector<int> vec ={10,20,30,40,50};
        // 调用Test函数, 传入vec和索引10
        int i = Test(vec,10);
    }
    // 捕获运行时错误并输出异常信息
    catch(const runtime_error& e){
        cout<<"异常信息: "<<e.what()<<endl;
    }
    // 捕获范围越界错误并输出异常信息
    catch(const out_of_range& e){
        cout<<"异常信息: "<<e.what()<<endl;
    }
    // 捕获字符指针类型的异常并输出异常信息
    catch(char const* e){
        cout<<"异常信息: "<<e<<endl;
    }
    // 暂停程序以查看输出
    system("pause");
    return 0;
}