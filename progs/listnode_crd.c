#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode 
{
    int value;
    struct ListNode* pNext;
} LN;

int main() {
    int n, k;
    LN* Last = NULL;
    while (scanf("%d", &n) != EOF)
    {
        LN* Header = (LN*)malloc(sizeof(LN));
        Header->pNext = NULL;
        scanf("%d", Header);
        Last = Header;
        for (int i = 1; i < n; i++) {
            Last->pNext = (LN*)malloc(sizeof(LN*));
            scanf("%d", Last->pNext);
            Last = Last->pNext;
        }
        Last->pNext = NULL;
        scanf("%d", &k);
        int j = n - k;
        if (k >= 1 && j >= 0) {
            for (int i = 0; i < j; i++) {
                Last = Header->pNext;
                free(Header);
                Header = Last;
            }
            printf("%d\n", Header->value);
        } else {
            printf("0\n");
        }
        while (Header)
        {
            Last = Header->pNext;
            free(Header);
            Header = Last;
        }
    }
    return 0;
}