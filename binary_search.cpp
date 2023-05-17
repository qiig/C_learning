/*
    binary search

*/
#include<iostream>
using namespace std;

int biSearch(int k, int low, int high, int data[])
{
    int mid;

    while(low <= high)
    {
        mid = (low+high)/2;
        if(k < data[mid]) high = mid-1;
        else if(k > data[mid]) low = mid+1;
        else return mid;
    }

    return 0;
}

int main()
{
    int data[] = {1, 3, 5, 7, 8, 9, 11, 12, 13,26, 45, 56, 57, 58, 59, 123, 156};
    
    cout << biSearch(8, 0, 16, data) << endl;

    cout << biSearch(59, 0, 16, data) << endl;

    return 0;
}