#include "seqQueue_2end.h"

int main(){
    int x;
    seqQueue_2end<int> Q{};
    try{
        cout << "Enqueue: "<< endl;
        Q.EnHead(1);
        Q.EnHead(2);
        Q.EnTail(3);
        Q.EnTail(4);
        cout << Q.getHead() << " & " << Q.getTail() << endl;
    }catch(const char *s){cout << s << endl;}
    try{
        cout <<"Dequeue from Head: "<<endl;
        for(int i = 0; i < 4; i++){
            cout << Q.DeHead() <<" ";
        }
        cout << endl;
        if(Q.isEpt() == 1) cout <<"Empty."<<endl;
        else cout <<"not Empty."<<endl;
    }catch(const char *s){cout << s << endl;}
    try{
        cout <<"Dequeue from Tail: "<<endl;
        Q.EnHead(1);
        Q.EnHead(2);
        Q.EnTail(3);
        Q.EnTail(4);
        for(int i = 0; i < 4; i++){
            cout << Q.DeTail() <<" ";
        }
        cout << endl;
        if(Q.isEpt() == 1) cout <<"Empty."<<endl;
        else cout <<"not Empty."<<endl;
    }catch(const char *s){cout << s << endl;}
    return 0;
}