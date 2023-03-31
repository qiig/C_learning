#include<iostream>

using namespace std;

template<typename DataType>
struct Node {
    DataType data; // 数据域
    struct Node<DataType> *next; // 指针域
};

template<typename DataType>
class cir_singlyLinkList {
    public:
        cir_singlyLinkList (); // 构造函数：建立只有头节点的空链表
        cir_singlyLinkList (DataType a[], int n); // 建立有 n 个元素的单链表
        ~cir_singlyLinkList ();
        int getLen (); // 单链表长度
        DataType getVal (int i); // 查找第 i 个结点的元素值
        int getPos (DataType x); // 查找值为 x 的元素位置
        void Insert (int i, DataType x); // 在 i 位置插入值 x
        DataType Delete (int i); // 删除第 i 个结点
        int isEpt (); // 判断是否为空
        void PrintList (); // 遍历单链表
    private:
        Node<DataType> *first;
};

template<typename DataType>
cir_singlyLinkList<DataType>::cir_singlyLinkList () {
    first = new Node<DataType>;
    first->next = nullptr;
}

template<typename DataType>
int cir_singlyLinkList<DataType>::isEpt () {
    if (first->next == nullptr) {
        return 1;
    }
    return 0;
}

template<typename DataType>
void cir_singlyLinkList<DataType>::PrintList () {
    Node<DataType> *p = first->next; // 初始化工作指针
    while (p != first)
    {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}

template<typename DataType>
int cir_singlyLinkList<DataType>::getLen () {
    Node<DataType> *p = first->next;
    int cnt = 0;
    while (p != first)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

template<typename DataType>
DataType cir_singlyLinkList<DataType>::getVal (int i) {
    Node<DataType> *p = first->next;
    int cnt = 1;
    while (p != first && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    if (p == first || p == nullptr) {
        throw "error: getPos error.";
    } else {
        return p->data;
    }
}

template<typename DataType>
int cir_singlyLinkList<DataType>::getPos (DataType x) {
    Node<DataType> *p = first->next;
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

template<typename DataType>
void cir_singlyLinkList<DataType>::Insert (int i, DataType x) {
    Node<DataType> *p = first, *s = nullptr;
    int cnt = 0;
    if (first != nullptr && i != 1) {
        p = p->next;
        cnt++;
    } else if (first != nullptr && i == 1) {
        s = new Node<DataType>;
        s->data  = x;
        s->next = p->next;
        p->next = s;    
    }
    while (p != first && cnt < i - 1)
    {
        p = p->next;
        cnt++;
    }
    if ((p == nullptr || p == first) && i != 1) {
        throw "error: wrong inserting location.";
    } else if (i != 1){
        s = new Node<DataType>;
        s->data  = x;
        s->next = p->next;
        p->next = s;
    }
}

// 头插法
#if 0
template<typename DataType>
cir_singlyLinkList<DataType>::cir_singlyLinkList (DataType a[], int n) {
    first = new Node<DataType>;
    first->next = first; // 初始化
    for (int i = 0; i < n; i++) {
        Node<DataType> *s = nullptr;
        s = new Node<DataType>;
        s->data = a[i];
        s->next = first->next;
        first->next = s;
    }
}
#endif
// 尾插法
#if 1
template<typename DataType>
cir_singlyLinkList<DataType>::cir_singlyLinkList (DataType a[], int n) {
    first = new Node<DataType>;
    Node<DataType> *r = first, *s = nullptr;
    for (int i = 0; i < n; i++) {
        s = new Node<DataType>;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = first;
}
#endif

template<typename DataType>
DataType cir_singlyLinkList<DataType>::Delete (int i) {
    DataType x;
    Node<DataType> *p = first, *q = nullptr;
    int cnt = 0;
    if (first != nullptr && i != 1) {
        p = p->next;
        cnt++;
    } else if (first != nullptr && i == 1) {
        q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
        return x;        
    }
    while (p != first && cnt < i - 1) 
    {
        p = p->next;
        cnt++;
    }
    if ((p == first || p->next == first) && i != 1) {
        throw "error: do not exist p or pNext.";
    } else {
        q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}

template<typename DataType>
cir_singlyLinkList<DataType>::~cir_singlyLinkList () {
    Node<DataType> *h = first;
    Node<DataType> *p = first;
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