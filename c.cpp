/*
    get Max F (profit)
*/

#include <iostream>

using namespace std;

// global
int maxF = 0;
int t, N, M, K;

const int nM = 101;
const int mM = 21;

int map[nM][mM];
int mem[nM][mM];

// functions

int getF();
void changeCol(int col);
void initMap();

// solu1 dfs
int solu1();
void getCnk(int n, int k, int e = -1);
void dfs(int pos, int cnt, int n, int k, int a[], bool vis[]);

// solu2: recursion
int solu2();
void fac(int cnt);

// solu3: combination_01
int solu3();
void getCnk_01(int n, int k, int e = -1);
void combination_01(int* a, int n, int k);      // combination using 0-1 methods
void printRes(int* a, bool* index, int n);      // print result of 0-1 combination
bool hasDone(bool* index, int n, int k);        // check if k-0 are all at right for 0-1 combination


// main
int main() {
    // pre
    int a, T;
    cin >> t;
    T = t;
    while(t--)
    {
        cin >> N >> M >> K;
        // intput map
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> a;
                map[i][j] = a;
                mem[i][j] = a;
            }
        }
        // solve
        int res = 0, res2 = 0, res3 = 0;
        maxF = 0; res = solu1();
        // maxF = 0; initMap(); res2 = solu2();
        // maxF = 0; initMap(); res3 = solu3();
        // output
        cout << "#" << T-t << " " << res << " " << res2 << " " << res3 << endl;
    }
    return 0;
}
// getF
int getF()
{
    int z, sum = 0;
    for(int i = 0; i < N; i++){
        z = 1;
        for(int j = 0; j < M; j++){
            z &= map[i][j];
        }
        if(z) ++sum;
    }
    return sum;
}

// flip column
void changeCol(int col)
{
    for(int i = 0; i < N; i++){
        map[i][col] ^= 1;
    }
    return;
}

// init map
void initMap()
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = mem[i][j];
        }
    }
    return;
}

// solution 1
int solu1()
{
    // pre
    int res = 0;
    // k = 1
    getCnk(M, K);
    // k in [2, K]
    for(int i = 2; i <= K; i++){
        for(int j = 0; j < M; j++){
            // initMap();
            if(i&1) changeCol(j);
            getCnk(M-1, K-i, j);
            if(i&1) changeCol(j);
        }
    }
    // return
    res = maxF;
    return res;
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

// dfs
void dfs(int pos, int cnt, int n, int k, int a[], bool vis[])
{
    if(cnt == k){
        for(int i = 0; i < n; i++){
            if(vis[i]) // cout << a[i] <<' ';
            {
                changeCol(a[i]-1);
            }
        }
        int cur = getF();
        if(cur > maxF) maxF = cur;
        // re
        for(int i = 0; i < n; i++){
            if(vis[i]) changeCol(a[i]-1);
        }
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

// 
// solu2: recursion
int solu2()
{
    int res = 0;
    //
    maxF = 0;
    fac(0);
    res = maxF;
    // return
    return res;
}

// recursion
void fac(int cnt)
{
    if(cnt == K){
        int cur = getF();
        if(cur > maxF) maxF = cur;
        // initMap();
        return;
    }
    //
    for(int i = 0; i < M; i++){
        changeCol(i);
        fac(++cnt);
        changeCol(i);
        cnt--;
    }
}

//
// solution3
int solu3()
{
    // pre
    int res = 0;
    // k = 1
    getCnk_01(M, K);
    // k in [2, K]
    for(int i = 2; i <= K; i++){
        for(int j = 0; j < M; j++){
            // initMap();
            if(i&1) changeCol(j);
            getCnk_01(M-1, K-i, j);
            if(i&1) changeCol(j);
        }
    }
    // return
    res = maxF;
    return res;
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

void printRes(int* a, bool* index, int n)      // print result of 0-1 combination
{
    for(int i = 0; i < n; i++){
        if(index[i]) // cout << a[i] << " ";
        {
            changeCol(a[i]-1);
        }
    }
    // check f
    int cur = getF();
    if(cur > maxF) maxF = cur;
    // re
    for(int i = 0; i < n; i++){
        if(index[i]) changeCol(a[i]-1);
    }

    return;
}

bool hasDone(bool* index, int n, int k)        // check if k-0 are all at right for 0-1 combination
{
    for(int i = n-1; i >= n-k; i--){
        if(!index[i]) return false;
    }
    return true;
}


// test cases
/*
data:
4
3 3 2
0 1 0
1 0 0
1 0 0
3 3 3
0 1 0
1 0 0
1 0 0
3 4 3
0 1 0 1
1 0 1 0
0 0 0 0
3 4 4
0 1 0 1
1 0 1 0
0 0 0 0


res:
#1 2
#2 0
#3 0
#4 1
*/

/*
1
30 20 16
0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1 0 0
0 0 0 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 1 0 0 0 1 0 0 0 1 0 1 0 1 0 0 1
0 1 0 0 1 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0
0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1 0 0
0 0 1 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 0 0
0 1 0 1 1 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0
0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1 0 0
0 0 0 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1
0 1 0 0 1 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0
0 1 0 0 1 1 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 1 1 1 1 0 0
0 0 1 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 0 0
0 1 0 1 1 0 1 0 1 1 1 0 1 0 0 0 1 1 0 0
0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 1 0 0
0 0 0 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 1 0 0 0 1 0 0 0 1 0 1 0 1 0 0 1
0 1 0 0 1 0 1 0 0 1 1 0 0 0 0 0 1 1 0 0
0 1 0 0 1 0 1 0 1 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1 0 0
0 0 1 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 0 1 0 0 1 0 0 0 1 0 0 0 1 0 0 0
0 1 0 1 1 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0

*/

/*
1
20 20 10
0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1 0 0
0 0 0 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 1 0 0 0 1 0 0 0 1 0 1 0 1 0 0 1
0 1 0 0 1 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0
0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1 0 0
0 0 1 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 0 0
0 1 0 1 1 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0
0 1 0 0 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 0 1 1 1 0 0
0 0 0 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1
0 1 0 0 1 0 1 0 0 1 1 0 1 0 0 0 1 1 0 0
0 1 0 0 1 1 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 0 0 0 0 0 1 0 0 0 0 0 1 0 1 1 1 1 0 0
0 0 1 1 1 0 1 0 0 0 1 0 1 0 0 0 1 1 0 1
1 1 0 0 0 0 0 0 1 0 0 0 1 0 1 0 1 0 0 0
0 1 0 1 1 0 1 0 1 1 1 0 1 0 0 0 1 1 0 0


*/