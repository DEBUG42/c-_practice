#include<iostream>
#include<cstring>
using namespace std;
class MyString{
    private:
    char *str;
    public:
    // 默认构造函数
    MyString(){};
    // 构造函数，初始化字符串
    MyString(const char *s){
        // 动态分配内存以存储输入字符串及其结束符
        str = new char[strlen(s)+1];
        // 将输入字符串复制到新分配的内存中
        strcpy(str, s);
    }
    // 重载加法运算符，实现字符串连接
    MyString  operator+(const MyString &rhs){
        // 动态分配内存以存储新字符串及其结束符
        char *newStr = new char[strlen(str)+strlen(rhs.str)+1];
        // 将原字符串和rhs的字符串连接起来
        strcpy(newStr, str);
        strcat(newStr, rhs.str);
        // 释放原有内存
        return MyString(newStr);
    }
    // 重载等于运算符，比较两个字符串是否相等
    bool operator==(const MyString &rhs){
        return strcmp(rhs.str,str) == 0;
    }
    // 重载不等于运算符，比较两个字符串是否不相等
    bool operator!=(const MyString &rhs){
        return strcmp(rhs.str,str) != 0;
    }

    // 重载赋值运算符，实现字符串复制
    MyString &operator=(const MyString &rhs){
        // 释放原有内存
        delete[] str;
        // 复制rhs的字符串到新内存中
        str = new char[strlen(rhs.str)+1];
        strcpy(str, rhs.str);
        return *this;
    }
    // 析构函数，释放内存
    ~MyString(){
        // 释放内存
        delete[] str;
    }
    // 重载输出运算符，实现字符串输出
    friend ostream &operator<<(ostream &os, const MyString &s){
        os << s.str;
        return os;
    }
};
int main(){
    // 创建MyString对象并初始化
    MyString s1("Hello");
    MyString s2(" World");
    // 使用加法运算符连接两个字符串
    MyString s3 = s1 + s2;
    // 输出s1
    cout << "s1:"<< s1 << endl;
    // 输出s2
    cout << "s2:"<< s2 << endl;
    // 输出连接后的s3
    cout << "s3(s1+s2):"<< s3 << endl;

    // 使用等于运算符比较s1和s2是否相等
    if(s1 == s2)
        cout << "s1 == s2" << endl;
    else
        cout << "s1 != s2" << endl;
    return 0;
}