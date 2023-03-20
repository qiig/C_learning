#include<stdio.h>
#include<string.h>
#define Ms 10010
// higher precision add (integer)
int main() {
    char ch1[Ms], ch2[Ms];
    while (scanf("%s %s", ch1, ch2) != EOF)
    {
        int num1[Ms] = { 0 };
        int num2[Ms] = { 0 };
        int len1 = strlen(ch1);
        int len2 = strlen(ch2);
        for (int i = 0; i < len1; i++) {
            num1[i] = ch1[len1 - i - 1] - '0';
        } 
        for (int i = 0; i < len2; i++) {
            num2[i] = ch2[len2 - i - 1] - '0';
        }
        int len = len1 > len2 ? len1 : len2;
        int num[Ms] = { 0 };
        int sum, isUp = 0;
        for (int i = 0; i <= len; i++) {
            sum = num1[i] + num2[i] + isUp;
            if (sum < 10) {// isUp == 0
                num[i] = sum;
                isUp = 0;
            } else {
                num[i] = sum % 10;
                isUp = 1;
            }
        }
        // print
        if (num[len]) { // the first == 0
            printf("%d", num[len]);
        }
        for (int i = 0; i < len; i++) {
            printf("%d", num[len - i - 1]);
        }
        printf("\n");
    }
    return 0;
}
