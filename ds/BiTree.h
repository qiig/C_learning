#ifndef BITREE_H
#define BITREE_H
/*
    Binary Tree
    Level Order Traverse:
        changing sequential queue to circular queue.
    PreOrder/InOrder/PostOrder traverse (recurrence)
    nPreOrder/nInOrder/nPostOrder traverse (non recurrence)
*/
#include<iostream>
using namespace std;
template<typename DT>
struct BiNode{
    DT data;
    BiNode<DT> *lchild, *rchild;
};
template<typename DT>
class BiTree{
    public:
        BiTree(){root = Creat();};  // creat a binary tree
        ~BiTree(){Release(root);};  // destory
        void PreOrder(){PreOrder(root);};   // preorder traverse
        void InOrder(){InOrder(root);}; // inorder traverse
        void PostOrder(){PostOrder(root);}; // postorder traverse
        void LevelOrder();  // lever order traverse
        void nPreOrder();
        void nInOrder();
        void nPostOrder();
    private:
        int Qsize, Ssize;   // size of a queue or a stack
        BiNode<DT> *Creat();
        void Release(BiNode<DT> *bt);
        void PreOrder(BiNode<DT> *bt);
        void InOrder(BiNode<DT> *bt);
        void PostOrder(BiNode<DT> *bt);
        BiNode<DT> *root;
};
template<typename DT>
BiNode<DT> *BiTree<DT>::Creat(){
    BiNode<DT> *bt;
    Qsize = 20, Ssize = 100;
    char ch;
    cin >> ch;
    if(ch == ',') bt = nullptr;
    else{
        bt = new BiNode<DT>;
        bt->data = ch;
        bt->lchild = Creat();
        bt->rchild = Creat();
    }
    return bt;
}
template<typename DT>
void BiTree<DT>::Release(BiNode<DT> *bt){
    if(bt == nullptr) return;
    else{
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}
template<typename DT>
void BiTree<DT>::PreOrder(BiNode<DT> *bt){
    if(bt == nullptr) return;
    else{
        cout << bt->data << " ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
template<typename DT>
void BiTree<DT>::InOrder(BiNode<DT> *bt){
    if(bt == nullptr) return;
    else{
        InOrder(bt->lchild);
        cout << bt->data << " ";
        InOrder(bt->rchild);
    }
}
template<typename DT>
void BiTree<DT>::PostOrder(BiNode<DT> *bt){
    if(bt == nullptr) return;
    else{
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout << bt->data << " ";
    }
}
template<typename DT>
void BiTree<DT>::LevelOrder(){  // changing sequential queue to circular queue
    BiNode<DT> *Q[Qsize], *q = nullptr;
    int front = Qsize - 1, rear = Qsize - 1;
    if(root == nullptr) return;
    if((rear + 1) % Qsize == front) throw "error: overflow. ";
    rear = (rear + 1) % Qsize;  
    Q[rear] = root;
    while(front != rear){
        if(rear == front) throw "error: underflow. ";
        front = (front + 1) % Qsize;
        q = Q[front];
        cout << q->data << " ";
        if(q->lchild != nullptr){
            if((rear + 1) % Qsize == front) throw "error: overflow. ";
            rear = (rear + 1) % Qsize;
            Q[rear] = q->lchild;
        } 
        if(q->rchild != nullptr){
            if((rear + 1) % Qsize == front) throw "error: overflow. ";
            rear = (rear + 1) % Qsize;
            Q[rear] = q->rchild;         
        }
    }
}
template<typename DT>
void BiTree<DT>::nPreOrder(){
    BiNode<DT> *bt = root;
    BiNode<DT> *S[Ssize];
    int top = -1;
    while(bt != nullptr || top != -1){
        while(bt != nullptr){
            cout << bt->data;
            S[++top] = bt;  // push(bt)
            bt = bt->lchild;
        }
        if(top != -1){
            bt = S[top--];
            bt = bt->rchild;
        }
    }
}
template<typename DT>
void BiTree<DT>::nInOrder(){
    BiNode<DT> *bt = root;
    BiNode<DT> *S[Ssize];
    int top = -1;
    while(bt != nullptr || top != -1){
        while(bt != nullptr){
            S[++top] = bt;  // push(bt)
            bt = bt->lchild;
        }
        if(top != -1){
            bt = S[top--];  // pop()
            cout << bt->data;
            bt = bt->rchild;
        }
    }
}
template<typename DT>
struct element{
    BiNode<DT> *ptr;
    int flag;
};  // setting a flag to mark status of lchild & rchild traversing
template<typename DT>
void BiTree<DT>::nPostOrder(){
    BiNode<DT> *bt = root;
    element<DT> S[Ssize];
    int top = -1;
    while(bt != nullptr || top != -1){
        while(bt != nullptr){
            top++;
            S[top].ptr = bt;
            S[top].flag = 1;    // push(bt & flag)
            bt = bt->lchild;
        }
        while(top != -1 && S[top].flag == 2){
            bt = S[top--].ptr;
            cout << bt->data;
        }
        if(top != -1){
            S[top].flag = 2;
            bt = S[top].ptr->rchild;
        }
    }
}

#endif  // Binary Tree