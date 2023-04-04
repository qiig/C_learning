#ifndef UNIONFIND_H
#define UNIONFIND_H
/*
    union & find set
*/
// main
#if 0
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
#endif  // main

#include<iostream>
using namespace std;

struct ElemType{
    char data;
    int parent;
};
const int maxS = 100;   // max num. of the set
class unionFind{
    public:
        unionFind(char ch[], int n);
        ~unionFind(){};
        int Find(char x);   // finding the root of the element x 
        void Union(char x, char y); // union the subtree which includes element x and the subtree including y
    private:
        ElemType elem[maxS];    // parent expression
        int length;
};
unionFind::unionFind(char ch[], int n){
    for(int i = 0; i < n; i++){
        elem[i].data = ch[i];
        elem[i].parent = -1;
    }
}
int unionFind::Find(char x){
    int i;
    for(i = 0; i < length; i++){
        if(elem[i].data == x) break;
    }
    while(elem[i].parent != -1){
        i = elem[i].parent;
    }
    return i;
}
void unionFind::Union(char x, char y){
    int vex1 = Find(x);
    int vex2 = Find(y);
    if(vex1 != vex2) elem[vex2].parent = vex1;
}

#endif  // union & find set