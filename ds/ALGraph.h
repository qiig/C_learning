#ifndef ALGRAPH_H
#define ALGRAPH_H
/*
    adjacency list graph
*/
/*
#include "ALGraph.h"
// main
int main(){
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    ALGraph<char> ALG{ch, 6, 6};
    for(int i = 0; i < MaxS; i++){
        visited[i] = 0;
    }
    cout << "depth first traverse: ";
    ALG.DFTraverse(0);
    for(int i = 0; i < MaxS; i++){
        visited[i] = 0;
    }
    cout << endl << "breadth first traverse: ";
    ALG.BFTraverse(0);
    return 0;
}
// test
    data:
    0 1 0 2 0 5 1 2 1 4 2 3
    res:
    depth first traverse: AFCDBE
    breadth first traverse: AFCBDE
*/
#include<iostream>
using namespace std;

const int MaxS = 10;
int visited[MaxS] = {0};  // !: remember to init visited array
struct EdgeNode{
    int adjvex;
    EdgeNode* next;
};
template<typename DT>
struct VertexNode{
    DT vertex;
    EdgeNode* firstEdge;
};
template<typename DT>
class ALGraph{
    VertexNode<DT> adjlist[MaxS];   // saving vertex nodes
    public:
        ALGraph(DT a[], int n, int e);
        ~ALGraph();
        void DFTraverse(int v); // depth first traverse
        void BFTraverse(int v); // breadth first traverse
    protected:
        int vertexN, edgeN;
};
template<typename DT>
ALGraph<DT>::ALGraph(DT a[], int n, int e){
    int vo, vi; // vertex out / in
    EdgeNode* s = nullptr;
    vertexN = n; edgeN = e;
    for(int i = 0; i < vertexN; i++){
        adjlist[i].vertex = a[i];
        adjlist[i].firstEdge = nullptr;
    }
    for(int i = 0; i < edgeN; i++){
        cin >> vo >> vi;
        s = new EdgeNode;
        s->adjvex = vi;
        s->next = adjlist[vo].firstEdge;
        adjlist[vo].firstEdge = s;
    }
}
template<typename DT>
ALGraph<DT>::~ALGraph(){
    EdgeNode *p = nullptr, *q = nullptr;
    for(int i = 0; i < vertexN; i++){
        p = q = adjlist[i].firstEdge;
        while(p != nullptr){
            p = p->next;
            delete q;
            q = p;
        }
    }
}
template<typename DT>
void ALGraph<DT>::DFTraverse(int v){
    int vi;
    EdgeNode* p = nullptr;
    cout << adjlist[v].vertex;
    visited[v] = 1;
    p = adjlist[v].firstEdge;
    while(p != nullptr){
        vi = p->adjvex;
        if(visited[vi] == 0) DFTraverse(vi);
        p = p->next;
    }
}
template<typename DT>
void ALGraph<DT>::BFTraverse(int v){
    int w, vi, Q[MaxS];
    int front = -1, rear = -1;
    EdgeNode* p = nullptr;
    cout << adjlist[v].vertex; visited[v] = 1;
    Q[++rear] = v;
    while(front != rear){
        w = Q[++front];
        p = adjlist[w].firstEdge;
        while(p != nullptr){
            vi = p->adjvex;
            if(visited[vi] == 0){
                cout << adjlist[vi].vertex;
                visited[vi] = 1;
                Q[++rear] = vi;
            }
            p = p->next;
        }
    }
}

#endif  // adjacency list graph