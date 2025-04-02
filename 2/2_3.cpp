#include <iostream>
using namespace std;
class Time{
    private:
    int hour;
    int minute;
    int second;
    public:
    void setTime(int h,int m,int s)
    {
        hour=h;
        minute=m;
        second=s;
    }
    void displayTime()
    {
        cout<<"Time: "<<hour<<":"<<minute<<":"<<second<<endl;
    }
    void addOneSecond()
    {
        second++;
        if(second==60)
        {
            second=0;
            minute++;
            if(minute==60)
            {
                minute=0;
                hour++;
                if(hour==24)
                {
                    hour=0;
                }
            }
        }
    }
};
int main()
{
    Time t;
    int h,m,s;
    cin>>h>>m>>s;
    t.setTime(h,m,s);
    t.displayTime();
    t.addOneSecond();
    t.displayTime();
}