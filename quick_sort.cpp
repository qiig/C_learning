/*
    quick sort

*/
#include<iostream>
using namespace std;

int partion(int l, int r, int data[])
{
    int i = l, j = r;

    while(i < j)
    {
        while(i < j && data[i] <= data[j]) j--;
        if(i < j){
            int tmp = data[i]; data[i] = data[j];
            data[j] = tmp; i++;
        }

        while(i < j && data[i] <= data[j]) i++;
        if(i < j){
            int tmp = data[i]; data[j] = data[i];
            data[i] = tmp; j--;
        }
    }

    return i;
}

void quickS(int l, int r, int data[])
{
    if(l >= r) return;

    int pivot = partion(l, r, data);
    quickS(l, pivot-1, data);
    quickS(pivot+1, r, data);

    return;
}

int main()
{
    int data[] = {3, 6, 5, 0, 9, 1, 6, 34, 0, 89, 15};

    quickS(0, 10, data);

    for(int i = 0; i < 11; i++) cout << data[i] << " ";
    cout << endl;

    return 0;
}