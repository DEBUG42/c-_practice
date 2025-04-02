#include <iostream>
using namespace std;
class People{
    protected:
        int age;
        int height;
        int weight;
        static int num;
    public:
        People(int a, int h, int w){
        age = a;
        height = h;
        weight = w;
        num++;
        }
        
        void Eatting(){
            weight ++;
        }

        void Sporting(){
            height ++;
        }

        void Sleeping(){
            age ++;
            Eatting();
            Sporting();
        }
        
        void Show(){
        cout << "age: " << age << endl;
        cout <<"height: "<< height << endl;
        cout <<"weight: "<<weight<<endl;
        }
//用静态成员函数，可以直接跳过定义对象的环节
        static void ShowNum(){
        cout << "人数 "<<num<<endl;
        }
};
int People::num=0;

int main(){
People obj1(8,120,60);
obj1.Eatting();
obj1.Sporting();
obj1.Sleeping();
obj1.Show();
People obj2(18,170,108);
obj2.Eatting();
obj2.Sporting();
obj2.Sleeping();
obj2.Show();
People::ShowNum();
return 0;
}