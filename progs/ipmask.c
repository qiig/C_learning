#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
/*
    识别有效的IP地址和子网掩码
*/
int isMask(int* n);
int* getCount(char* ch, int len);

int main() {
    int cnt[9];
    char ch[35];
    memset(cnt, 0, sizeof(int) * 9);
    while (scanf("%s", ch) != EOF)
    {
        int* g = NULL;
        int len = strlen(ch);
        g = getCount(ch, len);
        if (g == NULL) {
            printf("error: g is nullptr. \n");
            exit(1);
        }
        for (int i = 0; i < 7; i++) {
            cnt[i] += *(g + i);
        }
    }
    for (int i = 0; i < 7; i++) {
        printf("%d ", cnt[i]);
    }
    memset(cnt, 0, sizeof(int) * 9);
    printf("\n");
    return 0;
}

int* getCount(char* ch, int len) {
    int cnt[8]; // 0A 1B 2C 3D 4E 5Error 6PrivateIP
    memset(cnt, 0, sizeof(int) * 8);
    int num = 0, nadr = 0;
    int adr[9] = { 0 };
    int* g = NULL;
    for (int i = 0; i < len; i++) { // 转存IP和掩码
        if (*(ch + i) == '.' || *(ch + i) == '~') {
            if (*(ch + i +1) == '.' || *(ch + i + 1) == '~') {
                cnt[5]++;  // 非法格式
                g = cnt;
                if (g == NULL) {
                    printf("error: g is nullptr.");
                    exit(1);
                }
                return g;
                break;
            }
            adr[nadr++] = num;
            num = 0;
        } else if (i == len - 1) {
            num = num * 10 + *(ch + i) - '0';
            adr[nadr++] = num;
        } else {
            num = num * 10 + *(ch + i) - '0';
        }
    }
    int isIPs = 0;
    for (int i = 3; i >= 0; i--) { // 先判断IP
        if (adr[i] >= 0 && adr[i] <= 255) {
            isIPs = 1;
        } else {
            isIPs = 0;
            break;
        }
    }
    int isIP = 0;
    if (isIPs) {
        if (adr[0] >= 1 && adr[0] <= 126) {
            isIP = 1;
            cnt[0]++; // if IP is not illegal and belongs to A, A++
            if (adr[0] == 10) {
                cnt[6]++;
            }
        } else if (adr[0] >= 128 && adr[0] <= 191) {
            isIP = 1;
            cnt[1]++;
            if (adr[0] == 172 && adr[1] >= 16 && adr[1] <= 31) {
                cnt[6]++;
            }
        } else if (adr[0] >= 192 && adr[0] <= 223) {
            isIP = 1;
            cnt[2]++;
            if (adr[0] == 192 && adr[1] == 168) {
                cnt[6]++;
            }
        } else if (adr[0] >= 224 && adr[0] <= 239) {
            isIP = 1;
            cnt[3]++;
        } else if (adr[0] >= 240 && adr[0] <= 255) {
            isIP = 1;
            cnt[4]++;
        }
    } else {
        cnt[5]++;
    }
    if (isMask(adr) == 0) {
        if (isIP) { // 如果IP正确 但掩码错误 cnt++ ‘避免重复计数’
            cnt[5]++;
        }
        if (adr[0] >= 1 && adr[0] <= 126) {
            cnt[0]--; // if IP is illegal and belongs to A, A++
            if (adr[0] == 10) {
                cnt[6]--;
            }
        } else if (adr[0] >= 128 && adr[0] <= 191) {
            cnt[1]--;
            if (adr[0] == 172 && adr[1] >= 16 && adr[1] <= 31) {
                cnt[6]--;
            }
        } else if (adr[0] >= 192 && adr[0] <= 223) {
            cnt[2]--;
            if (adr[0] == 192 && adr[1] == 168) {
                cnt[6]--;
            }
        } else if (adr[0] >= 224 && adr[0] <= 239) {
            cnt[3]--;
        } else if (adr[0] >= 240 && adr[0] <= 255) {
            cnt[4]--;
        }
    }
    g = cnt;
    if (g == NULL) {
        printf("error: g is nullptr.");
        exit(1);
    }
    return g;
}

int isMask(int* n) {
    int a, b;
    int c[32], e[32];
    memset(e, 0, sizeof(int) * 32);
    for (int i = 7; i >= 4; i--) {
        a = *(n + i);
        b = 0;
        while (a != 0)
        {
            e[(7 - i) * 8 + b] = a % 2;
            b++;
            a /= 2;
        }
    }
    for (int i = 0; i < 32; i++) {
        c[i] = e[31 - i];
    }
    int isZ = 0, bb, cnt1;
    b = 0;
    cnt1 = 0;
    for (int i = 0; i < 32; i++) {     // 判断
        if (c[i] == 1 && isZ == 0) {
            b++; cnt1++;
        } else if (c[i] == 1 && isZ == 1) {
            b--; cnt1++;
        } else {
            cnt1--;
            if (isZ == 0) {
                bb = b;
            }
            isZ = 1;
        }
    }
    if (cnt1 == 32 || cnt1 == -32) {
        return 0;
    }
    if (b < bb) {
        return 0;
    } 
    return 1;
}