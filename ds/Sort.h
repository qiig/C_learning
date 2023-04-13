#ifndef SORT_H
#define SORT_H
/*
    sort methods
*/
#include<iostream>
using namespace std;
class Sort{
    public:
        Sort(int r[], int n);   // creat
        ~Sort();    // destory
        void InsertSort();  // straight insertion sort
        void ShellSort();   // shell sort
        void BubbleSort();  //bubble sort
        void QuickSort(int first, int last);    // quick sort
        void SelectSort();  // simple selection sort
        void HeapSort();    // heap sort
        void MergeSort1(int first, int last);   // 2-way merge sort (recursive)
        void MergeSort2();  // 2-way merge sort (non recursive)
        void Print();
    private:
        int Partition(int first, int last); // quick sort
        void Sift(int k, int last); // heap sort
        void Merge(int first1, int last1, int last2);   // merge sort
        void MergePass(int h);  // merge sort
        int *data;
        int length;
};
Sort::Sort(int r[], int n){
    data = new int[n];
    for(int i = 0; i < n; i++){
        data[i] = r[i];
    }
    length = n;
}
Sort::~Sort(){
    delete[] data;
}
void Sort::Print(){
    for(int i = 0; i < length; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}
void Sort::InsertSort(){
    int j, temp;
    for(int i = 1; i < length; i++){
        temp = data[i];
        for(j = i - 1; j >= 0 && temp < data[j]; j--){
            data[j+1] = data[j];
        }
        data[j+1] = temp;
    }
}
void Sort::ShellSort(){
    int d, i, j, temp;
    for(d = length/2; d >= 1; d = d/2){
        for(i = d; i < length; i++){
            temp = data[i];
            for(j = i - d; j >= 0 && temp < data[j]; j = j - d){
                data[j+d] = data[j];
            }
            data[j+d] = temp;
        }
    }
}   // same as InsertSort: d = 1


#endif  // sort