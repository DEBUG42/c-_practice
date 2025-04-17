#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// 游戏状态枚举，定义了游戏的三种可能结果：赢、输、继续
enum GameStatus {
    WIN,
    LOSE,
    CONTINUE
};

// 模拟掷骰子，返回两个骰子点数之和
int RollDice() {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}

// 游戏主逻辑函数
void Game() {
    srand(time(0)); // 初始化随机数生成器种子
    int sum = RollDice(); // 掷骰子并获取点数之和
    cout << "首次投掷点数是：" << sum << endl; // 输出首次投掷的结果
    int myPoint = 0; // 初始化玩家的目标点数
    GameStatus status; // 定义游戏状态变量

    // 根据首次投掷的点数之和确定游戏状态
    switch(sum){
        case 7:case 11:
        status = WIN; // 点数为7或11时，玩家赢
        break;
        case 2:case 3:case 12:
        status = LOSE; // 点数为2，3或12时，玩家输
        break;
        default:
        status = CONTINUE; // 其他情况游戏继续
        myPoint = sum; // 设置玩家的目标点数为首次投掷的点数之和
        cout <<"继续游戏，你的目标点数是："<<myPoint<<endl; // 输出玩家的目标点数
        break;
    }

    // 游戏继续进行，直到玩家赢或输
    while(status == CONTINUE){
        cout<<"按Enter继续游戏..."<<endl; // 提示玩家按Enter继续
        cin.ignore(); // 等待玩家按下Enter
        sum = RollDice(); // 掷骰子并获取点数之和
        cout << "你当前的点数是：" << sum << endl; // 输出当前掷骰子的结果
        if(sum == myPoint){
            status = WIN; // 当前点数等于目标点数时，玩家赢
        }else if(sum == 7){
            status = LOSE; // 当前点数为7时，玩家输
        }
    }

    // 根据游戏状态输出最终结果
    if(status == WIN){
        cout << "你赢了！" << endl;
    }else{
        cout << "你输了！" << endl;
    }
}

// 输出游戏帮助信息
void Help(){
    cout<<"掷骰子游戏规则"<<endl;
    cout<<"1.：初次掷骰子，如果点数为7或11，则你赢；其他情况，你继续游戏，直到你达到目标点数，你赢。"<<endl;
    cout<<"2.：如果点数为2，3，12，则你输；"<<endl;
    cout<<"3.：其它点数作为目标点，玩家继续掷骰子"<<endl;
    cout<<"4.：如果掷出7，则你输。"<<endl;
}

// 运行游戏的主函数，提供游戏菜单供玩家选择
void Run() {
    int choice; // 定义玩家的选择变量
    do {
        cout << "1.开始游戏" << endl;
        cout << "2.帮助" << endl;
        cout << "3.退出" << endl;
        cout << "请选择：";
        cin >> choice; // 获取玩家的选择
        switch (choice) {
            case 1:
                Game(); // 玩家选择开始游戏
                break;
            case 2:
                Help(); // 玩家选择查看帮助信息
                break;
            case 3:
                cout << "游戏结束，再见！" << endl; // 玩家选择退出游戏
                break;
            default:
                cout << "输入错误，请重新输入！" << endl; // 玩家输入了无效选项
                break;
        }
    } while (choice != 3); // 循环直到玩家选择退出游戏
}

// 程序入口点
int main() {
    Run(); // 调用运行游戏的主函数
    return 0; // 返回0表示程序正常结束
}