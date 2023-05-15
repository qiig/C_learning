#include<iostream>
using namespace std;

// global
const int nM = 101;
const int mM = 21;
int map[nM][mM];
int mam[nM][mM];
int t, N, M, K, mMax;

// functions
int getFac();
void chg(int col);
void sol(int cnt);
void ini();
int solu1();

// main
int main()
{
    int res, tt = 0;
    cin >> t;
    tt = t;
    while(t--)
    {
        cin >> N >> M >> K;
        // get map
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[i][j];
                mam[i][j] = map[i][j];
            }
        }
        // solve
        res = 0;
        res = solu1();
        
        // output
        cout << "#" << tt-t << " " << res << endl;
    }
}

int getFac()
{
    int sum, cnt = 0;
    for(int i = 0; i < N; i++){
        sum = 0;
        for(int j = 0; j < M; j++){
            sum += map[i][j];
        }
        if(sum == M) cnt++;
    }
    return cnt;
}

void chg(int col)
{
    for(int i = 0; i < N; i++){
        if(map[i][col] == 0){
            map[i][col] = 1;
        } else {
            map[i][col] = 0;
        }
    }
}

void sol(int cnt)
{
    if(cnt == K){
        int fac = getFac();
        if(fac >= mMax) mMax = fac;
        ini();
        return;
    }
    for(int i = 0; i < M; i++){
        chg(i);
        cnt++;
        sol(cnt);
        cnt--;
    }
}

void ini()
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = mam[i][j];
        }
    }
}

int solu1()
{
    // pre
    int res = 0;
    mMax = 0;
    // solve
    sol(0);
    // res
    res = mMax;
    // return
    return res;
}

// test cases
/*
3
3 3 2
0 1 1 
0 0 0
1 1 0
3 3 1
1 1 0
1 0 0
1 1 0
3 4 3
1 0 1 0
0 0 1 1
0 0 0 1



*/