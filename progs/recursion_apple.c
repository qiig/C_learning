#include<stdio.h>
/*
    Input:  m in [0,10] int :apple
            n in [0,10] int :dish
    Output: count in [] int :count
    Method: recursion
    Content: divide apples
*/
int getDivi(int m, int n);

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) != EOF)
    {
        printf("%d\n", getDivi(m, n));
    }
    return 0;
}

int getDivi(int m, int n) {
    if (m == 0 || n == 1) {
        return 1;
    } else if (n > m) {
        return getDivi(m, m);
    } else {
        return getDivi(m, n - 1) + getDivi(m - n, n);
    }
}