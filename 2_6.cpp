#include <iostream>
#include <cstring>
using namespace std;
class Student{
    private:
        char name[18];
        int num;
        int mathScore;
        int englishScore;
        static int count;
        static int mathTotalScore;
        static int englishTotalScore;
    public:
        Student(char nm[], int n, int math, int english){
            strcpy(name, nm);
            num = n;
            mathScore = math;
            englishScore = english;
            count++;
            mathTotalScore += math;
            englishTotalScore += english;
        }

        void ShowBase(){
            cout << "Name: " << name << endl;
            cout << "Number: " << num << endl;
            cout << "Math Score: " << mathScore << endl;
            cout << "English Score: " << englishScore << endl;
        }

        static void Showstatic(){
        cout<<"count: "<<count<<endl;
        cout<<"mathTotalScore: "<<mathTotalScore<<endl;
        cout<<"englishTotalScore: "<<englishTotalScore<<endl;
        }
};
int Student::count = 0;
int Student::mathTotalScore =0;
int Student::englishTotalScore =0;

int main(){
    Student obj1("李明",1101,98,80);
    obj1.ShowBase();
    Student obj2("王杰",1102,96,89);
    obj2.ShowBase();
    Student obj3("吴世宏",1103,86,98);
    obj3.ShowBase();
    Student::Showstatic();
}