#ifndef MGRAPH_H
#define MGRAPH_H
/*
    graph: adjacency matrix method
*/
/*
#include "MGraph_k.h"
// main
int main(){
    int vn, en; // num. of vertices & edges
    cin >> vn >> en;
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    MGraph<char> MG{ch, vn, en};
    for(int i = 0; i < MaxS; i++){
        visited[i] = 0;
    }
    cout << "depth first traverse: ";
    MG.DFTraverse(0);
    for(int i = 0; i < MaxS; i++){
        visited[i] = 0;
    }
    cout << endl << "breadth first traverse: ";
    try{
        MG.BFTraverse(0);
    } catch(const char* str){cout << str << endl;}
    cout << endl << "prim: " << endl;
    MG.Prim(0);
    cout << "Kruskal: " << endl;
    MG.Kruskal();
    return 0;
}
// test
data1:
    6 6 0 1 1 0 2 1 0 5 1 1 2 1 1 4 1 2 3 1
res1:
    depth first traverse: ABCDEF
    breadth first traverse: ABCFED
    prim:
    0 -> 1 : 1
    0 -> 2 : 1
    2 -> 3 : 1
    1 -> 4 : 1
    0 -> 5 : 1
    Kruskal:
    (0, 1) 1
    (0, 2) 1
    (0, 5) 1
    (1, 4) 1
    (2, 3) 1
data2:
    6 9
    0 1 34
    0 2 46
    0 5 19
    1 4 12
    2 3 17
    2 5 25
    3 4 38
    3 5 25
    4 5 26
res2:
    depth first traverse: ABEDCF
    breadth first traverse: ABCFED
    prim:
    0 -> 5 : 19
    5 -> 2 : 25
    2 -> 3 : 17
    5 -> 4 : 26
    4 -> 1 : 12
    Kruskal:
    (1, 4) 12
    (2, 3) 17
    (0, 5) 19
    (2, 5) 25
    (4, 5) 26
data3:
    6 9
    0 1 34
    0 2 46
    0 5 19
    3 5 25
    1 4 12
    2 3 17
    2 5 25
    3 4 38
    4 5 26
res3:
    depth first traverse: ABEDCF
    breadth first traverse: ABCFED
    prim:
    0 -> 5 : 19
    5 -> 2 : 25
    2 -> 3 : 17
    5 -> 4 : 26
    4 -> 1 : 12
    Kruskal:
    (1, 4) 12
    (2, 3) 17
    (0, 5) 19
    (3, 5) 25
    (4, 5) 26
*/
#include<iostream>
using namespace std;
const int MaxS = 101;    // vertex
const int MaxE = 101;   // edge
int visited[MaxS] = {0};
struct EdgeType{
    int from, to, weight;
};  // struct of edge set array
template<typename DT>
class MGraph{
    public:
        MGraph(DT a[], int n, int e);   // vertices array, number of vertices, number of edges
        ~MGraph(){};
        void DFTraverse(int v); // depth-first traverse & vertex v
        void BFTraverse(int v); // breadth-first traverse & vertex v
        void Prim(int v);   // find minimal spanning tree
        void Kruskal(); // find minimal spanning tree 
    private:
        DT vertex[MaxS];    // saving vertices
        int edge[MaxS][MaxS];   // saving edges
        int verN, edgN; // saving n & e
        const int maxWei = 99999;   // max weigh
        const int MaxSQ = 21;   // max queue
        EdgeType edges[MaxE];   // saving edge set
        int MinEdge(int lc[], int verN);   // find min weight and return its index
        int FindRoot(int parent[], int v);  // find the root of vertex v
        void GetEdgeS();
};
template<typename DT>
MGraph<DT>::MGraph(DT a[], int n, int e){
    int r, c, w;
    verN = n; edgN = e;
    for(int i = 0; i < verN; i++){
        vertex[i] = a[i];
    }
    for(int i = 0; i < verN; i++){
        for(int j = 0; j < verN; j++){
            if(i == j) edge[i][j] = 0; // init edge
            else edge[i][j] = maxWei;
        }
    }
    for(int i = 0; i < edgN; i++){
        cin >> r >> c >> w;
        edge[r][c] = w; edge[c][r] = w; // undirected graph
        edges[i].from = r; edges[i].to = c;
        edges[i].weight = w;
    }
}
template<typename DT>
void MGraph<DT>::DFTraverse(int v){
    cout << vertex[v]; visited[v] = 1;
    for(int j = 0; j < verN; j++){
        if(edge[v][j] != 0 && edge[v][j] < maxWei && visited[j] == 0) DFTraverse(j);
    }
}
template<typename DT>
void MGraph<DT>::BFTraverse(int v){
    int w, Q[MaxSQ];
    int front = -1, rear = -1;  // init queue
    cout << vertex[v]; visited[v] = 1;
    if((rear + 1) % MaxSQ == front) throw "error: overflow. ";
    rear = (rear + 1) % MaxSQ;
    Q[rear] = v;
    while(front != rear){   // queue is not empty
        if(rear == front) throw "error: underflow. ";
        front = (front + 1) % MaxSQ;
        w = Q[front]; 
        for(int i = 0; i < verN; i++){
            if(edge[w][i] != 0 && edge[w][i] < maxWei && visited[i] == 0){
                cout << vertex[i]; visited[i] = 1;
                if((rear + 1) % MaxSQ == front) throw "error: overflow. ";
                rear = (rear + 1) % MaxSQ;
                Q[rear] = i;
            }
        }
    }
}
template<typename DT>
void MGraph<DT>::Prim(int v){
    int vi;
    int adjvex[MaxS], lowcost[MaxS];
    for(int i = 0; i < verN; i++){  // init
        lowcost[i] = edge[v][i];
        adjvex[i] = v;
    }
    lowcost[v] = 0; // v in U
    for(int i = 1; i < verN; i++){
        vi = MinEdge(lowcost, verN);    // find vi of minimal edge
        cout << adjvex[vi] << " -> " << vi << " : " << lowcost[vi] << endl;
        lowcost[vi] = 0;    // vi in U
        for(int j = 0; j < verN; j++){
            if(edge[j][vi] < lowcost[j]){
                lowcost[j] = edge[j][vi];
                adjvex[j] = vi;
            }
        }
    }
}
template<typename DT>
int MGraph<DT>::MinEdge(int lc[], int verN){
    int minVal, minInd; // minimal value & its index
    minVal = maxWei; minInd = 0;
    for(int i = 1; i < verN; i++){
        if(minVal > lc[i] && lc[i] != 0){
            minVal = lc[i];
            minInd = i;
        }
    }
    return minInd;
}
template<typename DT>
void MGraph<DT>::GetEdgeS(){
#if 1   // sort1
    int cfrom, cto, cweight;
    for(int i = 0; i < edgN; i++){
        for(int j = 0; j < edgN - i - 1; j++){
            if(edges[j].weight > edges[j+1].weight){
                cfrom = edges[j].from; cto = edges[j].to; cweight = edges[j].weight;
                edges[j].from = edges[j+1].from;
                edges[j].to = edges[j+1].to;
                edges[j].weight = edges[j+1].weight;
                edges[j+1].from = cfrom; edges[j+1].to = cto; edges[j+1].weight = cweight;
            }
        }
    }
#endif
#if 0   // sort2

#endif
}
template<typename DT>
void MGraph<DT>::Kruskal(){
    int num = 0, i, vex1, vex2;
    int parent[verN];
    GetEdgeS();
    for(int i = 0; i < verN; i++){
        parent[i] = -1;
    }
    for(num = 0, i = 0; num < verN - 1; i++){
        vex1 = FindRoot(parent, edges[i].from);
        vex2 = FindRoot(parent, edges[i].to);
        if(vex1 != vex2){
            cout << "(" << edges[i].from << ", " << edges[i].to;
            cout << ") " << edges[i].weight << endl;
            parent[vex2] = vex1;
            num++;
        }
    }
}
template<typename DT>
int MGraph<DT>::FindRoot(int parent[], int v){
    int t = v;
    while(parent[t] > -1){
        t = parent[t];
    }
    return t;
}

#endif  // matrix saving method of undirected graph