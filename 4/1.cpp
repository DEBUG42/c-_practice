#include <iostream>
using namespace std;

// 定义一个名为 Array 的类，用于封装数组及其操作
class Array{
    private:
    int* elem; // 指向数组元素的指针
    int size;  // 数组的大小
    public:
    // 构造函数，初始化数组指针和大小
    Array(int *all,int sz):elem(all),size(sz){}
    // 获取数组大小的方法
    int GetSize(){return size;}
    // 重载 operator[]，允许通过下标访问数组元素，注意下标从1开始
    int &operator[](int pos){return elem[pos-1];}
};

// 主函数，程序入口
int main(void){
    int a[]={1,2,3,4,5}; // 定义并初始化一个包含5个整数的数组
    Array obj(a,5); // 创建 Array 类的对象，传入数组和大小

    obj[1]=8; // 修改数组的第一个元素为8
    // 遍历并输出数组中的所有元素
    for(int i=1;i<=obj.GetSize();i++){
        cout<<obj[i]<<" "<<endl;
    }
    system("pause"); // 暂停程序，等待用户输入
    return 0; // 返回0，表示程序正常结束
}