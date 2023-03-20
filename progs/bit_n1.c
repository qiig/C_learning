#include<stdio.h>
// 位运算
int main() 
{
    int n;
    while (scanf("%d", &n) != EOF) 
    {
        int count = 0;
        while (n) 
        {
            n = n & (n - 1); //求一个二进制数有几个1，用n与n-1作&；
            n = n & (n << 1); //求一个二进制数有几个连续的1，用n与n<<1作&
            count++;
        }
        printf("%d\n", count);
    }
    return 0;
}