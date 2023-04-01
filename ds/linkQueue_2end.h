#ifndef LINKQUEUE_H
#define LINKQUEUE_H
/*
    linked queue
*/
#include<iostream>
using namespace std;

template<typename DT>
struct Node{
    DT data;
    Node<DT>* next;
};
template<typename DT>
class linkQueue{
    public:
        linkQueue();
        ~linkQueue(){};
        void EnHead(DT val);
        void EnTail(DT val);
        DT DeHead();
        DT DeTail();
        DT getHead();
        DT getTail();
        int isEpt();
    private:
        Node<DT> *front, *rear;
};
template<typename DT>
linkQueue<DT>::linkQueue(){
    Node<DT> *s = nullptr;
    s = new Node<DT>;
    s->next = nullptr;
    front = s;
    rear = s;
}
template<typename DT>
linkQueue<DT>::~linkQueue(){
    Node<DT> *p = nullptr;
    while(front != nullptr){
        p = front->next;
        delete front;
        front = p;
    }
}
template<typename DT>
void linkQueue<DT>::EnHead(DT val){
    Node<DT> *s = nullptr;
    s = new Node<DT>;
    s->data = val;
    s->next = nullptr;
    rear->next = s;
    rear = s;
}
template<typename DT>
DT linkQueue<DT>::DeHead(){
    DT x;
    Node<DT> *p = nullptr;
    if(rear == front) throw "underflow. ";
    p = front->next;
    x = p->data;
    front->next = p->next;
    if(p->next == nullptr) rear = front;
    delete p;
    return x;
}
template<typename DT>
DT linkQueue<DT>::getHead(){
    if(rear == front) throw "underflow. ";
    return front->next->data;
}
template<typename DT>
int linkQueue<DT>::isEpt(){
    if(rear == front) return 1;
    return 0;
}

#endif // linked queue