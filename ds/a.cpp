#include "unionFind.h"
// main
int main(){
    int n;
    char x, y, ch[100];
    cout << "Input n: ";
    while(cin >> n && n > 0){
        for(int i = 0; i < n; i++)
            cin >> ch[i];
        unionFind UF{ch, n};
        cout << "Input finding value: ";
        cin >> x;
        cout << x << "'s root is: " << UF.Find(x) << endl;
        cout << "Input unioning 2 values: ";
        cin >> x >> y;
        cout << x << "'s root is: " << UF.Find(x) << "  &  ";
        cout << y << "'s root is: " << UF.Find(y) << endl;
        UF.Union(x, y);
        cout << "after: " << endl;
        cout << x << "'s root is: " << UF.Find(x) << "  &  ";
        cout << y << "'s root is: " << UF.Find(y) << endl;
        cout << "Input n: ";
    }
    return 0;
}