
#include<iostream>
using namespace std;

// solution3
// int solu3()
// {
//     // pre
//     int res = 0;
//     // k = 1
//     getCnk_01(M, K);
//     // k in [2, K]
//     for(int i = 2; i <= K; i++){
//         for(int j = 0; j < M; j++){
//             // initMap();
//             if(i&1) changeCol(j);
//             getCnk_01(M-1, K-i, j);
//             if(i&1) changeCol(j);
//         }
//     }
//     // return
//     res = maxF;
//     return res;
// }
void printRes(int* a, bool* index, int n)      // print result of 0-1 combination
{
    for(int i = 0; i < n; i++){
        if(index[i]) cout << a[i] << " ";
    }
    cout << endl;
    // check f
    // int cur = getF();
    // if(cur > maxF) maxF = cur;
    // re
    // for(int i = 0; i < n; i++){
    //     if(index[i]) changeCol(a[i]-1);
    // }

    return;
}

bool hasDone(bool* index, int n, int k)        // check if k-0 are all at right for 0-1 combination
{
    for(int i = n-1; i >= n-k; i--){
        if(!index[i]) return false;
    }
    return true;
}
void combination_01(int* a, int n, int k)      // combination using 0-1 methods
{
    bool* index = new bool[n];
    // pre k = 1
    for(int i = 0; i < k; i++){
        index[i] = true;
    }
    for(int i = k; i < n; i++){
        index[i] = false;
    }
    printRes(a, index, n);

    // until all 0 are at left
    while(!hasDone(index, n, k)){
        // left --> right
        for(int i = 0; i < n-1; i++){
            // 10 --> 01
            if(index[i] && !index[i+1]){
                index[i] = false;
                index[i+1] = true;

                // 1s before 10 --> 01
                int cnt = 0;
                for(int j = 0; j < i; j++){
                    if(index[j]){
                        index[j] = false;
                        index[cnt++] = true;
                    }
                }
                // print
                printRes(a, index, n);
                break;
            }
        }
    }

    delete[] index;
}
// Combination
void getCnk_01(int n, int k, int e)
{
    // pre
    int *a = new int[n];
    // a
    for(int i = 0; i < n; i++){
        if(e == -1) a[i] = i+1;
        else if(i < e-1) a[i] = i+1;
        else a[i] = i+2;
    }
    //
    combination_01(a, n, k);
    delete[] a;

    return;
}


// combination recursion
// dfs
void dfs(int pos, int cnt, int n, int k, int a[], bool vis[])
{
    if(cnt == k){
        for(int i = 0; i < n; i++){
            if(vis[i]) cout << a[i] <<' ';
        }
        cout << endl;
        // int cur = getF();
        // if(cur > maxF) maxF = cur;
        // re
        // for(int i = 0; i < n; i++){
        //     if(vis[i]) changeCol(a[i]-1);
        // }
        // cout << endl;
        return;
    }
    //
    if(pos == n) return;
    // vis
    if(!vis[pos]){
        vis[pos] = true;
        dfs(pos+1, cnt+1, n, k, a, vis);
        // back_track
        vis[pos] = false;
    }
    dfs(pos+1, cnt, n, k, a, vis);
}
// Combination
void getCnk(int n, int k, int e)
{
    // pre
    int *a = new int[n];
    bool *vis = new bool[n];
    // a
    for(int i = 0; i < n; i++){
        if(e == -1) a[i] = i+1;
        else if(i < e-1) a[i] = i+1;
        else a[i] = i+2;
        vis[i] = false;
    }
    //
    dfs(0, 0, n, k, a, vis);
    delete[] a;
    delete[] vis;
    return;
}



int main()
{
    int n, k, e;
    while(cin >> n >> k >> e)
    {
        cout << "new-------" << endl;
        getCnk(n, k, e);
        cout << "01--------" << endl;
        getCnk_01(n, k, e);
    }
    return 0;
}