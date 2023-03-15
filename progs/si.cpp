#include <stdio.h>
    
int main()
{
    char ch;
    int a[128] = { 0 };
    int count = 0;
    while (scanf("%c", &ch) == 1 && ch != '\n')
    {
        for (int i = 0; i <128; i++)
        {
            if (a[i] == 0 && ch == i)
            {
                a[i]++;
                count++;
                break;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}