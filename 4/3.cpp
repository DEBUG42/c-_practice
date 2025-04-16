#include<iostream>
using namespace std;

// 定义复数类
class Complex{
    private:
    int a, i; // 私有成员变量，a 表示实部，i 表示虚部

    public:
    Complex(){} // 默认构造函数

    // 带参数的构造函数，用于初始化复数的实部和虚部
    Complex(int x, int y){a = x; i = y;}

    // 重载加法运算符，用于复数相加
    Complex operator+ (Complex c){
        Complex sum;
        sum.a = a + c.a;
        sum.i = i + c.i;
        return sum;
    }

    // 重载乘法运算符，用于复数相乘
    Complex operator* (Complex c){
        Complex multi;
        multi.a = a * c.a - i * c.i;
        multi.i = a * c.i + i * c.a;
        return multi;
    } 

    // 重载输出流运算符，用于输出复数
    friend ostream& operator<< (ostream& os, Complex c){
        os << c.a << "+" << c.i << "i";
        return os;
    } 
};

// 主函数
int main(){
    Complex c1(3, 4); // 创建复数对象 c1，实部为 3，虚部为 4
    Complex c2(1, 2); // 创建复数对象 c2，实部为 1，虚部为 2
    Complex sum = c1 + c2; // 计算 c1 和 c2 的和
    Complex multi = c1 * c2; // 计算 c1 和 c2 的积

    cout << "sum = " << sum << endl; // 输出复数加法的结果
    cout << "multi = " << multi << endl; // 输出复数乘法的结果
    return 0;
}