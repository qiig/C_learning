#include<iostream>
#include<cstring>
using namespace std;
class Queen{
    public:
        Queen(int n);
        ~Queen();
        void SetQueen();
        void PrintQueen();
    private:
        int isRight(int k); // 判断 k 位置是否合适
        int *qu; // Queen的位置
        int num; // Queen个数
};
Queen::Queen(int n){
    qu = new int[n];
    memset(qu, -1, n);
    num = n;
}
Queen::~Queen(){
    delete[] qu;
}
void Queen::SetQueen(){
    int k = 0, cnt = 0; // Queen的个数，解的个数
    while(k >= 0){
        qu[k]++; // 将 Queen k 摆放在下一列的位置
        while(qu[k] < num && isRight(k) == 1){
            qu[k]++;    // 若位置冲突则摆放至下一位置
        }
        if(qu[k] < num && k == num - 1){
            cout <<  "Solution " << ++cnt << " is: " << endl;
            PrintQueen();
        } else if(qu[k] < num && k < num - 1){
            k++;
        } else{
            qu[k--] = -1;   // 回溯
        }
    }
}
void Queen::PrintQueen(){
    for(int i = 0; i < num; i++){
        cout << qu[i] + 1 << " ";
    }
    cout << endl;
}
int Queen::isRight(int k){
    for(int i = 0; i < k; i++){
        if(qu[i] == qu[k] || abs(i - k) == abs(qu[i] - qu[k])) return 1;
    }   // 与 k 前某一 Queen 在同一列或斜线上
    return 0;
}
// main
int main(){
    int n;  // n 个 Queen
    cout << "Input: ";
    while(cin >> n && n > 3){
        Queen Q(n);
        Q.SetQueen();
        cout << "Input: ";
    }
    return 0;
}