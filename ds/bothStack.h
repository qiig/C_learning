#ifndef BOTHSTACK_H
#define BOTHSTACK_H
/*
    two stacks use one array
*/
#include<iostream>
using namespace std;
const int StackSize = 100;
template<typename DT>
class bothStack{
    public:
        bothStack();
        ~bothStack(){};
        void Push(int ab, DT val);
        DT Pop(int ab);
        DT getHead(int ab);
        int isEpt(int ab);
    private:
        DT data[StackSize];
        int top1, top2;
};
template<typename DT>
bothStack<DT>::bothStack(){
    top1 = -1;
    top2 = StackSize;
}
template<typename DT>
void bothStack<DT>::Push(int ab, DT val){
    if(top1 == top2 -1) throw "overflow. ";
    if(ab == 1) data[++top1] = val;
    else if(ab == 2) data[--top2] = val;
    else throw "wrong stack index. ";
}
template<typename DT>
DT bothStack<DT>::Pop(int ab){
    if(ab == 1){
        if(top1 == -1) throw "underflow. ";
        return data[top1--];
    } else if(ab == 2){
        if(top2 == StackSize) throw "underflow. ";
        return data[top2++];
    } else throw "wrong stack index. "; return 0;
}
template<typename DT>
DT bothStack<DT>::getHead(int ab){
    if(ab == 1){
        if(top1 == -1) throw "underflow. ";
        return data[top1];
    } else if(ab == 2){
        if(top2 == StackSize) throw "underflow. ";
        return data[top2];
    } else throw "wrong stack index. "; return 0;
}
template<typename DT>
int bothStack<DT>::isEpt(int ab){
    if(ab == 1){
        if(top1 == -1) return 1;
        return 0;
    }else if(ab == 2){
        if(top2 == StackSize) return 1;
        return 0;
    }else throw "wrong stack index. "; return 0;
}

#endif