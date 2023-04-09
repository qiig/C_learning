#include "MGraph_kd.h"
// main
int main(){
    int vn, en, isDire; // num. of vertices & edges
    cin >> vn >> en >> isDire;  // isDire = 0: undirected graph
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    MGraph<char> MG{ch, vn, en, isDire};
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
    cout << "Dijkstal: " << endl;
    MG.Dijkstra(0);
    return 0;
}
/*
5 7 1
0 1 10
0 3 30
0 4 100
1 2 50
2 4 10
3 2 20
3 4 60
*/