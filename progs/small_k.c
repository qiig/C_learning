#include<stdio.h>
#include<stdlib.h>
/* 
    Input: n in [1, 1000]     n groups data
          k <= n
          val in [1, 10000]
    Output: k integer numbers k1 < k2 < k3 < ...
    Method: bubble sort
*/
int* getSort(int* an, int n); // n = len. of an

int main() {
    int n, k;
    int an[1001] = { 0 };
    while (scanf("%d %d", &n, &k) != EOF)
    {
        for (int i = 0; i < n; i++) {
            scanf("%d", &an[i]);
        }
        int* a = getSort(an, n);
        for (int i = 0; i < k; i++) {
            printf("%d ", *(a + i));
        }
        printf("\n");
    }
    
}

int* getSort(int* an, int n) {
    int a, index;
    int bn[1001] = { 0 };
    for (int i = 0; i < n; i++) {
        bn[i] = *(an + i);
    }
    for (int i = 0; i < n - 1; i++){
        index = i;
        a = bn[i];
        for (int j = i + 1; j < n; j++) {
            if (a > bn[j]) {
                index = j;
                a = bn[j];
            }
        }
        if (index != i) {
            bn[index] = bn[i];
            bn[i] = a;
        }
    }
    int* b = bn;
    // isNullPtr ?
    if (b == NULL) {
        printf("error: tmp is nullptr.\n");
        exit(1);
    }
    //
    return b;
}