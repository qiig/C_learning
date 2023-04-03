#ifndef BITREE_H
#define BITREE_H
/*
    Binary Tree
    Level Order Traverse:
        changing sequential queue to circular queue.
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
    private:
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
    char ch;
    cin >> ch;
    if(ch == '#') bt = nullptr;
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
    int Qsize = 20;
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

#endif  // Binary Tree