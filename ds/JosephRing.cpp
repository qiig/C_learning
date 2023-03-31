#include "cir_singlyLinkList.h"

int main(){
    int n, m;
    int a[101] = {0};
    while (cin >> n >> m && n > 0)
    {
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        cir_singlyLinkList<int> J{a, n};
        int num = n, beg = 1;
        for (int i = 0; i < 4; i++) {
            n = J.getLen();
            beg += m - 1;
            if (beg > n) beg -= (beg / n) * n;
            try {
                cout << J.getVal(beg) << " ";
                J.Delete(beg);
            } catch (const char *s) {cout << s << endl;}
        }
        try {
            cout << J.getVal(1) << endl;
            J.Delete(beg);
        } catch (const char* s) {cout << s << endl;}
    }
    return 0;
}