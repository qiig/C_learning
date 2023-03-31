#ifndef STATICLINKLISH_H
#define STATICLINKLISH_H

#include<iostream>

using namespace std;

const int MaxS = 100;  // 数组长度

template<typename DT>
struct sNode {
    DT data;
    int next;
};

template<typename DT>
class staticLinkList {
    public:
        staticLinkList();
        staticLinkList(DT a[], int n);
        ~staticLinkList(){};
        void PrintList();
        int getLen();
        int getPos(DT val);
        DT getVal(int pos);
        void Insert(int pos, DT val);
        DT Delete(int pos);
        int isEpt();
    private:
        sNode<DT> sList[MaxS];
        int first, avail;
};

template<typename DT>
staticLinkList<DT>::staticLinkList(){
    for (int i = 0; i < MaxS; i++) {
        sList[i].next = i + 1;
    }
    first = 0; sList[first].next = -1;
    avail = 1; sList[MaxS - 1].next = -1;
}

#if 0
// 头插法
template<typename DT>
staticLinkList<DT>::staticLinkList(DT a[], int n) {
    for (int i = 0; i < MaxS; i++) {
        sList[i].next = i + 1;
    }
    first = 0; sList[first].next = -1;
    avail = 1; sList[MaxS - 1].next = -1;
    int s, p;
    for (int i = 0; i < n; i++) {
        if (i == 0) p = first;
        s = avail;
        avail = sList[avail].next;
        sList[s].data = a[i];
        sList[s].next = sList[p].next;
        sList[p].next = s;
    }    
}
#endif
#if 1
// 尾插法
template<typename DT>
staticLinkList<DT>::staticLinkList(DT a[], int n) {
    for (int i = 0; i < MaxS; i++) {
        sList[i].next = i + 1;
    }
    first = 0; sList[first].next = -1;
    avail = 1; sList[MaxS - 1].next = -1;
    int s, p = first;
    for (int i = 0; i < n; i++) {
        s = avail;
        avail = sList[avail].next;
        sList[s].data = a[i];
        sList[p].next = s;
        p = s; 
    }
    sList[p].next = -1;
}
#endif
template<typename DT>
int staticLinkList<DT>::getLen(){
    int cnt = 0;
    int p = sList[first].next;
    while (p != -1) {
        p = sList[p].next;
        cnt++;
    }
    if (sList[first].next == -1) throw "error: empty list.";
    return cnt;
}

template<typename DT>
int staticLinkList<DT>::getPos(DT val){
    int cnt = 1;
    int p = sList[first].next;
    while (p != -1){
        if (sList[p].data == val) return cnt;
        p = sList[p].next;
        cnt++;
    }
    return 0;
}

template<typename DT>
DT staticLinkList<DT>::getVal(int pos){
    int cnt = 1;
    int p = sList[first].next;
    while(p != -1 && cnt < pos){
        p = sList[p].next;
        cnt++;
    }
    if (p == -1) throw "postion error.";
    else return sList[p].data;
}

template<typename DT>
void staticLinkList<DT>::Insert(int pos, DT val){
    int s, p = first;
    int cnt = 1;
    while (p != -1 && cnt < pos){
        p = sList[p].next;
        cnt++;
    }
    if (p == -1) throw "error: insert pos error.";
    else{
        s = avail;
        avail = sList[avail].next;
        sList[s].data = val;
        sList[s].next = sList[p].next;
        sList[p].next = s;
    }
}

template<typename DT>
DT staticLinkList<DT>::Delete(int pos){
    DT val;
    int s, p = first;
    int cnt = 1;
    while (p != -1 && cnt < pos){
        p = sList[p].next;
        cnt++;
    }
    if (p == -1) throw "error: delete pos error.";
    else{
        s = sList[p].next;
        val = sList[s].data;
        sList[p].next = sList[s].next;
        sList[s].next = avail;
        avail = s;
        return val;
    }
}

template<typename DT>
int staticLinkList<DT>::isEpt(){
    if(first == -1) return 1;
    return 0;
}

template<typename DT>
void staticLinkList<DT>::PrintList(){
    int p = sList[first].next;
    while(p != -1){
        cout << sList[p].data << " ";
        p = sList[p].next;
    }
    cout << endl;
}

#endif // staticLinkList.h