#ifndef SORT_H
#define SORT_H
/*
    sort methods
*/
/*
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
*/
#include<iostream>
#include<cmath>
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
void Sort::BubbleSort(){
    int exchange, bound, temp;
    exchange = length - 1;
    while(exchange != 0){
        bound = exchange; exchange = 0;
        for(int i = 0; i < bound; i++){
            if(data[i] > data[i+1]){
                temp = data[i];
                data[i] = data[i+1];
                data[i+1] = temp;
                exchange = i;
            }
        }
    }
}
int Sort::Partition(int first, int last){
    int i = first, j = last, temp;
    while(i < j){
        while(i < j && data[i] <= data[j]) j--; // right
        if(i < j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
        }
        while(i < j && data[i] <= data[j]) i++; //left
        if(i < j){
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            j--;
        }
    }
    return i;
}
void Sort::QuickSort(int first, int last){
    if(first > last) return;
    else{
        int pivot = Partition(first, last);
        QuickSort(first, pivot - 1);    // left
        QuickSort(pivot + 1, last);     // right
    }
}
void Sort::SelectSort(){
    int temp, index;
    for(int i = 0; i < length - 1; i++){
        index = i;
        for(int j = i + 1; j < length; j++){
            if(data[j] < data[index]) index = j;
        }
        if(index != i){
            temp = data[i];
            data[i] = data[index];
            data[index] = temp;
        }
    }
}
void Sort::Sift(int k, int last){
    int i, j, temp;
    i = k; j = 2 * i + 1;   // j is lchild of i
    while(j <= last){
        if(j < last && data[j] < data[j+1]) j++;    // choose max(lchild, rchild)
        if(data[i] > data[j]) break;
        else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i = j;
            j = 2 * i + 1;
        }
    }
}
void Sort::HeapSort(){
    int i, temp;
    for(i = ceil<int>(length/2)-1; i >= 0; i--){
        Sift(i, length-1);
    }
    for(i = 1; i < length; i++){
        temp = data[0];
        data[0] = data[length - i];
        data[length - i] = temp;
        Sift(0, length - i -1);
    }
}
void Sort::Merge(int first1, int last1, int last2){
    int *temp = new int[length];
    int i = first1, j = last1 + 1, k = first1;
    while(i <= last1 && j <= last2){
        if(data[i] <= data[j]){
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }
    while(i <= last1){
        temp[k++] = data[i++];
    }
    while(j <= last2){
        temp[k++] = data[j++];
    }
    for(i = first1; i <= last2; i++){
        data[i] = temp[i];
    }
    delete[] temp;
}
void Sort::MergeSort1(int first, int last){
    if(first == last) return;
    else {
        int mid = (first + last)/2;
        MergeSort1(first, mid);     // sort left seq
        MergeSort1(mid+1, last);    // sort right seq
        Merge(first, mid, last);    // merge left & right
    }
}
void Sort::MergePass(int h){
    int i = 0;
    while(i + 2 * h <= length){
        Merge(i, i+h-1, i+2*h-1);
        i += 2 * h;
    }
    if(i + h < length){
        Merge(i, i+h-1, length-1);
    }
}
void Sort::MergeSort2(){
    int h = 1;
    while(h < length){
        MergePass(h);
        h *= 2;
    }
}

#endif  // sort