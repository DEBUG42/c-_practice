#include <iostream>
using namespace std;
// 定义一个模板函数Max，用于返回两个相同类型的参数中的较大值
template <typename T>
T Max(T a ,T b){return (a>b)?a:b;}
// 主函数
int main(){
    int c=Max(1,2);
    long d=Max(1L,2L);
    double e=Max(1.8,2.3);
    float f=Max(1.3f,2.5f);
    cout<<"int类型的c值为：" << c << endl;
    cout<<"long类型的d值为：" << d << endl;
    cout<<"double类型的e值为：" << e << endl;
    cout<<"float类型的f值为：" << f << endl;
    system("pause");
    return 0;
}