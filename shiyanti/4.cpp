//可以增加退出确认机制多次游戏，记录分数
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
enum GameStatus {
    WIN,
    LOSE,
    CONTINUE
};
int RollDice() {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;
    return dice1 + dice2;
}
void Game() {
    srand(time(0));
    int sum = RollDice();
    cout << "首次投掷点数是：" << sum << endl;
    int myPoint = 0;
    GameStatus status;
    switch(sum){
        case 7:case 11:
        status = WIN;
        break;
        case 2:case 3:case 12:
        status = LOSE;
        break;
        default:
        status = CONTINUE;
        myPoint = sum;
        cout <<"继续游戏，你的目标点数是："<<myPoint<<endl;
        break;
    }
    while(status == CONTINUE){
        cout<<"按Enter继续游戏..."<<endl;
        cin.ignore();
        sum = RollDice();
        cout << "你当前的点数是：" << sum << endl;
        if(sum == myPoint){
            status = WIN;
        }else if(sum == 7){
            status = LOSE;
        }
    }
    if(status == WIN){
        cout << "你赢了！" << endl;
    }else{
        cout << "你输了！" << endl;
    }
}
void Help(){
    cout<<"掷骰子游戏规则"<<endl;
    cout<<"1.：初次掷骰子，如果点数为7或11，则你赢；其他情况，你继续游戏，直到你达到目标点数，你赢。"<<endl;
    cout<<"2.：如果点数为2，3，12，则你输；"<<endl;
    cout<<"3.：其它点数作为目标点，玩家继续掷骰子"<<endl;
    cout<<"4.：如果掷出7，则你输。"<<endl;
}
void Run() {
    int choice;
    do {
        cout << "1.开始游戏" << endl;
        cout << "2.帮助" << endl;
        cout << "3.退出" << endl;
        cout << "请选择：";
        cin >> choice;
        switch (choice) {
            case 1:
                Game();
                break;
            case 2:
                Help();
                break;
            case 3:
                cout << "游戏结束，再见！" << endl;
                break;
            default:
                cout << "输入错误，请重新输入！" << endl;
                break;
        }
    } while (choice != 3);
}
int main() {
    Run();
    return 0;
}