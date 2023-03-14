#include <stdio.h>
#include <string.h>
    
int main(void)
{
int n,m=0;
    scanf("%d",&n);
    int a[10]={0};
    while(n)
    {
        if(a[n%10] == 0)
        {
            a[n%10]++;
            m = m*10 + n%10;
        }
        n /= 10;
    }
    printf("%d\n",m);
return 0;
}