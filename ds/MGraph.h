#ifndef MGRAPH_H
#define MGRAPH_H
/*
    graph: adjacency matrix method
*/
/*
#include "MGraph.h"
// main
int main(){
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    MGraph<char> MG{ch, 6, 6};
    for(int i = 0; i < MaxS; i++){
        visited[i] = 0;
    }
    cout << "depth first traverse: ";
    MG.DFTraverse(0);
    for(int i = 0; i < MaxS; i++){
        visited[i] = 0;
    }
    cout << endl << "breadth first traverse: ";
    MG.BFTraverse(0);
    return 0;
}
// test
    data:
    0 1 0 2 0 5 1 2 1 4 2 3
    res:
    depth first traverse: ABCDEF
    breadth first traverse: ABCFED
*/
#include<iostream>
using namespace std;
const int MaxS = 10;    // vertex
int visited[MaxS] = {0};
template<typename DT>
class MGraph{
    public:
        MGraph(DT a[], int n, int e);   // vertices array, number of vertices, number of edges
        ~MGraph(){};
        void DFTraverse(int v); // depth-first traverse & vertex v
        void BFTraverse(int v); // breadth-first traverse & vertex v
    private:
        DT vertex[MaxS];    // saving vertices
        int edge[MaxS][MaxS];   // saving edges
        int verN, edgN; // saving n & e
};
template<typename DT>
MGraph<DT>::MGraph(DT a[], int n, int e){
    int r, c;
    verN = n; edgN = e;
    for(int i = 0; i < verN; i++){
        vertex[i] = a[i];
    }
    for(int i = 0; i < verN; i++){
        for(int j = 0; j < verN; j++){
            edge[i][j] = 0; // init edge
        }
    }
    for(int i = 0; i < edgN; i++){
        cin >> r >> c;
        edge[r][c] = 1; edge[c][r] = 1; // undirected graph
    }
}
template<typename DT>
void MGraph<DT>::DFTraverse(int v){
    cout << vertex[v]; visited[v] = 1;
    for(int j = 0; j < verN; j++){
        if(edge[v][j] == 1 && visited[j] == 0) DFTraverse(j);
    }
}
template<typename DT>
void MGraph<DT>::BFTraverse(int v){
    int w, Q[MaxS];
    int front = -1, rear = -1;  // init queue
    cout << vertex[v]; visited[v] = 1;
    Q[++rear] = v;
    while(front != rear){   // queue is not empty
        w = Q[++front]; 
        for(int i = 0; i < verN; i++){
            if(edge[w][i] == 1 && visited[i] == 0){
                cout << vertex[i]; visited[i] = 1;
                Q[++rear] = i;
            }
        }
    }
}

#endif  // matrix saving method of undirected graph