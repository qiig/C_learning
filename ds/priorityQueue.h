#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
/*
    priority queue
*/
// main
#if 0
    #include "priorityQueue.h"
    // main
    int main(){
        int n, cnt = 0;
        priQueue<int> pQ{};
        cout << "Input no." << ++cnt << ": ";
        while(cin >> n && n > 0){
            pQ.EnQueue(n);
            cout << "Input no." << ++cnt << ": ";
        }
        cout << "Head is: " << pQ.getHead() << endl;
        cout << "Empty ? ";
        if(pQ.isEpt()) cout << "yes" << endl;
        else cout << "no" << endl;
        while(!pQ.isEpt()){
            cout << "no." << --cnt << " is: " << pQ.DeQueue() << endl;
        }
        return 0;
    }
#endif

#include<iostream>
using namespace std;

const int Qsize = 100;  // max length of the queue array
template<typename DT>
class priQueue{
    public:
        priQueue();
        ~priQueue();
        void EnQueue(DT val);
        DT DeQueue();
        DT getHead();
        int isEpt();
    private:
        DT data[Qsize]; // the array saving queue
        int rear;
};
template<typename DT>
priQueue<DT>::priQueue(){
    rear = 0;   // initpriqueue
}
template<typename DT>
priQueue<DT>::~priQueue(){

}
template<typename DT>
void priQueue<DT>::EnQueue(DT val){
    int i, temp;
    if(rear == Qsize - 1) throw "error: overflow. ";
    i = ++rear;
    data[i] = val;
    while(i / 2 > 0 && data[i/2] < val){
        temp = data[i];
        data[i] = data[i/2];
        data[i/2] = temp;
        i /= 2;
    }
}
template<typename DT>
DT priQueue<DT>::DeQueue(){
    int i, j, val, temp;
    if(rear == 0) throw "error: underflow. ";
    val = data[1];
    data[1] = data[rear--];
    i = 1;
    j = 2 * i;
    while(j <= rear){
        if(j < rear && data[j] < data[j+1]) j++;
        else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i = j;
            j = 2 * i;
        }
    }
    return val;
}
template<typename DT>
DT priQueue<DT>::getHead(){
    if(rear == 0) throw "error: underflow. ";
    return data[rear];
}
template<typename DT>
int priQueue<DT>::isEpt(){
    if(rear == 0) return 1;
    return 0;
}

#endif  // priority queue