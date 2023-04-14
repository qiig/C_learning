#include "RadixSort.h"
// main
int main(){
    int select;
    int r[10] = {2, 5, 1, 7, 9, 4, 3, 6, 5, 8};
    // int r[10] = {61, 98, 12, 15, 20, 24, 31, 99, 23, 35};
    RadixSort<int> L{r, 10, 2};
    // L.GetAns();
    L.Print();
    return 0;
}

/*
int r[10] = {2, 5, 1, 7, 9, 4, 3, 6, 5, 8};
int r[10] = {61, 98, 12, 15, 20, 24, 31, 99, 23, 35};
*/