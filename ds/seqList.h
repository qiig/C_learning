/*
    SeqList Class
*/
#include <iostream>

using namespace std;

const int MAX = 100;

template <typename DT>
class SeqList {
    public:
        SeqList ();
        SeqList (DT a[], int n); // 创建长度为 n 的顺序表
        ~SeqList ();
        void Insert (int pos, DT val); // 在 pos 处插入值为 val 的元素
        DT Delete (int pos); // 删除 pos 处的值
        DT getVal (int pos); // 按位查找
        int getPos (DT val); // 按值查找
        int getLen (); // 顺序表长度
        int isEpt (); // 判空
        void PrintList (); // 遍历
    private:
        DT data[MAX]; //  存放表元素
        int len; // 线性表长度
};

template <typename DT>
SeqList<DT>::SeqList () {
    len = 0;
}

template <typename DT>
SeqList<DT>::SeqList (DT a[], int n) {
    if (n > MAX) throw "illegal parameter: length. ";
    for (int i = 0; i < n; i++) {
        data[i] = a[i];
    }
    len = n;
}

template <typename DT>
SeqList<DT>::~SeqList () {}

template <typename DT>
int SeqList<DT>::isEpt () {
    if (len == 0) return 1;
    return 0;
}

template <typename DT>
int SeqList<DT>::getLen () {
    return len;
}

template <typename DT>
DT SeqList<DT>::getVal (int pos) {
    if (pos < 1 || pos > len) throw "illegal parameter: pos. ";
    else return data[pos - 1];
}

template <typename DT>
int SeqList<DT>::getPos (DT val) {
    for (int i = 0; i < len; i++) {
        if (data[i] == val) return i + 1;
    }
    return 0;
}

template <typename DT>
void SeqList<DT>::PrintList () {
    for (int i = 0; i < len; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template <typename DT>
void SeqList<DT>::Insert (int pos, DT val) {
    if (len == MAX) throw "error: len is MAX. ";
    if (pos < 1 || pos > len + 1) throw "error: illegal pos. ";
    for (int i = len; i >= pos; i--) {
        data[i] = data[i - 1];
    }
    data[pos - 1] = val;
    len++;
}

template <typename DT>
DT SeqList<DT>::Delete (int pos) {
    if (len == 0) throw "error: len is 0. ";
    if (pos < 1 || pos > len + 1) throw "error: illegal pos. ";
    DT x;
    x = data[pos - 1];
    for (int i = pos - 1; i < len; i++) {
        data[i] = data[i + 1];
    }
    len--;
    return x;
}