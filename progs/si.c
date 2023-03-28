#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode
{
    int val;
    struct ListNode* pNext;
} LN;

int main() {
    int n;
    LN* Last = NULL;
    while (scanf("%d", &n))
    {
        LN* Header = (LN*)malloc(sizeof(LN));
        Header->pNext = NULL;
        scanf("%d", Header);
        Last = Header;
        for (int i = 1; i < n; i++) {
            Last->pNext = (LN*)malloc(sizeof(LN));
            scanf("%d", Last->pNext);
            Last = Last->pNext;
        }
        Last->pNext = NULL;

        while (Header)
        {
            printf("%d ", Header->val);
            Last = Header->pNext;
            free(Header);
            Header = Last;
        }
        printf("\n");
    }
    return 0;
}




