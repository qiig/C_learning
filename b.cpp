/*
    Dynamic Programming
    
    1. Recursion
    2. DP: bottom-up <> tabulation
    3. DP: top-down  <> memoization
*/

#include<iostream>
using namespace std;

// global
const int fM = 100;
int fibon[fM] = {0, 1};

// functions
int solu1(int n);
int solu2(int n);
int solu3(int n);
int Fibonacci(int n);
int FiboNRe(int n);

// main
int main()
{
    int t, T, n, res;
    cin >> t; T = t;
    while(t--)
    {
        // input
        cin >> n;

        // res
        res = 0;    // default
        //res = solu1(n);
        int res2 = 0;
        res2 = solu2(n);
        int res3 = 0;
        res3 = solu3(n);
        // output
        cout << "#" << T-t << " " << res << " " << res2 << " " << res3 <<  endl;
    }
    return 0;
}

// func. im.
int solu1(int n)
{
    // pre
    int res;
    // solve
    res = Fibonacci(n);
    // return
    return res;
}

int Fibonacci(int n)
{
    if(n == 1) return 0;
    if(n == 2) return 1;
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int solu2(int n)
{
    // pre
    int i = 2;
    int fibo[fM] = {0, 1};
    // solve
    while(n > 1 && i <= n)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
        i++;
    }
    // return
    return fibo[n-1];
}

int solu3(int n)
{
    // pre
    for(int i = 0; i < fM; i++){
        fibon[i] = 0;
    }
    // solve
    int res = 0;
    res = FiboNRe(n);
    // return 
    return res;
}

int FiboNRe(int n)
{
    // end
    if(n == 1) return 0;
    if(n == 2) return 1;
    // check
    if(fibon[n] != 0) return fibon[n];
    //
    return fibon[n] = FiboNRe(n-1) + FiboNRe(n-2);
}