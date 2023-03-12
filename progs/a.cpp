#include<iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n)
    {
        if (n == 0) {
            break;
        }
        int* p = new int;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        cout <<"sizeof --- "<< sizeof(*p) << endl;
        cout <<"msize  --- "<< _msize(p) << endl;

        delete[] p;
    }

    return 0;
}