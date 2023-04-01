#include<iostream>
using namespace std;
struct Node{
    int coef, exp;
    Node* next; 
};
class Polynomial{
    public:
        Polynomial();
        Polynomial(const Polynomial &B); // 拷贝构造函数
        ~Polynomial();
        Polynomial operator+(Polynomial &B); // 重载+运算符 多项式加法
        void Print();
    private:
        Node *first;
};
Polynomial::~Polynomial(){
    Node *p = first;
    while(first != nullptr){
        first = first->next;
        delete p;
        p = first;
    }
    cout << "~f" << endl;
}
Polynomial::Polynomial(){
    Node *r = nullptr, *s = nullptr;
    int coef, exp;
    first = new Node;
    r = first;
    cout << "Input: coef & exp: ";
    cin >> coef >> exp;
    while(coef != 0){
        s = new Node;
        s->coef = coef;
        s->exp = exp;
        r->next = s;
        r = s;
        cout << "Input: coef & exp: ";
        cin >> coef >> exp;
    }
    r->next = nullptr;
}
Polynomial::Polynomial(const Polynomial &B){
    first = B.first;
}
Polynomial Polynomial::operator+(Polynomial &B){
    Node *pre = first, *p = pre->next;
    Node *qre = B.first, *q = qre->next;
    Node *qtemp = nullptr;
    while(p != nullptr && q != nullptr){
        if(p->exp < q->exp){ // case 1
            pre = p;
            p = p->next;
        } else if(p->exp > q->exp){ // case 2
            qtemp = q->next;
            pre->next = q;
            q->next = p;
            q = qtemp;
            pre = q;
            qre->next = q;
        } else{ // case 3
            p->coef = p->coef + q->coef;
            if(p->coef == 0){ // 合并同类项后系数为零
                pre->next = p->next;
                delete p;
                p = pre->next;
            } else{ // 合并后系数不为零
                pre = p;
                p = p->next;
            }
            qre->next = q->next;
            delete q;
            q = qre->next;
        }
    }
    if(q != nullptr) pre->next = q; // 若 B 中还有其他项，则加至 A 后
    return *this;
}
void Polynomial::Print(){
    Node *p = first->next;
    if(p != nullptr){
        cout << p->coef << "x" << p->exp;
    }
    p = p->next;
    while(p != nullptr){
        if(p->coef > 0){
            cout << " + " << p->coef << "x" << p->exp;
        } else {
            cout << " - " << - p->coef << "x" << p->exp;
        }
        p = p->next;
    }
    cout << endl;
}
// main
int main(){
    Polynomial A{}, B{};
    A.Print();
    B.Print();
    Polynomial C = A + B;
    cout << "Result: ";
    C.Print();
    return 0;
}