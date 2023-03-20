#include<stdio.h>

int f(int n);

int main() 
{
    int n;
    while (scanf("%d", &n) != EOF) 
    {
        printf("%d\n", f(n));
    }
    return 0;
}

int f(int n) {
    if (n % 2 == 0) {
        return 2 * n + 3 * n * (n - 1) / 2;
    } else {
        return 3 * n - 1 + f(n - 1);
    }
}