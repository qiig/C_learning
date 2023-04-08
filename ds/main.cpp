#include "MGraph.h"
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
    return 0;
}
/*
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
*/
// 6 6 0 1 1 0 2 1 0 5 1 1 2 1 1 4 1 2 3 1