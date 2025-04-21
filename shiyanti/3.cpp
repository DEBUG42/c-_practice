#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <chrono>
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
using namespace std;

// 定义选择类型的枚举
typedef enum{
    ROCK,SCISSOR,CLOTH,DISPLAY,HELP,QUIT
}SelectType;

// 定义结果类型的枚举
typedef enum{
    WIN,LOSE,TIE
}ResultType;

// 剪刀石头布游戏类
class GameOfRockScissorCloth {
    private:
        // 静态常量数组，存储选择的字符串表示
        static const string SelectString[3];
        // 人的选择
        SelectType select1;
        // 计算机的选择
        SelectType select2;
        // 游戏结果
        ResultType result;
        // 人输入的选择数字
        int num1;
        // 计算机随机选择的数字
        int num2;
        // 游戏是否继续标志
        bool isContinue = true;
        // 静态变量，存储人的总得分
        static int score1;
        // 静态变量，存储计算机的总得分
        static int score2;
    public:   
        // 读取用户输入的选择
        void Read();
        // 生成计算机随机选择
        void random_num();
        // 判断游戏是否继续
        void endGame(){
            isContinue = false;
        }
        bool is_Continue(){
            return isContinue;
        }
        // 游戏主逻辑函数
        void Game(){
            // 将num初始值转为其它数字
            Read();
            if(num1 == ROCK || num1 == SCISSOR || num1 == CLOTH){
                random_num();
            }

        }
        void displayScore(){
            cout << "你的得分: " << score1 << endl;
            cout << "电脑的得分: " << score2 << endl;
        }

};

int GameOfRockScissorCloth::score1 =0;
int GameOfRockScissorCloth::score2 =0;
const string GameOfRockScissorCloth::SelectString[3] = {"石头", "剪刀", "布"};

// 读取用户输入的选择并进行处理
void GameOfRockScissorCloth::Read(){   
            cin >> num1;
            num1-=1;
            select1 = (SelectType)num1;
            switch(select1){
                case ROCK:
                    num1=0;
                    break;
                case SCISSOR:
                    num1=1;
                    break;
                case CLOTH:
                    num1=2;
                    break;
                case DISPLAY:
                    displayScore();
                    break;
                case HELP:
                    cout << "帮助：输入数字1-3选择你要出的拳，输入数字4显示当前得分，输入数字5帮助，输入数字6退出游戏." << endl;
                    break;
                case QUIT:
                    endGame();
                    cout <<endl;
                    cout <<"再见"<<endl;
                    displayScore();
                    break;
                default:
                    cout << "输入错误！" << endl;
                    break;
            }
        }

// 生成计算机随机选择并计算结果
void GameOfRockScissorCloth::random_num(){

        srand(time(0));
        num2 = rand() % 3;
        cout <<"你的出拳: "<<SelectString[num1]<<endl;
        cout << "电脑的出拳: "<<SelectString[num2]<<endl;
        //计算结果
        if(num1 == 0 && num2 == 0){
            result = TIE;
        }
        if(num1 == 1 && num2 == 1)
        {
            result = TIE;
        }
        if(num1 == 2 && num2 == 2)
        {
            result = TIE;
        }
        if(num1 == 0 && num2 == 1)
        {
            result = WIN;
        }
        if(num1 == 1 && num2 == 2)
        {
            result = WIN;
        }
        if(num1 == 2 && num2 == 0)
        {
            result = WIN;
        }
        if(num1 == 0 && num2 == 2)
        {
            result = LOSE;
        }
        if(num1 == 1 && num2 == 0)
        {
            result = LOSE;
        }
        if(num1 == 2 && num2 == 1)
        {
            result = LOSE;
        }
        //更新分数
        if(result == WIN){
            cout << "你赢了!" << endl;
            score1++;
        }
        else if(result == LOSE){
            cout << "你输了!" << endl;
            score2++;
        }
        else{
            cout << "平局!" << endl;
        }
}

atomic<bool> isContinue1(true);
mutex mtx;
void countdown(int seconds,GameOfRockScissorCloth& GameOfRockScissorCloth){
    cout << "请在倒计时内做出你的选择: (1) 石头, (2) 剪刀, (3) 布, (4) 显示分数 (5)帮助, (6) 退出游戏" << endl;
    for(int i=seconds;i>=1&&isContinue1;i--){
        lock_guard<mutex> lock(mtx);
        cout <<"还剩"<<i<<"秒"<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
    if(isContinue1){
        lock_guard<mutex> lock(mtx);
        cout<<endl;
        cout << "时间到！" << endl;
        GameOfRockScissorCloth.displayScore();
        cout <<"按任意键退出游戏"<<endl;
        GameOfRockScissorCloth.endGame();
        isContinue1 = false;
    }
}

void listenForInput(GameOfRockScissorCloth& GameOfRockScissorCloth){
    while (isContinue1 && cin.peek() == '\n') { // 检查是否还有时间并且没有输入
        cin.ignore(); // 忽略缓冲区中的换行符
    }
    if (isContinue1) {
        GameOfRockScissorCloth.Game();
        //换两行方便显示
        cout << endl;
        cout << endl;
        isContinue1 = false;
    }
}

// 主函数，游戏入口
int main() {
    SetConsoleOutputCP(65001); // 设置输出编码为UTF-8
    GameOfRockScissorCloth GameOfRockScissorCloth;

    cout << "欢迎来到剪刀石头布游戏!" << endl;
    this_thread::sleep_for(chrono::seconds(1));

    do{
        isContinue1 = true;
        thread countdownThread(countdown, 5 ,ref(GameOfRockScissorCloth));
        thread inputThread(listenForInput,ref(GameOfRockScissorCloth));

        
        countdownThread.join();
        inputThread.join();

    }while(GameOfRockScissorCloth.is_Continue());
    return 0;
}