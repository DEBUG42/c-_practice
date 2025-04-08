#include <iostream>
#include <cmath>
using namespace std;
class Dot {
    public:
    float x, y;
    Dot():x(0.0), y(0.0) {}
    Dot(float a, float b)
    {
        x = a;
        y = b;
    }  
};
class line:public Dot {
    public:
    Dot dot1,dot2;
/*   line(Dot dot1, Dot dot2) : Dot((dot1.x + dot2.x) / 2, (dot1.y + dot2.y) / 2) {
        cout << "x=" << x << " y=" << y << endl;
    }
*/  
    line(Dot d1,Dot d2){

        x=(d1.x+d2.x)/2;
        y=(d1.y+d2.y)/2;
    }      
    void print(Dot dot1, Dot dot2)
    {
    float length;
    length=sqrt((dot1.x-dot2.x)*(dot1.x-dot2.x)+(dot1.y-dot2.y)*(dot1.y-dot2.y));
    cout << length << endl; 
    }     

};
int main() {
Dot dot1(1.0,2.0);
Dot dot2(3.0,4.0);
line l(dot1,dot2);
l.print(dot1,dot2);
return 0;
}
