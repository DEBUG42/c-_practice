#include <iostream>
using namespace std;

// 日期类，用于表示和操作日期
class Date{
    private:
    int day, month, year; // 私有成员变量，分别表示日、月、年

    public:
    Date(){} // 默认构造函数

    // 构造函数，初始化日期为指定的年、月、日
    Date(int y, int m, int d):year(y), month(m), day(d){}

    // 重载加法运算符，用于在日期上增加指定的天数
    Date operator+(int days){
        Date NewDate;
        NewDate.day = day + days;
        NewDate.month = month;
        NewDate.year = year;
        return NewDate;
    }

    // 重载减法运算符，用于在日期上减少指定的天数
    Date operator-(int days){
        Date NewDate;
        NewDate.day = day - days;
        NewDate.month = month;
        NewDate.year = year;
        return NewDate;
    }

    // 重载输入流运算符，用于从输入流中读取日期
    friend istream& operator>>(istream& is, Date& d){
        is >> d.year >> d.month >> d.day;
        return is;
    }

    // 重载输出流运算符，用于将日期输出到输出流
    friend ostream& operator<<(ostream& os, const Date& d){
        os << d.year << "-" << d.month << "-" << d.day;
        return os;
    }
};
// 主函数，演示日期类的使用
int main(){
    Date date1(2023,10,15);
    cout << "Initial date: " << date1 << endl;
    Date date2 = date1 + 10;
    cout << "Date after adding 10 days: " << date2 << endl;
    Date date3 = date2 - 5;
    cout << "Date after subtracting 5 days: " << date3 << endl;
    cout << "Enter a date:(yyyy mm dd) ";
    Date date4;
    cin >> date4;
    cout << "You entered: " << date4 << endl;
    return 0;
}