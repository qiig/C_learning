/*
    find & output a cycle in the directed-cycle-graph

    Note: indices of each vectex must start from 1
    Note: the amount of nodes should be less than or equal to 20
    Note: the amount of edges should be less than or equal to 100
*/
#include<iostream>
using namespace std;

// global

const int nN = 20;
const int eN = 100;

bool vis[nN], rec[nN];
int A[eN], B[eN];
int t, T, N, M;
int ans[nN];
int lena = 0;

// functions
bool dfs(int v);

// main
int main() 
{
    cin >> t; T = t;
    while(t--)
    {
        // input
        cin >> N >> M;
        int a = 0, b = 0;
        for(int i = 0; i < M; i++) {
            cin >> a >> b;
            A[i] = a-1;
            B[i] = b-1;
        }

        // init
        for(int i = 0; i < N; i++) {
            vis[i] = false;
            rec[i] = false;
        }

        // solve
        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                vis[i] = true;
                rec[i] = true;
                if(dfs(i)) break;

                rec[i] = false;
            }
        }

        // output
        lena = -1;
        for(int i = 0; i < N; i++) {
            if(rec[i]) {
                ans[++lena] = i+1;
            }
        }

        cout << endl << "#" << T-t << " ";
        if(lena==-1) cout << -1 << " ";
        else {
            for(int i = 0; i <= lena; i++) {
                cout << ans[i] << " ";
            }
        }
    }

    return 0;
}

//
// defination
//
// dfs
bool dfs(int v) 
{
    for(int i = 0; i < M; i++) {
        if(A[i]==v) {

            if(rec[B[i]]) return true;
            
            if(!vis[B[i]] && !rec[B[i]]) {
                vis[B[i]] = true;
                rec[B[i]] = true;
                if(dfs(B[i])) return true;
                rec[B[i]] = false;
            }
        }
    }

    return false;
}

// test cases
/*
1
5 5
1 2
3 2
3 4
5 3
4 5

*/