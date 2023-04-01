#ifndef seqQueue_2end_2END_H
#define seqQueue_2end_2END_H
/*
    sequential queue with double-ended
    there are two cases:
        case 1:
            en: head & tail
            de: head & tail
        case 2:
            en: head & tail
            de: only head
*/
#include<iostream>
using namespace std;
const int QueueSize = 100;
template<typename DT>
class seqQueue_2end{
    public:
        seqQueue_2end();
        ~seqQueue_2end(){};
        void EnHead(DT val);
        void EnTail(DT val);
        DT DeHead();
        DT DeTail();
        DT getHead();
        DT getTail();
        int isEpt();
    private:
        DT data[QueueSize];
        int front, rear;
};
template<typename DT>
seqQueue_2end<DT>::seqQueue_2end(){
    rear = QueueSize - 1;
    front = QueueSize - 1;
}
// Enqueue
template<typename DT>
void seqQueue_2end<DT>::EnHead(DT val){
    int f;
    if((front - 1) % QueueSize == rear) throw "overflow. ";
    f = front;
    front = (front - 1) % QueueSize;
    data[f] = val;
}
template<typename DT>
void seqQueue_2end<DT>::EnTail(DT val){
    if((rear + 1) % QueueSize == front) throw "overflow. ";
    rear = (rear + 1) % QueueSize;
    data[rear] = val;
}
// Dequeue
template<typename DT>
DT seqQueue_2end<DT>::DeHead(){
    if(rear == front) throw "underflow. ";
    front = (front + 1) % QueueSize;
    return data[front];
}
template<typename DT>
DT seqQueue_2end<DT>::DeTail(){
    DT x;
    if(rear == front) throw "underflow. ";
    x = data[rear];
    rear = (rear - 1) % QueueSize;
    return x;
}
// getElement
template<typename DT>
DT seqQueue_2end<DT>::getHead(){
    if(rear == front) throw "underflow. ";
    return data[(front + 1) % QueueSize];
}
template<typename DT>
DT seqQueue_2end<DT>::getTail(){
    if(rear == front) throw "underflow. ";
    return data[(rear) % QueueSize];
}
// is Empty
template<typename DT>
int seqQueue_2end<DT>::isEpt(){
    if(front == rear) return 1;
    return 0;
}

#endif // sequential queue with double-ended