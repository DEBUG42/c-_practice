#include <iostream>
using namespace std;

// 定义复数类
class Complex{
    private:
    int realPart, imagPart; // 私有成员变量，表示复数的实部和虚部
    public:
    Complex(){realPart=0; imagPart=0;} // 默认构造函数，初始化为0
    Complex(int r, int i){realPart=r; imagPart=i;} // 带参数的构造函数，初始化为指定的实部和虚部
    int GetRealPart(){return realPart;} // 获取复数的实部
    int GetImagPart(){return imagPart;} // 获取复数的虚部
};

// 重载输出运算符以支持Complex类对象的输出
ostream& operator<<(ostream& os, Complex c){
    if(c.GetImagPart()>0){
        os << c.GetRealPart() << "+" << c.GetImagPart() << "i"; // 输出实部和正虚部
    }
    else if(c.GetImagPart()<0){
        os << c.GetRealPart() << c.GetImagPart() << "i"; // 输出实部和负虚部
    }
    else{
        os << c.GetRealPart(); // 如果虚部为0，仅输出实部
    }
    return os;
}

// 主函数
int main(){
    Complex c1(3, 4); // 创建一个复数对象，实部为3，虚部为4
    Complex c2(1, -2); // 创建一个复数对象，实部为1，虚部为-2
    Complex c3(5, 0); // 创建一个复数对象，实部为5，虚部为0
    cout << c1 <<endl; // 输出复数对象c1
    cout << c2 <<endl; // 输出复数对象c2
    cout << c3 <<endl; // 输出复数对象c3
    return 0;
}