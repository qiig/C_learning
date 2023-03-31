#include<iostream>

using namespace std;

/*
    Double Linked List 
*/

template<typename DT>
struct dNode {
    DT data; // 数据域
    struct dNode<DT> *prior, *next; // 指针域
};

template<typename DT>
class cir_doubleLinkList {
    public:
        cir_doubleLinkList (); // 构造函数：建立只有头节点的空链表
        cir_doubleLinkList (DT a[], int n); // 建立有 n 个元素的单链表
        ~cir_doubleLinkList ();
        int getLen (); // 单链表长度
        DT getVal (int i); // 查找第 i 个结点的元素值
        int getPos (DT x); // 查找值为 x 的元素位置
        void Insert (int i, DT x); // 在 i 位置插入值 x
        DT Delete (int i); // 删除第 i 个结点
        int isEpt (); // 判断是否为空
        void PrintList (); // 遍历单链表
    private:
        dNode<DT> *first;
};

template<typename DT>
cir_doubleLinkList<DT>::cir_doubleLinkList () {
    first = new dNode<DT>;
    first->next = nullptr;
    first->prior = nullptr;
}

template<typename DT>
int cir_doubleLinkList<DT>::isEpt () {
    if (first->next == nullptr) {
        return 1;
    }
    return 0;
}

template<typename DT>
void cir_doubleLinkList<DT>::PrintList () {
    dNode<DT> *p = first->next; // 初始化工作指针
    while (p != first)
    {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}

template<typename DT>
int cir_doubleLinkList<DT>::getLen () {
    dNode<DT> *p = first->next;
    int cnt = 0;
    while (p != first)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

template<typename DT>
DT cir_doubleLinkList<DT>::getVal (int i) {
    dNode<DT> *p = first->next;
    int cnt = 1;
    while (p != first && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    if (p == nullptr || p == first) {
        throw "error: location error.";
    } else {
        return p->data;
    }
}

template<typename DT>
int cir_doubleLinkList<DT>::getPos (DT x) {
    dNode<DT> *p = first->next;
    int cnt = 1;
    while (p != first)
    {
        if (p->data == x) {
            return cnt;
        }
        p = p->next;
        cnt++;
    }
    return 0;
}

template<typename DT>
void cir_doubleLinkList<DT>::Insert (int i, DT x) {
    dNode<DT> *p = first, *s = nullptr;
    int cnt = 0;
    if (first != nullptr && i != 1) {
        p = p->next;
        cnt++;
    } else if (i == 1) {
        s = new dNode<DT>;
        s->data  = x;
        s->next = p->next;
        s->prior = p;
        p->next->prior = s;
        p->next = s;
    }
    while (p != first && cnt < i - 1)
    {
        p = p->next;
        cnt++;
    }
    if ((p == nullptr && p == first) && i != 1) {
        throw "error: wrong inserting location.";
    } else if (i != 1) {
        s = new dNode<DT>;
        s->data  = x;
        s->next = p->next;
        s->prior = p;
        p->next->prior = s;
        p->next = s;
    }
}

// 头插法
#if 1
template<typename DT>
cir_doubleLinkList<DT>::cir_doubleLinkList (DT a[], int n) {
    first = new dNode<DT>;
    first->next = first; // 初始化
    first->prior = first;
    for (int i = 0; i < n; i++) {
        dNode<DT> *s = nullptr;
        s = new dNode<DT>;
        s->data = a[i];
        s->prior = first;
        s->next = first->next;
        first->next->prior = s;
        first->next = s;
    }
}
#endif
// 尾插法
#if 0
template<typename DT>
cir_doubleLinkList<DT>::cir_doubleLinkList (DT a[], int n) {
    first = new dNode<DT>;
    first->prior = first;
    first->next = first;
    dNode<DT> *r = first, *s = nullptr;
    for (int i = 0; i < n; i++) {
        s = new dNode<DT>;
        s->data = a[i];
        s->prior = r;
        r->next = s;
        r = s;
    }
    r->next = first;
    first->prior = r;
}
#endif

template<typename DT>
DT cir_doubleLinkList<DT>::Delete (int i) {
    DT x;
    dNode<DT> *p = first;
    int cnt = 0;
    if (first != nullptr && i != 1) {
        p = p->next;
        cnt++;
    } else if (first != nullptr && i == 1) {
        p = p->next;
        x = p->data;
        (p->prior)->next = p->next;
        (p->next)->prior = p->prior;
        delete p;
        return x;        
    }
    while (p != first && cnt < i) 
    {
        p = p->next;
        cnt++;
    }
    if ((p == first || p->next == first) && i != 1) {
        throw "error: do not exist p or pNext.";
    } else {
        x = p->data;
        (p->prior)->next = p->next;
        (p->next)->prior = p->prior;
        delete p;
        return x;
    }
}

template<typename DT>
cir_doubleLinkList<DT>::~cir_doubleLinkList () {
    dNode<DT> *h = first;
    dNode<DT> *p = first;
    if (first != nullptr) {
        first = first->next;
        delete p;
        p = first;
    }
    while (first != h)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

