#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// 枚举数字类型
typedef enum{
   EMPTY, ACE = 1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING,
} RankType;
// 枚举花色类型
typedef enum{
    CLUB,DIAMOND,HEART,SPADE
} CardType;
// 定义结构体
struct Card{
    RankType rank;
    CardType type;
};
//重载<<运算符，输出Card结构体信息
ostream& operator<<(ostream& os, const Card& card){
    switch(card.type){
        case CLUB:
        os << "梅花";
        break;
        case DIAMOND:
        os << "方块";
        break;
        case HEART:
        os << "红桃";
        break;
        case SPADE:
        os << "黑桃";
        break;
    }
    switch(card.rank){
        case ACE:
        os << "A";
        break;
        case JACK:
        os << "J";
        break;
        case  QUEEN:
        os << "Q";
        break;
        case KING:
        os << "K";
        break;
        default:
        os << (int)card.rank;
        break;
    }
    return os;
}
class GameOf21Point{

private:
    Card deck [52]; // 定义牌堆
    int dealPos; // 定义发牌位置
    Card hands [8][21];//hands[0]是庄家
    int numOfCard[8];// 扑克牌数目
    int numOfAce[8]={0}; // 玩家手中A的数目
    int totalScore[8]={0}; // 玩家总分
    int blackJack[8]={0}; // 玩家21点分
    string name[8];
    int numOfPlayer;

    bool isAlive[8]={false};     // 定义玩家是否活着
    bool isContinue[8]={false};  // 定义玩家是否继续游戏
 
    void Shuffle(); // 定义洗牌函数
    int GetTotalScore(Card hand[21],int n); // 定义计算总分函数
    void ShowStatus(int num,bool hideFirstCardAndTotalScore); // 定义显示手牌函数
    Card DealOneCard(){return deck[dealPos++];} // 定义发牌函数

public:
    GameOf21Point(){};
    virtual ~GameOf21Point(){};
    void Game();
};
void GameOf21Point::Shuffle(){
    // 定义洗牌算法
    //先生成标准排序的52张牌
    for (int i = 0; i < 52; i++) {
        deck[i].rank = (RankType)(i%13+1);
        deck[i].type = (CardType)(i%4);
    }    
    //然后将牌堆打乱
    for(int i=0;i<52;i++){
        int pos = rand()%52;
        Card temp = deck[i];
        deck[i] = deck[pos];
        deck[pos] = temp;
    }
}
int GameOf21Point::GetTotalScore(Card hand[21],int n){
    totalScore[n] = 0;
    numOfAce[n] = 0;
    for(int k=0;k<numOfCard[n];k++){
        if(hand[k].rank == ACE){
            totalScore[n] += 11;
            numOfAce[n]++;
        }
        else if(hand[k].rank >= 10)
            totalScore[n] += 10;
        else
            totalScore[n] += hand[k].rank;
    }
    while(totalScore[n]>21&&numOfAce[n]>0){
        totalScore[n]-=10;
        numOfAce[n]--;
    }
 
    return totalScore[n];
}
void GameOf21Point::ShowStatus(int num,bool hideFirstCardAndTotalScore){
    cout << name[num]<< "手牌:"<< endl;
    if(hideFirstCardAndTotalScore == false){
        for(int i=0;i<numOfCard[num];i++){
            cout <<"第"<< i+1<<"张牌："<<hands[num][i]<<endl;
        }
        GetTotalScore(hands[num],num);
        cout <<"总分为:"<<totalScore[num]<<endl;
    if(totalScore[num]>21){
        isAlive[num] = false; // 玩家淘汰
        cout<<name[num]<<"的牌爆掉了"<<endl;    
    }   
    }
    else{
            cout << "第1张牌：<隐藏>"<<endl;
        for(int i=1;i<numOfCard[num];i++){
            cout <<"第"<< i+1<<"张牌："<<hands[num][i]<<endl;
        }
    }
}
void GameOf21Point::Game(){
//初始化阶段
    name[0] = "庄家"; // 定义庄家名字
    cout<<"欢迎来到21点游戏"<<endl;
    cout<<"请输入玩家人数(1-7):";
    cin>>numOfPlayer;
    while(numOfPlayer<1 || numOfPlayer>7){
        cout<<"人数输入错误，请重新输入"<<endl;
        cout<<"请输入玩家人数(1-7):";
        cin>>numOfPlayer;
    }
    for(int i=1;i<=numOfPlayer;i++){
        cout<<"请输入玩家"<<i<<"的名字:";
        cin>>name[i];
    }    

    // 开始游戏
    Shuffle(); // 进行洗牌
    dealPos = 0; // 重置发牌位置
    for(int i=0;i<=numOfPlayer;i++){
        numOfCard[i] = 0; // 重置其他玩家手牌数目
        for(int j=0;j<21;j++){
        hands [i][j].rank=EMPTY; //重置手牌
        isAlive[i] = true; // 其他玩家默认活着
        isContinue[i] = true; // 其他玩家默认继续游戏
        }
    }
//初始抽牌阶段    
    for(int i=0;i<=numOfPlayer;i++){
        for(int j=0;j<2;j++)
        {
            hands[i][j] = DealOneCard(); // 发两张牌
            numOfCard[i]++; // 记录手牌数目
        }
    }        
    cout<<endl;
    ShowStatus(0,true); // 显示庄家初始状态
    cout<<endl;

    for(int i=1;i<=numOfPlayer;i++){
        ShowStatus(i,false); // 显示其他玩家初始状态
        cout<<endl;
    }
//判断一手blackjack
    for(int i=0;i<=numOfPlayer;i++){
        if(totalScore[i] == 21){
            blackJack[i] = 1; // 玩家21点分
    }
}
//开始游戏阶段
    cout<<"玩家阶段开始"<<endl;
    bool gameContinue=true;
    do{
        gameContinue = false;
        //检测玩家是否存活且继续抽牌
        for(int i=1;i<=numOfPlayer;i++){
             // 默认不继续游戏除非有玩家还能抽牌
            if(isAlive[i] == true && isContinue[i] == true){
                cout <<name[i]<<":"<< "选择是否抽牌(y/n)"<<endl;
                char answer;
                do{
                cin >> answer;
                switch(answer){
                    case 'y':
                    hands[i][numOfCard[i]] = DealOneCard(); // 发一张牌
                    numOfCard[i]++; // 记录手牌数目
                    ShowStatus(i,false); // 显示玩家状态
                    break;
                    case 'n':
                    isContinue[i] = false; // 玩家不再抽牌
                    break;
                    default:
                    cout << "输入错误，请重新输入"<<endl;
                    break;
                }
                }while(answer!='y' && answer!='n');
            } 
        }
        //检测抽牌后玩家是否存活且能抽牌
        for(int i=1;i<=numOfPlayer;i++){
            
            if(isAlive[i] == true && isContinue[i] == true){
                gameContinue = true; // 继续游戏
            }
        }
    }while(gameContinue == true);

//结算阶段    
    cout<<endl;
    cout<<"玩家行动结束"<<endl;
    cout<<"庄家行动"<<endl;

    ShowStatus(0,false); // 显示庄家状态
    while(totalScore[0]<17||numOfAce[0]>0){
        cout<<"庄家摸牌"<<endl;
        hands[0][numOfCard[0]] = DealOneCard(); // 庄家发一张牌
        numOfCard[0]++; // 记录手牌数目
        ShowStatus(0,false); // 显示庄家状态
    }


}
int main(){
    srand(time(0)); // 随机数种子
    GameOf21Point game;
    game.Game();
    return 0;
}