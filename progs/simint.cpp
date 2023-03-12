#include<iostream>
#include<algorithm>
// 统计不同数字的个数
using namespace std;

int main() {
    int n, num, lenc; // n 个数，每次输入 num，动态数组长度
    int* comp = nullptr;    // 存储比较值
    bool bo;
    while (cin >> n)
    {
        comp = new int[1001];

        lenc = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            bo = true;
            if (i == 0) {
                comp[i] = num;
                lenc++;
            }
            else {
                for (int j = 0; j < lenc; j++) {
                    if (num == comp[j]) {
                        bo = false;
                        break;
                    }
                }
                if (bo) {
                    comp[lenc] = num;
                    lenc++;
                }
            }
        }
        sort(comp,comp+lenc);

        for (int i = 0; i < lenc; i++) {
            cout << comp[i] << endl;
        }     
        delete[] comp;
    }

    return 0;
}