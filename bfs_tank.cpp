/*
    Tank
*/
#include<iostream>
using namespace std;

int n, m;
const int nM = 50;
int vis[nM][nM][nM][nM];
int map[nM][nM];
int dir[9][2] = {1,1,1,0,1,-1,0,1,0,0,0,-1,-1,1,-1,0,-1,1};

typedef struct _nod
{
    int x1, y1;
    int x2, y2;
    int step;
}_nod;

void initVis()
{
    for(int i = 0; i < nM; i++){
        for(int j = 0; j < nM; j++){
            for(int k = 0; k < nM; k++){
                for(int g = 0; g < nM; g++){
                    vis[i][j][k][g] = 0;
                }
            }
        }
    }
}

void initMap()
{
    for(int i = 0; i < nM; i++){
        for(int j = 0; j < nM; j++){
            map[i][j] = 0;
        }
    }
}

int bfs(_nod a, _nod b)
{
    // pre
    int minS = -1;
    _nod cur, nex;
    initVis();
    int x1b, x2b, x1e, x2e, y1b, y2b, y1e, y2e;
    x1b = a.x1; x2b = a.x2; y1b = a.y1; y2b = a.y2;
    x1e = b.x1; x2e = b.x2; y1b = b.y1; y2b = b.y2;
    cur.x1 = a.x1; cur.x2 = a.x2; cur.y1 = a.y1; cur.y2 = a.y2;
    cur.step = 0;
    // queue
    _nod que[nM];
    int fro = -1, rea = -1;

    // init
    que[++rea] = cur;
    vis[cur.x1][cur.y1][cur.x2][cur.y2] = 1;
#if 1
    while(fro < rea)
    {
        cur = que[++fro];
        if(cur.x1 == x1e && cur.x2 == x2e && cur.y1 == y1e && cur.y2 == y2e){
            minS = cur.step; break;
        }
        // more
        for(int i = 0; i < 9; i++){
            nex.x1 = cur.x1 + dir[i][0];
            nex.y1 = cur.y1 + dir[i][1];
            if(map[nex.x1][nex.y1] == -1) continue;
            if(nex.x1 < 0 || nex.x1 >= m) continue;
            if(nex.y1 < 0 || nex.y1 >= n) continue;
            for(int j = 0; j < 9; j++){
                nex.x2 = cur.x2 + dir[j][0];
                nex.y2 = cur.y2 + dir[j][0];
                //
                if(map[nex.x2][nex.y2] == -1) continue;
                // check 
                if(nex.x2 < 0 || nex.x2 >= m) continue;
                if(nex.y2 < 0 || nex.y2 >= n) continue;
                //
                if(vis[nex.x1][nex.y1][nex.x2][nex.y2] == 1) continue;
                if((nex.x1-nex.x2)*(nex.x1-nex.x2)+(nex.y1-nex.y2)*(nex.y1-nex.y2) > 2) {
                    vis[nex.x1][nex.y1][nex.x2][nex.y2] = 1;
                    nex.step = cur.step + 1;
                    que[++rea] = nex;
                }
            }

        }
        cout << fro << " ->> " << rea << endl;
    }
#endif
    return minS;
}

int main()
{
    int res = 0;
    int t, cnt = 0;
    cin >> t;
    while(cnt < t)
    {
        // pre
        _nod a, b;
        // input
        cout << "n & m: ";
        cin >> n >> m;
        initMap();
        cout << endl << "map: " << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> map[i][j];
            }
        }
        cout << endl << "start index: ";
        int x1b, x2b, x1e, x2e, y1b, y2b, y1e, y2e;
        cin >> x1b >> y1b >> x2b >> y2b;
        cout << endl << "end index: ";
        cin >> x1e >> y1e >> x2e >> y2e;
        cout << endl;
        a.x1 = x1b; a.y1 = y1b; a.x2 = x2b; a.y2 = y2b;
        b.x1 = x1e; b.y1 = y1e; b.x2 = x2e; b.y2 = y2e;
        a.step = 0; b.step = 0;
        // bfs
        res = bfs(a, b);
        // res
        
        // output
        cout << "#" << ++cnt << " " << res << endl;
    }
    return 0;
}

/*
1
5 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 -1
0 0 0 0 0 0
0 0 0 0 0 0
0 0 5 0
0 4 4 5

*/