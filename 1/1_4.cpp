#include <iostream>
using namespace std;
void sort(int &a, int &b){
int temp;
if (a > b)
{temp = a;
a = b;
b = temp;
}
}
int main(){
int a, b;
cin >> a >> b;
int &c = a, &d = b;
sort(c,d);
cout<<a<<" "<<b<<endl;
return 0;
}