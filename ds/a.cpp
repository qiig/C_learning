#include<iostream>
using namespace std;

const int mM = 9;
int map[mM][mM];
int vis[mM][mM];
int ptn[mM][mM];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

void init()
{
    for(int i = 0; i < mM; i++){
        for(int j = 0; j < mM; j++){
            map[i][j] = -1;
            vis[i][j] = 0;
        }
    }
}

// data structure
#if 1
// Queue
const int qM = 1000;  // max length of queue
template<typename T>
class _queue
{
public:
    _queue();
    ~_queue() {};
    void push(T a);
    T top();
    T pop();
    int empty();
private:
    T data[qM];
    int front, rear;
};

template<typename T>
_queue<T>::_queue()
{
    front = qM - 1;
    rear = qM - 1;
}

template<typename T>
void _queue<T>::push(T a)
{
    // check queue
    if ((rear + 1) % qM == front) cout << "overflow " << endl;
    rear = (rear + 1) % qM;
    data[rear] = a;
}

template<typename T>
T _queue<T>::pop()
{
    // check
    if (rear == front) cout <<  "under flow " << endl;
    front = (front + 1) % qM;
    return data[front];
}

template<typename T>
T _queue<T>::top()
{
    if (rear == front) cout << "under flow " << endl;
    return data[(front + 1) % qM];
}

template<typename T>
int _queue<T>::empty()
{
    if (rear == front) return 1;
    return 0;
}

#endif

typedef struct Nod
{
    int x, y, val;
    Nod* next;
}Nod;

typedef struct Node
{
    int x, y;
    int s, p;
}Node;


int BFS(int n, int m, Nod* l, Nod* r)
{
    _queue<Node> q;
    Node cur, nex;
    // begin & end index
    int xb, yb, xe, ye;
    xb = l->x; yb = l->y; xe = r->x; ye = r->y;
    //
    cur.x = xb; cur.y = yb; cur.s = 0; cur.p = 1;
    ptn[xb][yb] = 1;
    q.push(cur);
    int len = 1, slen = 1;
    int level = 0;
    while(!q.empty()){
        len = slen; slen = 0;
        while(len--)
        {
            // cout << q.length() << " - " << len << ";  ";
            if(q.empty()){
                cout << "empty " << endl;
                break;
            }

            cur = q.pop();
            if(cur.x == xe && cur.y == ye){
                return ptn[xe][ye];
            }
            for(int i = 0; i < 4; i++){
                xb = cur.x + dir[i][0]; yb = cur.y + dir[i][1];
                if(map[xb][yb] == -1 || map[xb][yb] == 9) continue; // over map or is wall
                if(vis[xb][yb]) continue;   // visited
                nex.x = xb; nex.y = yb; nex.s++;
                ptn[xb][yb] += ptn[cur.x][cur.y];
                nex.p = ptn[xb][yb];
                cout << " No. " <<level << " ' " << len << " ' "<< i << endl;
                q.push(nex); slen++;
            }
        }
        level++;
    }
    return 0;
}

int main()
{
    int t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        // init map & vis
        init();
        // pre List for Nodes but 0
        Nod* fir = nullptr, * rear = nullptr;
        Nod* s = nullptr, * p = nullptr;
        fir = new Nod; fir->next = nullptr;
        rear = fir;     // with first node
        // Input map
        int nn;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> nn;
                map[i][j] = nn;
                if(nn >= 1 && nn <= 5){
                    s = new Nod; s->x = i; s->y = j; s->val = nn; s->next = nullptr;
                    rear->next = s; rear = s;
                }
            }
        }
        // scan all nodes
        // pre
        int res = 1;
        Nod* l = nullptr, * r = nullptr;
        p = fir->next;
        while (p != nullptr)
        {
            if(p->val == 1) {
                l = p;
                break;
            }
            p = p->next;
        }
        r = l;
        // 1-2 2-3 ...
        for(int i = 2; i <= m; i++){
            l = r;
            p = fir->next;
            while(p!=nullptr){
                if(p->val == i){
                    r = p; break;
                }
                p = p->next;
            }
            // init ptn
            for(int j = 0; j < mM; j++){
                for(int k = 0; k < mM; k++){
                    ptn[j][k] = 0;
                }
            }
            // bfs
            // cout << l->val << " --> " << r->val << endl;
            res *= BFS(n, m, l, r);
        }
        cout << res << endl;

        // delete
        p = fir;
        while(p != nullptr)
        {
            fir = fir->next;
            delete p;
            p = fir;
        }
    }

    return 0;
}


/*
1
5 4
1 0 0 0 0
0 0 0 0 0
0 2 0 4 0
9 0 0 9 0
0 0 0 3 0

5
5 4
1 0 0 0 0
0 0 0 0 0
0 2 0 4 0
9 0 0 9 0
0 0 0 3 0
3 3
1 0 0
0 2 9
0 9 3
6 5
0 0 0 0 0 9
0 0 0 0 9 0
0 0 0 5 0 0
2 9 9 0 0 9
3 0 0 0 0 0
1 0 0 0 0 4
7 2
0 0 0 0 0 0 0
0 9 9 9 9 9 0
0 0 0 0 0 9 0
0 9 9 0 0 9 0
0 9 0 0 2 9 0
0 9 9 9 9 9 0
0 0 0 0 0 0 1
7 5
1 3 0 0 0 0 0
9 0 0 0 0 0 0
0 0 5 0 0 0 0
0 0 0 9 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 4
0 0 0 0 0 0 2

*/