#ifndef DYN_SEQLIST_H
#define DYN_SEQLISH_H

#include<iostream>

using namespace std;

const int IniL = 100;
const int IncL = 10;

template<typename DT>
class dyn_seqList{
    public:
        dyn_seqList();
        dyn_seqList(DT a[], int n);
        ~dyn_seqList();
        void Insert(int pos, DT val);
        DT Delete(int pos);
        int getPos(DT val);
        DT getVal(int pos);
        int getLen();
        int isEpt();
        void PrintList();
    private:
        DT *data;
        int maxS;
        int len;
};

template<typename DT>
dyn_seqList<DT>::dyn_seqList(){
    data = new DT[IniL];
    maxS = IniL;
    len = 0;
}

template<typename DT>
dyn_seqList<DT>::dyn_seqList(DT a[], int n){
    data = new DT[2 * n];
    maxS = 2 * n;
    len = n;
    for (int i = 0; i < n; i++)
        data[i] = a[i];
}

template<typename DT>
dyn_seqList<DT>::~dyn_seqList(){
    delete[] data;
}

template<typename DT>
int dyn_seqList<DT>::isEpt(){
    if (len == 0) return 1;
    return 0;
}

template<typename DT>
void dyn_seqList<DT>::PrintList(){
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template<typename DT>
int dyn_seqList<DT>::getLen(){
    return len;
}

template<typename DT>
int dyn_seqList<DT>::getPos(DT val){
    for (int i = 0; i < len; i++){
        if (data[i] == val) return i + 1;
    }
    return 0;
}

template<typename DT>
DT dyn_seqList<DT>::getVal(int pos){
    if (pos < 1 || pos > len + 1) throw "error: wrong pos. ";
    return data[pos - 1];
}

template<typename DT>
void dyn_seqList<DT>::Insert(int pos, DT val){
    if (pos < 1 || pos > len + 1) throw "error: wrong pos. ";
    if (len == maxS){
        DT *olddata = data;
        maxS += IncL;
        data = new DT[maxS];
        for (int i = 0; i < len; i++){
            data[i] = olddata[i];
        }
        delete[] olddata;
    }
    for (int i = len; i >= pos; i--){
        data[i] = data[i - 1];
    }
    data[pos -1] = val;
    len++;
}

template<typename DT>
DT dyn_seqList<DT>::Delete(int pos){
    if (pos < 1 || pos > len + 1) throw "error: wrong pos. ";
    DT val = data[pos];
    for (int i = pos; i < len - 1; i++)
        data[i] = data[i + 1];
    len--;
    return val;
}

#endif  // dynamic allocation for sequential list