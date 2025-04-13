#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
typedef enum{
    ROCK,SCISSOR,CLOTH,DISPLAY,HELP,QUIT
}SelectType;
typedef enum{
    WIN,LOSE,TIE
}ResultType;

class GameOfRockScissorCloth {
    private:
        static const string SelectString[3];
        SelectType select1;//人的选择
        SelectType select2;//计算机的选择
        ResultType result;
        int num1;//人输入的
        int num2;//计算机随机数
        bool isContinue = true;
        static int score1;
        static int score2;
    public:   
        void Read();
        void random_num();
        bool endGame(){
            return isContinue;
        }
        void Game(){
            //将num初始值转为其它数字
            Read();
            if(num1 == ROCK || num1 == SCISSOR || num1 == CLOTH){
                random_num();
            }

        }

};
int GameOfRockScissorCloth::score1 =0;
int GameOfRockScissorCloth::score2 =0;
const string GameOfRockScissorCloth::SelectString[3] = {"rock", "scissor", "cloth"};
void GameOfRockScissorCloth::Read(){   
            cout << "Please select your weapon: (1) rock, (2) scissor, (3) cloth, (4) display (5)help, (6) quit" << endl;
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
                    cout << "Your Score: " << score1 << endl;
                    cout << "Computer's Score: " << score2 << endl;
                    break;
                case HELP:
                    cout << "Help: You can choose rock, scissor, or cloth to play the game. The rules are simple: you have to choose either rock, scissor, or cloth. If both players choose the same object, it's a tie. If one player chooses rock and the other chooses scissor, the rock wins. If one player chooses scissor and the other chooses cloth, the scissor wins. If one player chooses cloth and the other chooses rock, the cloth wins." << endl;
                    break;
                case QUIT:
                    isContinue = false;
                    break;
                default:
                    cout << "Invalid input!" << endl;
                    break;
            }
        }
void GameOfRockScissorCloth::random_num(){
        //用时间戳生成随机数
        //设置种子  
        srand(time(0));  
        num2 = rand() % 3;
        cout <<"Your choice: "<<SelectString[num1]<<endl;
        cout << "Computer's choice: "<<SelectString[num2]<<endl;
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
            cout << "You win!" << endl;
            score1++;
        }
        else if(result == LOSE){
            cout << "You lose!" << endl;
            score2++;
        }
        else{
            cout << "It's a tie!" << endl;
        }
}

int main() {
    GameOfRockScissorCloth GameOfRockScissorCloth;
    do{
        GameOfRockScissorCloth.Game();

    }while(GameOfRockScissorCloth.endGame());
    return 0;
}