/*
    Slave & Master
    
    Input:  n, m; n slaves & n masters
    Func.:
    Output: min. steps
*/
#include<iostream>

using namespace std;

const int nM = 10;
int n, m;
int vis[nM][nM];

typedef struct _nod
{
    int lm, ls, s;
}_nod;

void initVis()
{
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0 || i == n){
                vis[i][j] = 0;
            } else if(i == j){
                vis[i][j] = 0;
            } else {
                vis[i][j] = 1;
            }
        }
    }
}

int bfs()
{
    // pre
    _nod cur, nex;
    _nod que[nM];
    int minS = -1;
    int fro = -1, rea = -1;
    
    // init
    initVis();
    cur.lm = n; cur.ls = n; cur.s = 0;
    que[++rea] = cur;
    vis[cur.lm][cur.ls] = 1;
    // scan
    while(fro < rea)
    {
        cur = que[++fro];
        if(cur.lm == 0 && cur.ls == 0){
            minS = cur.s;
            break;
        }
        for(int i = m; i >= 0; i--){
            for(int j = m-i; j >= 0; j--){
                if(i+j==0 || i!=j) continue;
                if(i>cur.lm||j>cur.ls||vis[cur.lm-i][cur.ls-j]==1) continue;
                vis[cur.lm-i][cur.ls-j] = 1;
                nex.lm = cur.lm - i;
                nex.ls = cur.ls - j;
                nex.s = cur.s + 1;
                que[++rea] = nex;
            }
        }
    }
    return minS;
}

int main()
{
    int t, res, cnt = 0;
    cin >> t;
    while(cnt < t)
    {
        // input
        cin >> n >> m;
        // res
        res = bfs();
        // output
        cout << "#" << ++cnt << " " << res << endl;
    }

    return 0;
}