#include "ALGraph_ts.h"
// main
int main(){
    char ch[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    AovGraph<char> ALG{ch, 7, 10};
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
    cout << endl << "topological sort: ";
    ALG.TopSort();
    return 0;
}
/*
1 3 1 2 0 2 0 4 3 5 2 5 2 6 2 4 4 6 5 6
*/