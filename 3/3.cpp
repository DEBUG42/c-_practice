#include <iostream>
#include <string.h>
using namespace std;
class Person{
    protected:
    char name[20];
    int age;
    char sex[4];
    public:
    Person(const char* n, int a, const char* s)
    {
        strcpy(name, n);
        age = a;
        strcpy(sex, s);
    }
    virtual void showInfo()const{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
    } 
};
class Teacher:public Person{
protected:
    char title[10];
    public:
    Teacher(const char* n, int a, const char* s, const char* t) : Person(n, a, s){
        strcpy(title, t);
        strcpy(name, n);
        age = a;
        strcpy(sex, s);
    }
    void showInfo()const{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Title: " << title << endl;
    }
};
class Cadre:public Person{
protected:
    char post[10];
    public:
    Cadre(const char* n, int a, const char* s, const char* p) : Person(n, a, s){
        strcpy(post, p);
        strcpy(name, n);
        age = a;
        strcpy(sex, s);
    }
    void showInfo()const{
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sex: " << sex << endl;
        cout << "Post: " << post << endl;
    }
};
class TeacherCadre:virtual public Teacher,virtual public Cadre{
    protected:
    int wages;
    public:
    TeacherCadre(const char* n, int a, const char* s, const char* t, const char* p, int w) : Teacher(n, a, s, t), Cadre(n, a, s, p){
        wages = w;
        strcpy(Teacher::name, n);    
        Teacher::age = a;
        strcpy(Teacher::sex, s);
        strcpy(post, p);
        strcpy(title, t);
    }
    void showInfo()const{
        cout << "Name: " << Teacher::name << endl;
        cout << "Age: " << Teacher::age << endl;
        cout << "Sex: " << Teacher::sex << endl;
        cout << "Title: " << title << endl;
        cout << "Post: " << post << endl;
        cout << "Wages: " << wages << endl;
        }
};
int main(){

}