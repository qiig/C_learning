#include "Sort.h"
// main
int main(){
    int select, r[10] = {2, 5, 1, 7, 9, 4, 3, 6, 5, 8};
    Sort L{r, 10};
    cout << "1.InsertSort   2.ShellSort " << endl;
    cout << "3.BubbleSort   4.QuickSort " << endl;
    cout << "5.SpSeleSort   6.Heap Sort " << endl;
    cout << "7.MergeRSort   8.MergeSort " << endl;
    cout << "Choosing Method No.";
    cin >> select;
    switch(select){
        case 1: L.InsertSort(); break;
        case 2: L.ShellSort(); break;
        case 3: L.BubbleSort(); break;
        case 4: L.QuickSort(0, 9); break;
        case 5: L.SelectSort(); break;
        case 6: L.HeapSort(); break;
        case 7: L.MergeSort1(0, 9); break;
        case 8: L.MergeSort2(); break;
        default: cout << "error: wrong index. " << endl; break;
    }
    L.Print();
    return 0;
}