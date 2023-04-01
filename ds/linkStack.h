#ifndef LINKSTACK_H
#define LINKSTACK_H

#include<iostream>
using namespace std;
template<typename DT>
struct Node{
    DT data;
    Node<DT>* next;
};
template<typename DT>
class linkStack{
    public:
        linkStack();
        ~linkStack();
        void Push(DT val);
        DT Pop();
        DT getTop();
        int isEpt();
    private:
        Node<DT> *top;
};
template<typename DT>
linkStack<DT>::linkStack(){
    top = new Node<DT>;
    top = nullptr;
}
template<typename DT>
linkStack<DT>::~linkStack(){
    Node<DT>* p = nullptr;
    while(top != nullptr){
        p = top;
        top = p->next;
        delete p;
    }
}
template<typename DT>
void linkStack<DT>::Push(DT val){
    Node<DT>* s = nullptr;
    s = new Node<DT>;
    s->data = val;
    s->next = top;
    top = s;
}
template<typename DT>
DT linkStack<DT>::Pop(){
    Node<DT> *p = nullptr;
    DT x;
    if(top == nullptr) throw "underflow. ";
    x = top->data;
    p = top;
    top = top->next;
    delete p;
    return x;
}
template<typename DT>
DT linkStack<DT>::getTop(){
    if(top == nullptr) throw "underflow. ";
    return top->data;
}
template<typename  DT>
int linkStack<DT>::isEpt(){
    if(top == nullptr) return 1;
    return 0;
}

#endif // linked stack