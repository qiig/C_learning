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
    // non recurrence traversing
    cout << endl << "nPreOrder traverse is: ";
    T.PreOrder();
    cout << endl << "nInOrder traverse is: ";
    T.InOrder();
    cout << endl << "nPostOrder traverse is: ";
    T.PostOrder();
    cout << endl;
    return 0;
}