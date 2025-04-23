#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Student{
    private:
    int no;
    char name[16];
    int score;
    public:
    void input(); // 输入学生信息
    void output(); // 输出学生信息
};
class StudentManage{
    private:
    static void Write(); // 将学生信息写入文件
    static void Show(); // 从文件中读取并显示学生信息
    public:
    static void Run(); // 运行学生信息管理程序
};
void StudentManage::Write(){
    Student stu;
    ofstream outfile("student.dat",ios::app);
    stu.input();
    outfile.write((char*)&stu,sizeof(stu));
    outfile.close();
}

void StudentManage::Show(){
    ifstream infile("student.dat",ios::in);
    Student stu;
    while(infile.read((char*)&stu,sizeof(stu))){
        stu.output();
    }
    infile.close();
}

void StudentManage::Run(){
    int choice;
    do{
        cout<<"1.录入学生信息"<<endl;
        cout<<"2.显示学生信息"<<endl;
        cout<<"3.退出"<<endl;
        cout<<"请选择(1/2/3):";
        cin>>choice;
        switch(choice){
            case 1:Write();break;
            case 2:Show();break;
            case 3:break;
            default:cout<<"输入错误"<<endl;
        }
    }while(choice!=3);
}

int main(){
    StudentManage::Run(); // 启动学生信息管理程序
    return 0;
}