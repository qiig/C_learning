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
    cout << "Floyd: A -> C " << endl;
    MG.Floyd();
    MG.PrintFloyd(0,2);
    cout << "Floyd: " << endl;
    MG.PrintFloyd();    
    return 0;
}
/*
3 5 1
0 1 4
0 2 11
1 0 6
1 2 2
2 0 3
*/