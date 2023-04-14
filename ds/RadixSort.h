#ifndef RADIXSORT_H
#define RADIXSORT_H
/*
    radix sort
*/
/*
#include "RadixSort.h"
// main
int main(){
    int select;
    int r[10] = {2, 5, 1, 7, 9, 4, 3, 6, 5, 8};
    // int r[10] = {61, 98, 12, 15, 20, 24, 31, 99, 23, 35};
    RadixSort<int> L{r, 10, 2};
    L.Print();
    return 0;
}
*/
#include<iostream>
using namespace std;
template<typename DT>
struct Node{
    DT data;
    Node *next;
};
template<typename DT>
class RadixSort{
    public:
        RadixSort(DT a[], int n, int d);
        ~RadixSort();
        void Print();
    private:
        Node<DT> *first;
        int d;
        int length;
        Node<DT>* GetAns(Node<DT> *first, int d);
};
template<typename DT>
RadixSort<DT>::RadixSort(DT a[], int n, int d){
    int cnt = 0;
    length = n;
    this->d = d;
    first = new Node<DT>;
    first->data = a[cnt]; first->next = nullptr; cnt++;
    Node<DT> *p = first, *s = nullptr;
    while(cnt < length){
        s = new Node<DT>;
        s->data = a[cnt++];
        p->next = s;
        p =s;
    }
    p->next = nullptr;
}
template<typename DT>
RadixSort<DT>::~RadixSort(){
    Node<DT> *p = first;
    while(first != nullptr){
        first = first->next;
        delete p;
        p = first;
    }
}
#if 1
template<typename DT>
Node<DT>* RadixSort<DT>::GetAns(Node<DT> *first, int d){
    Node<DT> *front[10], *rear[10], *tail;
    int k, base = 1;
    for(int i = 1; i <= d; i++){
        for(int j = 0; j < 10; j++){
            front[j] = nullptr;
            rear[j] = nullptr;
        }   // init front & rear
        while(first != nullptr){
            k = (first->data / base) % 10;
            if(front[k] == nullptr){
                front[k] = first;
                rear[k] = first;
            } else {
                rear[k]->next = first;
                rear[k] = rear[k]->next;
            }
            first = first->next;
        }
        for(int j = 0; j < 10; j++){
            if(front[j] == nullptr) continue;
            if(first == nullptr){
                first = front[j];
            } else {
                tail->next = front[j];
            }
            tail = rear[j];
        }
        tail->next = nullptr;
        base *= 10;
    }
    // Node<DT> *p = first;
    // while(p != nullptr){
    //     cout << p->data << " ";
    //     p = p->next;
    // }
    return first;
}
#endif
#if 0
template<typename DT>
Node<DT>* RadixSort<DT>::GetAns(Node<DT> *first, int d){
    Node<DT> *front[10], *rear[10], *tail;
    int i, j, k, base = 1;
    for(i = 1; i <= d; i++){
        for(j = 0; j < 10; j++){
            rear[j] = nullptr; front[j] = nullptr;
        }
        while(first != nullptr){
            k = (first->data / base) % 10;
            if(front[k] == nullptr) {rear[k] = first; front[k] = first;}
            else {rear[k]->next = first; rear[k] = first;}
            first = first->next;
        }
        for(j = 0; j < 10; j++){
            if(front[j] == nullptr) continue;
            if(first == nullptr) first = front[j];
            else tail->next = front[j];
            tail = rear[j];
        }
        tail->next = nullptr;
        base = base * 10;
    }
    return first;
}
#endif
template<typename DT>
void RadixSort<DT>::Print(){
    Node<DT> *p = GetAns(first, d);
    while(p != nullptr){
        cout << p->data << " ";
        p = p->next;
    }
}

#endif  // radix sort