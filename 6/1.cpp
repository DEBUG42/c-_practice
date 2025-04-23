#include <iostream>
#include <iomanip>
using namespace std;
// 主函数，用于打印9x9的乘法表
int main() {
    cout <<"*";
    for(int i = 1;i<=9;i++){
        cout << setw(6) << i;
    }
    cout << endl;
    for(int i=1;i<=9;i++){
        cout<< i;
        for(int j=1;j<i;j++)
        cout << setw(6)<<"";
        for(int j=i;j<=9;j++){
        cout<<setw(6)<<i*j;
        }
    cout<<endl;
}
}