#include <stdio.h>
// 质数因子
int main(void){
    int n;
    while(scanf("%d", &n) == 1){
        int tmp = n;
        for(int i = 2; i * i <= tmp && n >= i; i++){
            while(n % i == 0){
                printf("%d ", i);
                n /= i;
            }
        }
        if(n - 1) printf("%d ", n);
        putchar('\n');
    }
    return 0;
}