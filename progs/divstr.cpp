#include<iostream>
#include<cstring>
#include<string>

using namespace std;

// 字符串分隔

int main() {
    int m; // m为余数
    char* ch = nullptr;
    string str;
    while (cin >> str)
    {
        string nstr;
        const int len = str.length();
        ch = new char[len + 1];
        strcpy(ch, str.c_str());
        m = len % 8;
        if (len >= 8) {
            for (int i = 0; i < len - m; i++) {
                if (i % 8 == 0 && i != 0) {
                    cout << endl;
                }
                cout << ch[i];
            }
            cout << endl;
            if (m != 0) {
                for (int i = len - m; i < len - m + 8; i++) {
                    if ((i - len + m) >= m) {
                        cout << '0';
                    }
                    else {
                        cout << ch[i];
                    }
                }
                cout << endl;
            }
        }
        else {
            for (int i = 0; i < 8; i++) {
                if (i < len) {
                    cout << ch[i];
                }
                else {
                    cout << '0';
                }
            }
            cout << endl;
        }

        delete[] ch;
    }
    return 0;
}