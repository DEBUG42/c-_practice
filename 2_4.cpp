#include <iostream>
using namespace std;
class box{
    
    private:
    int height;
    int width;
    int length;

    public:
    box(int h, int w, int l):height(h),width(w),length(l){}

    int volume(){
        int vol;
        vol=height*width*length;
        return vol;
    }
};
int main(){
box box1(12,20,25),box2(10,14,20);
int vol1,vol2;
vol1=box1.volume();
vol2=box2.volume();
cout<<"vol1="<<vol1<<endl;
cout<<"vol2="<<vol2<<endl;
return 0;
}   