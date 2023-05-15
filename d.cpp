/*
    permutation & combination

*/
#include<iostream>
using namespace std;

// global

// functions

// permutation
void permutation(int start, int end, int a[]);

// combination dfs
void combination_dfs(int pos, int cnt, int n, int m, int a[], bool ind[]);

// combination 0-1
void combination_01(int* a, int n, int m);
void printRes(int* a, bool* vis, int n);
bool hasDone(bool* vis, int n, int m);


// main
int main()
{
    int n, m, k;
    while(cin >> n >> m >> k && n != 0)
    {
        // pre a & vis
        int* a = new int[n];
        bool* vis = new bool[n];
        for(int i = 0; i < n; i++){
            if(k == -1 || i < k-1) a[i] = i+1;
            else a[i] = i+2;
            vis[i] = false;
        }

        // printf
        cout << "permutation: " << endl;
        permutation(0, n, a);

        cout << "combination dfs: " << endl;
        //combination_dfs(0, 0, n, m, a, vis);

        cout << "combination 0-1: " << endl;
        //combination_01(a, n, m);

        delete[] a;
        delete[] vis;
    }

    return 0;
}

// define
// permutation
void permutation(int start, int end, int a[])
{
    if(start == end){
        for(int i = 0; i < end; i++){
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    //
    int tmp = 0;
    for(int i = start; i < end; i++){
        // swap
        tmp = a[start]; a[start] = a[i]; a[i] = tmp;
        // next
        permutation(start+1, end, a);
        // swap
        tmp = a[start]; a[start] = a[i]; a[i] = tmp;
    }
}

// combination dfs
void combination_dfs(int pos, int cnt, int n, int m, int a[], bool vis[])
{
    // cnt = k
    if(cnt == m){
        for(int i = 0; i < n; i++){
            if(vis[i]) cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    // pos = n
    if(pos == n) return;

    // 
    if(!vis[pos]){
        vis[pos] = true;
        // next k
        combination_dfs(pos+1, cnt+1, n, m, a, vis);
        // back_track
        vis[pos] = false;
    }
    
    // next n
    combination_dfs(pos+1, cnt, n, m, a, vis);
}

// combination_01
void combination_01(int* a, int n, int m)
{
    // pre vis
    bool* vis = new bool[n];
    // 
    for(int i = 0; i < m; i++){
        vis[i] = true;
    }
    for(int i = m; i < n; i++){
        vis[i] = false;
    }

    printRes(a, vis, n);

    // do until all 1s are at right
    while(!hasDone(vis, n, m))
    {
        for(int i = 0; i < n-1; i++){
            if(vis[i] && !vis[i+1]){
                vis[i] = false;
                vis[i+1] = true;

                // 1s before 10 -> 01
                int cnt = -1;
                for(int j = 0; j < i; j++){
                    if(vis[j]){
                        vis[j] = false;
                        vis[++cnt] = true;
                    }
                }

                printRes(a, vis, n);
                break;
            }
        }
    }

    delete[] vis;
}

void printRes(int* a, bool* vis, int n)
{
    for(int i = 0; i < n; i++){
        if(vis[i]) cout << a[i] << " ";
    }
    cout << endl;
    return;
}

bool hasDone(bool* vis, int n, int m)
{
    for(int i = n-1; i >= n-m; i--){
        if(!vis[i]) return false;
    }
    return true;
}