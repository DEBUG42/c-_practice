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
        int temp = days;
        while(temp > 0){
        // 检查是否为闰年二月
        if (month == 2  )
            { // 是否为闰年
                bool is_leap_year =(year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
                // 如果二月的天数加上临时天数超过29天
                if(day + temp > 28+is_leap_year)
                {
                    // 计算超出天数，并调整月份和年份
                    temp -= (28+is_leap_year - day);
                    day = 1;
                    month++;
                }
                else{
                    // 计算剩余天数
                    day += temp;
                    temp = 0;
                }
            }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
            { // 30天的月份
                if(day + temp > 30)
                {
                    // 计算超出天数，并调整月份
                    temp -= (30 - day);
                    day = 1;
                    month++;
                }
                else{
                    // 计算剩余天数
                    day += temp;
                    temp = 0;
                }
            }
        else{
            // 其他月份的天数
            if(day + temp > 31)
            {
                // 计算超出天数，并调整月份
                temp -= (31 - day);
                day = 1;
                month++;
                month %= 13;
                year += (month / 12);
            }
            else{
                // 计算剩余天数
                day += temp;
                temp = 0;
            }
        }    
   }
        NewDate.year = year;
        NewDate.month = month;
        NewDate.day = day;
        return NewDate;
    
    }

    // 重载减法运算符，用于在日期上减少指定的天数
    Date operator-(int days){
        Date NewDate;
        int temp = days;
        while(temp > 0){
            if( month == 1  ){
                if(day - temp <= 0)
                {
                    // 计算超出天数，并调整月份和年份
                    temp -= (day - 0);
                    day = 31;
                    month=12;
                    year--;
                }
                else{
                    // 计算剩余天数
                    day -= temp;
                    temp = 0;
                }
            }
            // 检查是否为闰年二月
            if (month == 3  ){
                 // 是否为闰年
                bool is_leap_year =(year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
                // 如果二月的天数减去临时天数小于0
                if(day - temp <= 0)
                {
                // 计算超出天数，并调整月份和年份
                temp -= (day - 0);
                day = 28+is_leap_year;
                month--;
                }
                else{
                    // 计算剩余天数
                    day -= temp;
                    temp = 0;
                }
            }
            if ( month == 2 || month == 4 || month == 6 || month == 8 || month == 9 || month == 11){
                if(day - temp <= 0)
                {
                    // 计算超出天数，并调整月份
                    temp -= (day - 0);
                    day = 31;
                    month--;
                }
                else{
                    // 计算剩余天数
                    day -= temp;
                    temp = 0;
                }
            }
            else{
                if(day - temp <= 0)
                {
                    // 计算超出天数，并调整月份
                    temp -= (day - 0);
                    day = 30;
                    month--;
                }
                else{
                    // 计算剩余天数
                    day -= temp;
                    temp = 0;
                }
            }
        }
        NewDate.year = year;
        NewDate.month = month;
        NewDate.day = day;
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