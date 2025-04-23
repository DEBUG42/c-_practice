#include <iostream>
#include <fstream>
using namespace std;
// 主函数，程序入口
int main(){
    ofstream outfile;
    // 打开一个名为 "test.txt" 的文件用于写入
    outfile.open("test.txt",ios::out);
    // 向文件写入字符串 "test file input" 并换行
    outfile <<"test file input"<<endl;
    // 向文件写入字符串 "5116888!" 并换行
    outfile <<"5116888!"<<endl;
    // 关闭文件
    outfile.close();

    ifstream infile;
    // 打开一个名为 "test.txt" 的文件用于读取
    infile.open("test.txt",ios::in);
    string str;
    
    // 逐行读取文件内容并输出到控制台
    while(getline(infile,str)){
        cout<<str<<endl;
    }
    // 关闭文件
    infile.close();
    // 返回0，表示程序正常结束
    return 0;
}