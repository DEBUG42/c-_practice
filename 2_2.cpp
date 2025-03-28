#include <iostream>
using namespace std;
class Array_max
{
    private:
        int array[10];
        int max;
        public:
        void set_value()
        {
            int n;
            for(n=0;n<10;n++)
            cin>>array[n];
        }
        void max_value()
        {
            int i;
            max=array[0];
            for(i=1;i<10;i++)
            {
                if(array[i]>max)
                max=array[i];
            }
        }
        void show_array()
        {
            cout<<max<<endl;    
        }
};
int main()
{
    Array_max arrmax;
    arrmax.set_value();
    arrmax.max_value();
    arrmax.show_array();
    return 0;
}