#include<iostream>

using namespace std;

template<typename DataType>
struct Node {
    DataType data; // 数据域
    struct Node<DataType> *next; // 指针域
};

template<typename DataType>
class LinkList {
    public:
        LinkList (); // 构造函数：建立只有头节点的空链表
        LinkList (DataType a[], int n); // 建立有 n 个元素的单链表
        ~LinkList ();
        int Length (); // 单链表长度
        DataType Get (int i); // 查找第 i 个结点的元素值
        int Locate (DataType x); // 查找值为 x 的元素位置
        void Insert (int i, DataType x); // 在 i 位置插入值 x
        DataType Delete (int i); // 删除第 i 个结点
        int Empty (); // 判断是否为空
        void PrintList (); // 遍历单链表
    private:
        Node<DataType> *first;
};

template<typename DataType>
LinkList<DataType>::LinkList () {
    first = new Node<DataType>;
    first->next = nullptr;
}

template<typename DataType>
int LinkList<DataType>::Empty () {
    if (first->next == nullptr) {
        return 1;
    }
    return 0;
}

template<typename DataType>
void LinkList<DataType>::PrintList () {
    Node<DataType> *p = first->next; // 初始化工作指针
    while (p != nullptr)
    {
        cout << p->data << "  ";
        p = p->next;
    }
    cout << endl;
}

template<typename DataType>
int LinkList<DataType>::Length () {
    Node<DataType> *p = first->next;
    int cnt = 0;
    while (p != nullptr)
    {
        p = p->next;
        cnt++;
    }
    return cnt;
}

template<typename DataType>
DataType LinkList<DataType>::Get (int i) {
    Node<DataType> *p = first->next;
    int cnt = 1;
    while (p != nullptr && cnt < i)
    {
        p = p->next;
        cnt++;
    }
    if (p == nullptr) {
        throw "error: locate error.";
    } else {
        return p->data;
    }
}

template<typename DataType>
int LinkList<DataType>::Locate (DataType x) {
    Node<DataType> *p = first->next;
    int cnt = 1;
    while (p != nullptr)
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
void LinkList<DataType>::Insert (int i, DataType x) {
    Node<DataType> *p = first, *s = nullptr;
    int cnt = 0;
    while (p != nullptr && cnt < i - 1)
    {
        p = p->next;
        cnt++;
    }
    if (p == nullptr) {
        throw "error: wrong inserting location.";
    } else {
        s = new Node<DataType>;
        s->data  = x;
        s->next = p->next;
        p->next = s;
    }
}

// 头插法
#if 0
template<typename DataType>
LinkList<DataType>::LinkList (DataType a[], int n) {
    first = new Node<DataType>;
    first->next = nullptr; // 初始化
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
LinkList<DataType>::LinkList (DataType a[], int n) {
    first = new Node<DataType>;
    Node<DataType> *r = first, *s = nullptr;
    for (int i = 0; i < n; i++) {
        s = new Node<DataType>;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = nullptr;
}
#endif

template<typename DataType>
DataType LinkList<DataType>::Delete (int i) {
    DataType x;
    Node<DataType> *p = first, *q = nullptr;
    int cnt = 0;
    while (p != nullptr && cnt < i - 1) 
    {
        p = p->next;
        cnt++;
    }
    if (p == nullptr || p->next == nullptr) {
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
LinkList<DataType>::~LinkList () {
    Node<DataType> *p = first;
    while (first != nullptr)
    {
        first = first->next;
        delete p;
        p = first;
    }
}

// main

int main () {
    int n, ar[101] = {0};
    while (cin >> n && n > 0 && n < 101)
    {
        for (int j = 0; j < n; j++) {
            cin >> ar[j];
        }
        LinkList<int> A{ar, n};
        cout << "Current LinkList is: ";
        A.PrintList();
        int i, x;
        cout << "Input inserting index and value: ";
        cin >> i >> x;
        try {
            A.Insert(i, x);
            cout << "After Insert: ";
            A.PrintList();
        } catch (char *str) {
            cout << str << endl;
        }
        cout << "Current Length is: " << A.Length() << endl;
        
    }
#if 0    
    int r[5] = {1, 2, 3, 4, 5}, i, x;
    LinkList<int> L{r, 5};
    cout << "current LintList is: ";
    L.PrintList ();
    try {
        L.Insert (2, 8);
        cout << "after insert: ";
        L.PrintList ();
    } catch (char *str) {
        cout << str << endl;
    } 
    cout << "current length is: " << L.Length () << endl;
    cout << "input x: ";
    cin >> x;
    i = L.Locate (x);
    if (i > 0) {
        cout << x << "'s location is: " << i << endl;
    } else {
        cout << "no " << x << "in LinkList." << endl;
    }
    try {
        cout << "delete element: ";
        cin >> i;
        x = L.Delete (i);
        cout << x << " is deleted." << ", and current LinkList is: " ;
        L.PrintList ();
    } catch (char *str) {
        cout << str << endl;
    }
#endif
    return 0;
}