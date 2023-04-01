#ifndef SEQSTACK_H
#define SEQSTACK_H

#include<iostream>
using namespace std;
const int StackSize = 20;

template<typename DT>
class seqStack{
    public:
        seqStack();
        ~seqStack(){};
        void Push(DT val);
        DT Pop();
        DT getTop();
        int isEpt();
    private:
        DT data[StackSize];
        int top;
};
template<typename DT>
seqStack<DT>::seqStack(){
    top = -1;
}
template<typename DT>
void seqStack<DT>::Push(DT val){
    if(top == StackSize - 1) throw "overflow. ";
    data[++top] = val;
}
template<typename DT>
DT seqStack<DT>::Pop(){
    DT x;
    if(top == -1) throw "underflow. ";
    x = data[top--];
    return x;
}
template<typename DT>
DT seqStack<DT>::getTop(){
    if(top == -1) throw "underflow. ";
    return data[top];
}
template<typename DT>
int seqStack<DT>::isEpt(){
    if(top == -1) return 1;
    return 0;
}

#endif // sequential stack