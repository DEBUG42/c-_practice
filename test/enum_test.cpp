#include <iostream>
using namespace std;

typedef enum Color {RED, GREEN, BLUE} Color;
//不能直接从枚举数字获取字母
int main() {
    int a=1;
    //想根据a输出red    
    cout <<Color(a)<<endl;

    return 0;
}