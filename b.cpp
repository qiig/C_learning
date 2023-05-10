/*
    Generating a Map Application
*/
#include<iostream>
using namespace std;

const int qM = 100;
const int mM = 8;
int map[mM][mM];
int vis[mM][mM];
int viS[mM][mM];
int pat[mM][mM];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int t, n, m;

typedef struct _nod
{
    int x, y, val;
    _nod* next;
}_nod;

typedef struct _nod2
{
    int x, y, s;
}_nod2;

void initMV()
{
    for(int i = 0; i < mM; i++){
        for(int j = 0; j < mM; j++){
            map[i][j] = -1;
            vis[i][j] = 0;
        }
    }
}
void initV()
{
    for(int i = 0; i < mM; i++){
        for(int j = 0; j < mM; j++){
            vis[i][j] = 0;
            viS[i][j] = 0;
        }
    }
}
void initP()
{
    for(int i = 0; i < mM; i++){
        for(int j = 0; j < mM; j++){
            pat[i][j] = 0;
        }
    }
}

int bfs(_nod* l, _nod* r)
{
    // pre
    _nod2 cur, nex;
    int xb, xe, yb, ye;
    xb = l->x; xe = r->x;
    yb = l->y; ye = r->y;
    // queue
    _nod2 que[qM];
    int fro = -1, rea = -1;
    // init
    cur.x = xb; cur.y = yb; cur.s = 0;
    que[++rea] = cur;
    // init pat
    initP();
    pat[xb][yb] = 1;
    vis[xb][yb] = 1;
    // bfs
    int tmp;
    while(fro < rea){
        tmp = rea;
        while(fro < tmp){
            cur = que[++fro];
            if(cur.x == xe && cur.y == ye){
                return pat[xe][ye];
            }
            for(int i = 0; i < 4; i++){
                nex.x = cur.x + dir[i][0]; nex.y = cur.y + dir[i][1];
                if(nex.x < 0 || nex.x >= n || nex.y < 0 || nex.y >= n) continue; // out of map
                if(map[nex.x][nex.y] == 9) continue;
                if(viS[nex.x][nex.y] != 0) continue;
                pat[nex.x][nex.y] += pat[cur.x][cur.y];
                if(vis[nex.x][nex.y] != 0) continue;
                nex.s = cur.s+1; 
                que[++rea] = nex;
                vis[nex.x][nex.y] = 1;
            }
            viS[cur.x][cur.y] = 1;
        }
    }
    return 0;
}

int main()
{
    // init
    int a;
    cin >> t;
    int cnt = 0;
    while(cnt < t)
    {
        cin >> n >> m;
        // init map & vis
        initMV();
        // pre list for nodes but 0 & 9
        _nod* fir = nullptr, *rear = nullptr, *s = nullptr, *p = nullptr;
        fir = new _nod; fir->next = rear; rear = fir;
        // input
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a; map[i][j] = a;
                if(a >= 1 && a <= 5){
                    s = new _nod; s->val = a; s->x = i; s->y = j; 
                    s->next = nullptr; rear->next = s; rear = s;
                }
            }
        }
        // search nodes l & r
        _nod* l = nullptr, *r = nullptr;
        p = fir->next;
        while(p != nullptr){
            if(p->val == 1){
                l = p; r = l; break;
            }
            p = p->next;
        }
        // scan 1-2, 2-3, ...
        int res = 1;
        for(int i = 2; i <= m; i++){
            l = r;
            // find r
            p = fir->next;
            while (p != nullptr)
            {
                if(p->val == i){
                    r = p; break;
                }
                p = p->next;
            }
            // get res
            initV();
            res *= bfs(l, r);
        }
        // output
        cout <<"#" << ++cnt << " "<< res << endl;
    }
    return 0;
}