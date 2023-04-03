#include "BiTree.h"
// main
int main(){
    BiTree<char> T{};
    cout << "PreOrder traverse is: ";
    T.PreOrder();
    cout << endl << "InOrder traverse is: ";
    T.InOrder();
    cout << endl << "PostOrder traverse is: ";
    T.PostOrder();
    cout << endl << "Level Order traverse is: ";
    try{
        T.LevelOrder();
    } catch(const char* s){cout << s << endl;}
    return 0;
}