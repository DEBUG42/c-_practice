#include <iostream>
using namespace std;
template <typename T>
T max(T a, T b,T c) {
    T max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    return max;
}
int main() {
    int i1 = 10, i2 = 20, i3 = 30;
    int i;
    double d1 = 1.1, d2 = 2.2, d3 = 3.3;
    double d;
    i = max(i1, i2, i3);
    d = max(d1, d2, d3);
    cout << "i_max=" << i << endl;
    cout << "d_max=" << d << endl;
    return 0;
}