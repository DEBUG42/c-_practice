#include <iostream>
using namespace std;
int max(int a, int b) {
    if(a > b)
    return a;
    else
    return b;
}
int max(int a, int b, int c) {
    int max = a;
    if(b > max)
    max = b;
    if(c > max)
    max = c;
    return max;
}   
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout<<max(a, b, c)<<endl;
    cout<<max(a,b)<<endl;    
    return 0;
}    