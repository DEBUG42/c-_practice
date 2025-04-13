#include <iostream>
using namespace std;
class Staff{
    protected:
    int num;
    char name[18];
    double rateOfAtttend;
    double basicSal;
    double prize;
    static int count;
    public:
    Staff(){}

    virtual void input()
    {
        num = ++count;
        cout <<"请输入编号为"<<num<<"号员工的姓名"<<endl;
        cout <<"姓名";
        cin >>name;
        cout <<"基本工资";
        cin >>basicSal;
        cout <<"奖金";
        cin >>prize;
        cout<<"出勤率（0~1）";
        cin >>rateOfAtttend;
    }
    virtual void Output()const {
        cout << "编号为"<<num<<"号员工的基本信息如下："<<endl;
        cout << "姓名：" << name << endl;
        cout << "基本工资：" << basicSal <<"元"<< endl;
        cout << "奖金：" << prize << "元" << endl;
        cout << "出勤率：" << rateOfAtttend*100 << "%" << endl;
    }
    void OUtputWage()const {
    cout <<"实发工资为"<<basicSal+prize*rateOfAtttend<<"元"<<endl;
    }
};
int Staff::count = 1000; // 静态变量初始化

class Saleman:public Staff{
    protected:
    double deductRate;
    int personAmount;
    public:
    Saleman(){};
    void input() override
    {
        Staff::input();
        cout<<"个人销售额";
        cin >> personAmount;
        cout<<"销售员提成比例（0~1）"<<endl;
        cin >> deductRate;
    }
    void Output()const override {
        Staff::Output();
        cout << "个人销售额：" << personAmount << "元" << endl;
        cout << "销售员提成比例：" << deductRate*100 << "%" << endl;
    }
    void OutputWage() {
        cout << "实发工资为" << basicSal + prize * rateOfAtttend + personAmount * deductRate << "元" << endl;
    }
};
class Manager:public Staff{
    protected:
    int totalAmount;
    double totalDeductRate;
    public:
    Manager(){};
    void input() override
    {
        Staff::input();
        cout<<"总销售额";
        cin >> totalAmount;
        cout<<"经理提成比例（0~1）"<<endl;
        cin >> totalDeductRate;
    }
    void Output()const override {
        Staff::Output();
        cout << "总销售额：" << totalAmount << "元" << endl;
        cout << "经理提成比例：" << totalDeductRate*100 << "%" << endl;
    }
    void OutputWage() {
        cout << "实发工资为" << basicSal + prize * rateOfAtttend + totalAmount * totalDeductRate << "元" << endl;
}
};
class SaleManager:virtual public Manager,virtual public Saleman{
    public:
    SaleManager(){};
    void input() override
    {
        Saleman::input();
        cout<<"总销售额";
        cin >> totalAmount;
        cout<<"经理提成比例（0~1）"<<endl;
        cin >> totalDeductRate;
    }
    void Output()const override {


        Saleman::Output();
        cout << "总销售额：" << totalAmount << "元" << endl;
        cout << "经理提成比例：" << totalDeductRate*100 << "%" << endl;

    }
    void OutputWage() {
        cout << "实发工资为" << Saleman::basicSal + Saleman::prize * Saleman::rateOfAtttend + personAmount * deductRate + totalAmount * totalDeductRate << "元" << endl;
    }
};

int main(){
    char flag ='Y';
    while (toupper(flag) == 'Y')     // 循环读取员工信息
    {
        cout<<"请选择录入类别（1.员工 2.销售员 3.经理 4.销售经理）"<<endl;
        int n;
        cin >> n;
        if(n==1)
        {
            Staff objStaff;
            objStaff.input();
            objStaff.Output();
            objStaff.OUtputWage();
        }
        else if(n==2)
        {
            Saleman objSales;
            objSales.input();
            objSales.Output();
            objSales.OutputWage();
        }
        else if(n==3)
        {
            Manager objManager;
            objManager.input();
            objManager.Output();
            objManager.OutputWage();
        }
        else if(n==4)
        {
            SaleManager objSalesManager;
            objSalesManager.input();
            objSalesManager.Output();
            objSalesManager.OutputWage();
        }
        else
        {
            cout<<"输入错误"<<endl;
        }
        cout<<"是否继续输入？（Y/N）"<<endl;
        cin >> flag;

    }
    system("PAUSE");
    return 0;
}