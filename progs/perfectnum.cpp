#include<stdio.h>

int getCnt(int n);

int main() {
    int n;
    while (scanf("%d", &n) == 1)
    {
        printf("%d\n", getCnt(n));
    }
    return 0;
}

int getCnt(int n) {
    int m, sum = 0, num = 0;
    // n == 6 || n == 28 true
    if (n < 6) {
        return 0;
    } else if (n < 28) {
        return 1;
    } else if (n < 31) {
        return 2;
    } else {
        sum = 2;
    }

    for (int i = 30; i <= n; i++) {
        m = i;
        num = 0;
        int j = 1;
        while (m / j >= j && j <= m / 2) {
            if (m % j == 0) {
                num += m / j + j;
            } 
            j++;
        }
        num -= i;
        if (i == num) {
            sum++;
        }
    }
    return sum;
}