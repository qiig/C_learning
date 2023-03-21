#include <stdio.h>
#include <stdlib.h>
 
typedef struct ListNode
{
    int m_nKey;
    struct ListNode* m_pNext;
} LST ;
 
int main(void)
{
    int n, k, i, j;
    LST *Last;
    while( scanf("%d", &n)!=EOF )
    {
        LST *Header = (LST *)malloc( sizeof(LST) );
        Header->m_pNext = NULL;
        scanf("%d", Header);
        Last = Header;
        for(i=1; i<n; i++){
            Last->m_pNext = (LST *)malloc( sizeof(LST) );
            scanf("%d", Last->m_pNext);
            Last = Last->m_pNext;
        }
        Last->m_pNext = NULL;
         
        scanf("%d", &k);
        if(k>=1 && (j=n-k)>=0){
            for(i=0; i<j; i++)
            {
                Last = Header->m_pNext;
                free(Header);
                Header = Last;
            }
            printf("%d\n", Header->m_nKey);
        }
        else printf("0\n");
        while(Header)
        {
            Last = Header->m_pNext;
            free(Header);
            Header = Last;
        }
    }
    return 0;
}