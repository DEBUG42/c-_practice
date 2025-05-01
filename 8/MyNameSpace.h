#include <iostream>
using namespace std;

namespace MyNameSpace {
    // 定义一个整数变量 value，初始值为 10
    int value = 10;
    // 定义一个函数 print，用于输出字符串 "Hello from MyNameSpace!" 到控制台
    void print(){
        cout <<"Hello from MyNameSpace!"<<endl;
    }
    // 定义一个子命名空间 ChildNameSpace
    namespace ChildNameSpace {
        // 定义一个整数变量 value，初始值为 10
        int value = 10;
        // 定义一个整数变量 value2，初始值为 20
        int value2 = 20;
    }
}