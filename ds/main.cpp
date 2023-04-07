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
