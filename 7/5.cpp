#include <iostream>
using namespace std;
// 定义一个二维点的类
class Point2D {
public:
    int x, y;
    // 构造函数，初始化点的坐标
    Point2D(int x = 0, int y = 0) : x(x), y(y) {}
    // 类型转换操作符，将Point2D对象转换为int类型
    operator int() const {
        cout << "调用Point2D的类类型转换函数" << endl;
        return x + y;
    }
    // 友元函数重载<<操作符，用于输出Point2D对象
    friend ostream& operator<<(ostream& os, const Point2D& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};
// 函数模板，根据给定的数组和下标返回相应的元素
template<typename T, typename Index>
T getElement(const T arr[], Index index) {
    if (index >= 0) {
        return arr[index];
    } else {
        throw out_of_range("Index is out of range");
    }
}
// 主函数，演示Point2D类的使用和getElement函数模板
int main() {
    Point2D arr1[]={Point2D(1,2),Point2D(3,4)};
    cout << arr1[0] << endl; // Point2D(1, 2)
    int arr[] = {1, 2, 3, 4, 5};
    cout << getElement(arr, 2) << endl; // 3
    double darr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << getElement(darr, 2) << endl; // 3.3
    return 0;
}