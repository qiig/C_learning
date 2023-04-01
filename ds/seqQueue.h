#ifndef SEQQUEUE_H
#define SEQQUEUE_H
/*
    sequential queue ADT
*/
#include<iostream>
using namespace std;
const int QueueSize = 100;
template<typename DT>
class seqQueue{
    public:
        seqQueue();
        ~seqQueue(){};
        void EnQueue(DT val);
        DT DeQueue();
        DT getHead();
        int isEpt();
    private:
        DT data[QueueSize];
        int front, rear;
};
template<typename DT>
seqQueue<DT>::seqQueue(){
    rear = QueueSize - 1;
    front = QueueSize - 1;
}
template<typename DT>
void seqQueue<DT>::EnQueue(DT val){
    if((rear + 1) % QueueSize == front) throw "overflow. ";
    rear = (rear + 1) % QueueSize;
    data[rear] = val;
}
template<typename DT>
DT seqQueue<DT>::DeQueue(){
    if(rear == front) throw "underflow. ";
    front = (front + 1) % QueueSize;
    return data[front];
}
template<typename DT>
DT seqQueue<DT>::getHead(){
    if(rear == front) throw "underflow. ";
    return data[(front + 1) % QueueSize];
}
template<typename DT>
int seqQueue<DT>::isEpt(){
    if(front == rear) return 1;
    return 0;
}

#endif // sequential queue