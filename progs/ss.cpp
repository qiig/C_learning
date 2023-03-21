#include<iostream>

typedef struct ListNode {
    int m_nkey;
    ListNode* m_pNext;
} LS;

int main() {
    int n;
    while (scanf("%d", &n) != EOF)
    {
        while (n)
        {
            printf("%d ", n & 1);
            n >>= 1;
        }
        printf("\n");
    }
    return 0;
}