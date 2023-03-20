#include<stdio.h>
#include<string.h>
/*
    Input: char_array
    Output: char
    Method: find index
    Content: find the first letter which is inputted only once.
*/
int main() {
    char str[1001];
    while (scanf("%s", str) != EOF)
    {
        int pos = 0, isN = 1;
        int len = strlen(str);
        int alp[26] = { 0 };
        char s[27];
        for (int i = 0; i < len; i++) {
            if (alp[str[i] - 'a'] == 0) {
                s[pos++] = str[i];
            }
            alp[str[i] - 'a']++;
        }
        for (int i = 0; i < pos; i++) {
            if (alp[*(s + i) - 'a'] == 1) {
                printf("%c\n", s[i]);
                isN = 0;
                break;
            }
        }
        if (isN) {
            printf("-1\n");
        }
    }
    return 0;
}