#include <iostream>
#include <cmath>
using namespace std;
class Triangle
{
private:
int a, b, c;
public:
void Set(int x, int y, int z)
{
a = x;
b = y;
c = z;
}
void Get()
{
    cout<<a<<" "<<b<<" "<<c<<endl;
}
void Perim()
{
    int sum = a + b + c;
    cout<<sum<<endl;
}
void Area()
{
    float p=(a+b+c)/2.0;
    float area;
    area=sqrt(p*(p-a)*(p-b)*(p-c));
    cout<<area<<endl;
}
};
int main()
{  
    Triangle tri;
    int x, y, z;
    cin>>x>>y>>z;
    tri.Set(x, y, z);
    tri.Get();
    tri.Perim();
    tri.Area();
    return 0;
}