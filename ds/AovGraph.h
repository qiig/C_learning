#ifndef AOVGRAPH_H
#define AOVGRAPH_H
/*
    activity of vertex network
    from class ALGraph
*/
/*
#include "AovGraph.h"
// main
int main(){
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    AovGraph<char> ALG{ch, 7, 10};
    cout << "topological sort: ";
    ALG.TopSort();
    return 0;
}
// test
data1:
    1 3 1 2 0 2 0 4 3 5 2 5 2 6 2 4 4 6 5 6
res1:
    topological sort: BDACFEG
*/
#include<iostream>
using namespace std;
const int MaxS = 10;
struct EdgeNode{
    int adjvex;
    EdgeNode* next;
};
template<typename DT>
struct VerNode{
    int in;
    DT vertex;
    EdgeNode *firstEdge;
};
template<typename DT>
class AovGraph{
    public:
        AovGraph(DT a[], int n, int e);
        ~AovGraph();
        void TopSort();
    private:
        VerNode<DT> adjlist[MaxS];
        int vertexN, edgeN;
};
template<typename DT>
AovGraph<DT>::AovGraph(DT a[], int n, int e){
    int vo, vi; // vertex out / in
    EdgeNode* s = nullptr;
    vertexN = n; edgeN = e;
    for(int i = 0; i < vertexN; i++){
        adjlist[i].in = 0;
        adjlist[i].vertex = a[i];
        adjlist[i].firstEdge = nullptr;
    }
    for(int i = 0; i < edgeN; i++){
        cin >> vo >> vi;
        s = new EdgeNode;
        s->adjvex = vi;
        s->next = adjlist[vo].firstEdge;
        adjlist[vo].firstEdge = s;
        adjlist[vi].in++;
    }
}
template<typename DT>
AovGraph<DT>::~AovGraph(){
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
void AovGraph<DT>::TopSort(){
    int i, j, k, cnt = 0;
    int S[MaxS], top = -1;  // sequential stack
    EdgeNode *p = nullptr;
    for(i = 0; i < vertexN; i++){
        if(adjlist[i].in == 0){
            S[++top] = i;
        }
    }
    while(top != -1){
        j = S[top--];
        cout << adjlist[j].vertex;
        cnt++;
        p = adjlist[j].firstEdge;
        while(p != nullptr){
            k = p->adjvex;
            adjlist[k].in--;
            if(adjlist[k].in == 0) S[++top] = k;
            p = p->next;
        }
    }
    if(cnt < vertexN) cout << "existing circuit!";
}

#endif  // activity of vertex network