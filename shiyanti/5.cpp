#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 日期类，用于表示和操作日期
class Date {
private:
    int year;  // 年份
    int month; // 月份
    int day;   // 日

public:
    // 构造函数，初始化日期，默认为公元1年1月1日
    Date(int y = 1, int m = 1, int d = 1) : year(y), month(m), day(d) {}

    // 设置年份
    void SetYear(int y) { year = y; }
    // 设置月份
    void SetMonth(int m) { month = m; }
    // 设置日
    void SetDay(int d) { day = d; }
    // 获取年份
    int GetYear() const { return year; }
    // 获取月份
    int GetMonth() const { return month; }
    // 获取日
    int GetDay() const { return day; }

    // 判断是否为闰年
    static bool IsLeapYear(int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // 获取某年总天数
    static int GetYearDays(int y) {
        return IsLeapYear(y) ? 366 : 365;
    }

    // 获取某年某月总天数
    static int GetMonthDays(int y, int m) {
        if (m == 2) {
            return IsLeapYear(y) ? 29 : 28;
        } else if (m == 4 || m == 6 || m == 9 || m == 11) {
            return 30;
        } else {
            return 31;
        }
    }

    // 将日期转换为该日期是公元元年1月1日以来的天数
    static int DateToNum(const Date &d) {
        int days = 0;
        // 计算完整年份的天数
        for (int y = 1; y < d.year; y++) {
            days += GetYearDays(y);
        }
        // 计算当年完整月份的天数
        for (int m = 1; m < d.month; m++) {
            days += GetMonthDays(d.year, m);
        }
        // 加上当月天数
        days += d.day - 1;
        return days;
    }

    // 将天数转换为日期
    static Date NumToDate(int n) {
        int y = 1, m = 1, d = 1;
        
        // 处理负数天数的情况
        if (n < 0) {
            y = 0;
            while (n < 0) {
                y--;
                n += GetYearDays(y);
            }
            m = 12;
            while (n < 0) {
                m--;
                n += GetMonthDays(y, m);
            }
            d = GetMonthDays(y, m) + n + 1;
            return Date(y, m, d);
        }

        while (n >= GetYearDays(y)) {
            n -= GetYearDays(y);
            y++;
        }
        while (n >= GetMonthDays(y, m)) {
            n -= GetMonthDays(y, m);
            m++;
        }
        d = n + 1;
        return Date(y, m, d);
    }

    // 计算某日期是星期几
    static int Week(const Date &d) {
        // 修正基准日计算，假设公元1年1月1日是星期一
        // 修正后的公式应该是 (DateToNum(d) + 1) % 7
        return (DateToNum(d)+1) % 7; // 0=周日,1=周一,...,6=周六
    }

    // 重载加法运算符，增加指定天数
    Date operator+(int days) {
        int totalDays = DateToNum(*this) + days;
        return NumToDate(totalDays);
    }

    // 重载减法运算符，减少指定天数
    Date operator-(int days) {
        int totalDays = DateToNum(*this) - days;
        return NumToDate(totalDays);
    }

    // 打印单个月份的日历
    static void PrintMonthCalendar(int year, int month) {
        string monthNames[] = {"", "一月", "二月", "三月", "四月", "五月", "六月", 
                              "七月", "八月", "九月", "十月", "十一月", "十二月"};
        
        cout << "\n" << year << "年 " << monthNames[month] << "\n";
        cout << "日 一 二 三 四 五 六\n";
        
        Date firstDay(year, month, 1);
        int firstWeekDay = Week(firstDay);
        int daysInMonth = GetMonthDays(year, month);
        
        // 打印初始空格
        for (int i = 0; i < firstWeekDay; i++) {
            cout << setw(3) << " ";
        }
        
        // 打印日期
        for (int day = 1; day <= daysInMonth; day++) {
            cout << setw(2) << day << " ";
            if ((day + firstWeekDay) % 7 == 0 || day == daysInMonth) {
                cout << "\n";
            }
        }
    }

    // 打印整年日历
    static void PrintYearCalendar(int year) {
        for (int month = 1; month <= 12; month++) {
            PrintMonthCalendar(year, month);
        }
    }
};

// 主函数，输入年份并打印该年的日历
int main() {
    char isContinue;
    do{
    int year;
    cout << "请输入年份(公元后): ";
    cin >> year;
    
    if (year <= 0) {
        cout << "无效的年份输入！" << endl;
        return 1;
    }
    
    Date::PrintYearCalendar(year);
    do{
    cout << "是否继续?(y/n): ";
    cin >> isContinue;
    switch(isContinue){
        case 'y':
            break;
        case 'n':
            return 0;
        default:
            cout << "无效的输入！" << endl;
    }
    }while(isContinue !='n'&& isContinue!='y');
    }while(isContinue !='n');

}


