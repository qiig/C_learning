#include<iostream>
#include<ctime>
#include<cstring>
using namespace std;

int sign[4][13] = {0}; // 记录牌型是否已发
string suits[4] = {"spades", "hearts", "clubs", "diamonds"};
string numbs[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
class playCards{
    public:
        playCards();
        ~playCards(){};
        void sendCards(int n);
        void PrintCards();
    private:
        int num; // 发牌张数
        string card[52];
};
playCards::playCards(){
    num = 0;
}
void playCards::sendCards(int n){
    int su, nu;
    num = n;
    memset(sign, 0, 4 * 13 * sizeof(int));
    srand(time(nullptr));
    for(int k = 0; k < n; ){
        su = rand() % 4;
        nu = rand() % 13;
        if(sign[su][nu] == 1) continue;
        else{
            card[k] = numbs[nu] + " of " + suits[su];
            sign[su][nu] = 1;
            k++;
        }
    }
}
void playCards::PrintCards(){
    for(int i = 0; i < num; i++){
        cout << card[i] << "  ";
    }
    cout << endl;
}
// main
int main(){
    int n;
    cout << "Input: ";
    while(cin >> n){
        if(n < 1){
            cout << "playCards ended. " << endl; break;
        } else if(n > 52){
            cout << "too many cards... input again: "; continue;
        } else{
            playCards cards;
            cards.sendCards(n);
            cards.PrintCards();
            cout << "Input: ";
        }
    }
    return 0;
}
