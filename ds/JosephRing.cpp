#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* next;
};

class JosephRing{
    public:
        JosephRing(int n); // 环元素数
        ~JosephRing();
        void Joseph(int m); // 间隔数
    private:
        Node *rear;
        int isEpt;
};

JosephRing::JosephRing(int n){
    Node *s = nullptr;
    rear = new Node;
    rear->data = 1;
    rear->next = rear;
    isEpt = 0;
    for(int i = 2; i <= n; i++){
        s = new Node;
        s->data = i;
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
}

JosephRing::~JosephRing(){
    if (isEpt == 0){
        Node *p = rear->next;
        while(p->next != p){
            rear->next = p->next;
            delete p;
            p = rear->next;
        }
        delete p;
    }
}

void JosephRing::Joseph(int m){
    Node *pre = rear, *p = rear->next;
    int cnt = 1;
    cout << "out of ring: " ;
    while(p->next != p){
        if(cnt < m){
            pre = p;
            p = p->next;
            cnt++;
        } else {
            cout << p->data << " ";
            pre->next = p->next;
            delete p;
            p = pre->next;
            cnt = 1;
        }
    }
    cout << p->data << endl;
    delete p;
    isEpt = 1;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        JosephRing J{n};
        J.Joseph(m);
    }
    return 0;
}