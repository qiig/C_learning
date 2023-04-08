#ifndef EDGEGRAPH_H
#define EDGEGRAPH_H
/*
    Kruskal, edge set array
*/
/*
#include "EdgeGraph.h"
// main
int main(){
    int vn, en; // num. of vertices & edges
    cin >> vn >> en;
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    EdgeGraph<char> EG{ch, vn, en};
    cout << "Kruskal: " << endl;
    EG.Kruskal();
    return 0;
}
// test
data:
    6 9
    1 4 12
    2 3 17
    0 5 19
    2 5 25
    3 5 25
    4 5 26
    0 1 34
    3 4 38
    0 2 46
res:
    Kruskal:
    (1, 4) 12
    (2, 3) 17
    (0, 5) 19
    (2, 5) 25
    (4, 5) 26
*/
#include<iostream>
using namespace std;
struct EdgeType{
    int from, to, weight;
};
const int MaxEdge = 100;
const int MaxVertex = 10;
template<typename DT>
class EdgeGraph{
    public:
        EdgeGraph(DT a[], int n, int e);
        ~EdgeGraph(){};
        void Kruskal();
    private:
        int FindRoot(int parent[], int v);  // find the root of vertex v
        DT vertex[MaxVertex];   // saving vertices
        EdgeType edge[MaxEdge]; // saving edge set
        int verN, edgN;
};
template<typename DT>
EdgeGraph<DT>::EdgeGraph(DT a[], int n, int e){
    verN = n; edgN = e;
    int f, t, w;
    for(int i = 0; i < verN; i++){
        vertex[i] = a[i];
    }
    for(int i = 0; i < edgN; i++){
        cin >> f >> t >> w;
        edge[i].from = f;
        edge[i].to = t;
        edge[i].weight = w;
    }
}
template<typename DT>
void EdgeGraph<DT>::Kruskal(){
    int num = 0, i, vex1, vex2;
    int parent[verN];
    for(int i = 0; i < verN; i++){
        parent[i] = -1;
    }
    for(num = 0, i = 0; num < verN - 1; i++){
        vex1 = FindRoot(parent, edge[i].from);
        vex2 = FindRoot(parent, edge[i].to);
        if(vex1 != vex2){
            cout << "(" << edge[i].from << ", " << edge[i].to;
            cout << ") " << edge[i].weight << endl;
            parent[vex2] = vex1;
            num++;
        }
    }
}
template<typename DT>
int EdgeGraph<DT>::FindRoot(int parent[], int v){
    int t = v;
    while(parent[t] > -1){
        t = parent[t];
    }
    return t;
}

#endif  // edge set array : Kruskal