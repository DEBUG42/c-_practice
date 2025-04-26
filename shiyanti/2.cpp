#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

struct TelephoneType {
    bool delTag;
    unsigned int seat;
    char name[16];
    char teleNO[18];
};

class TelephoneBook {
private:
    fstream file;
    void AddData();
    void DeleteData();
    void SearchData();
    void UpdateData();
    void Pack();
public:
    TelephoneBook();
    virtual ~TelephoneBook() { if (file.is_open()) file.close(); }
    void Run();
};

TelephoneBook::TelephoneBook() {
    ifstream iFile("telph.txt");
    if (iFile.fail()) {
        ofstream oFile("telph.txt");
        if (oFile.fail())
            throw runtime_error("打开文件失败！");
        oFile.close();
    } else {
        iFile.close();
    }
    file.open("telph.txt", ios::in | ios::out | ios::binary);
    if (file.fail())
        throw runtime_error("打开文件失败！");
}

void TelephoneBook::AddData() {
    TelephoneType data = {false}; // 初始化 delTag 为 false
    cout << "请输入序号：";
    cin >> data.seat;
    cin.ignore(); // 忽略前一次输入留下的换行符
    cout << "请输入姓名：";
    cin.getline(data.name, 16); // 从标准输入读取一行字符，存储到data.name中，最多读取15个字符（留一个字符给结束符'\0'）
    cout << "请输入电话号码："; // 提示用户输入电话号码
    cin.getline(data.teleNO, 18); // 从标准输入读取一行字符，存储到data.teleNO中，最多读取17个字符（留一个字符给结束符'\0'）
    file.seekp(0, ios::end);
    file.write((char*)&data, sizeof(data));
    cout << "添加成功！" << endl;
}

void TelephoneBook::Run() {
    int select;
    do {
        cout << "请选择" << endl;
        cout << "1.增加数据" << endl;
        cout << "2.更新数据" << endl;
        cout << "3.查询数据" << endl;
        cout << "4.删除数据" << endl;
        cout << "5.重组文件" << endl;
        cout << "6.退出" << endl;
        cin >> select;
        while (cin.get() != '\n'); // 清空输入缓冲区
        switch (select) {
            case 1:
                AddData();
                break;
            case 2:
                UpdateData();
                break;
            case 3:
                SearchData();
                break;
            case 4:
                DeleteData();
                break;
            case 5:
                Pack();
                break;
            case 6:
                break;
            default:
                cout << "输入错误！" << endl;
        }
    } while (select != 6);
}

void TelephoneBook::DeleteData() {
    TelephoneType telph = {false}; // 初始化 delTag 为 false
    unsigned int seat;
    cout << "请输入要删除的电话序号：";
    cin >> seat;
    file.seekg(0);
    file.read((char*)&telph, sizeof(telph));
    while (!file.eof()) {
        if (telph.seat == seat && !telph.delTag)
            break;
        file.read((char*)&telph, sizeof(telph));
    }
    if (!file.eof()) {
        cout << "被删除记录为：" << endl;
        cout << setw(3) << "序号" << setw(18) << "姓名" << setw(18) << "电话号码" << endl;
        cout << setw(3) << telph.seat << setw(18) << telph.name << setw(18) << telph.teleNO << endl;
        telph.delTag = true;
        file.seekp(-sizeof(telph), ios::cur);
        file.write((char*)&telph, sizeof(telph));
        cout << "删除成功！" << endl;
    } else {
        cout << "删除失败！" << endl;
        file.clear(); // 清除错误标志
    }
}

void TelephoneBook::SearchData() {
    TelephoneType telph = {false}; // 初始化 delTag 为 false
    unsigned int seat;
    cout << "请输入要查询的电话序号：";
    cin >> seat;
    file.seekg(0);
    file.read((char*)&telph, sizeof(telph));
    while (!file.eof()) {
        if (telph.seat == seat && !telph.delTag)
            break;
        file.read((char*)&telph, sizeof(telph));
    }
    if (!file.eof()) {
        cout << "查询记录为：" << endl;
        cout << setw(3) << "序号" << setw(18) << "姓名" << setw(18) << "电话号码" << endl;
        cout << setw(3) << telph.seat << setw(18) << telph.name << setw(18) << telph.teleNO << endl;
    } else {
        cout << "查询失败！" << endl;
        file.clear(); // 清除错误标志
    }
}

void TelephoneBook::UpdateData() {
    TelephoneType telph = {false}; // 初始化 delTag 为 false
    unsigned int seat;
    cout << "请输入要更新的电话序号：";
    cin >> seat;
    cin.ignore(); // 忽略前一次输入留下的换行符
    file.seekg(0);
    file.read((char*)&telph, sizeof(telph));
    while (!file.eof()) {
        if (telph.seat == seat && !telph.delTag)
            break;
        file.read((char*)&telph, sizeof(telph));
    }
    if (!file.eof()) {
        cout << "当前记录为：" << endl;
        cout << setw(3) << "序号" << setw(18) << "姓名" << setw(18) << "电话号码" << endl;
        cout << setw(3) << telph.seat << setw(18) << telph.name << setw(18) << telph.teleNO << endl;
        cout << "请输入新的姓名：";
        cin.getline(telph.name, 16);
        cout << "请输入新的电话号码：";
        cin.getline(telph.teleNO, 18);
        file.seekp(-sizeof(telph), ios::cur);
        file.write((char*)&telph, sizeof(telph));
        cout << "更新成功！" << endl;
    } else {
        cout << "更新失败！" << endl;
        file.clear(); // 清除错误标志
    }
}

void TelephoneBook::Pack() {
    file.clear();
    file.seekg(0);
    TelephoneType telph = {false}; // 初始化 delTag 为 false
    vector<TelephoneType> validRecords;
    while (file.read((char*)&telph, sizeof(telph))) {
        if (!telph.delTag) {
            validRecords.push_back(telph);
        }
    }
    file.clear();
    file.seekp(0);
    for (const auto& record : validRecords) {
        file.write((char*)&record, sizeof(record));
    }
    file.flush();
    // 将文件大小调整为有效记录的大小，删除多余的记录
    // 将文件大小调整为有效记录的大小，删除多余的记录
file.seekp(validRecords.size() * sizeof(TelephoneType));
file.tellp(); // 获取当前写位置
file.close();
file.open("your_filename_here", std::ios::out | std::ios::in); // 重新打开文件，注意要使用正确的文件名
file.seekp(0, std::ios::end); // 移动到文件末尾
file.close(); // 关闭文件，截断文件大小到当前写位置

    file.close();
    cout << "重组文件成功！" << endl;
}

int main() {
    try {
        TelephoneBook book;
        book.Run();
    } catch (const exception& e) {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}
