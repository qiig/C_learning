#include<iostream>
#include<string>
using namespace std;
const int MaxS = 20;
class Marcher{
    public:
        Marcher(string str);
        ~Marcher(){};
        int March();
    private:
        string str;
};
Marcher::Marcher(string str){
    this->str = str;
}
int Marcher::March(){
    char s[MaxS];
    int top = -1;
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ')'){
            if(top > -1) top--;
            else return -1; // 多 ）
        } else if(str[i] == '('){
            s[++top] = str[i];
        }
    }
    if(top == -1) return 0;
    else return 1;;
}

int main(){
    string str;
    cout << "Input: ";
    while(cin >> str){
        Marcher M{str};
        int k = M.March();
        switch(k){
            case 1:
                cout << "(" << endl; break;
            case -1:
                cout << ")" << endl; break;
            case 0:
                cout << "right " << endl; 
        }
        cout << "Input: ";
    }
    return 0;
}