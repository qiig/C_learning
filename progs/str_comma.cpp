#include <iostream>
#include<string>
#include<vector>
using namespace std;

// 字符串以 ， 分割，冒泡1/选择0 排序后输出；

void sortstr(vector<string>& vec, int len, int ch) ;

int main() {
    string s;
    vector<string> str;
    while (cin >> s) { 
        int lens = s.length();
        string ss = "";
        for (int i = 0; i < lens; i++) {
            if (s[i] != ',') {
                ss += s[i];
            } else {
                str.push_back(ss);
                ss = "";
            }
        }
        str.push_back(ss);
        ss = "";
        if (cin.get() == '\n') {
            int len = str.size();
            sortstr(str, len, 1);
            for (int i = 0; i < len; i++) {
                if (i == len - 1) {
                    cout << str[i];
                } else {
                cout << str[i] << ',';
                }
            }
            cout << endl;
            str.clear();
        }
    }
    return 0;
}

void sortstr(vector<string>& vec, int len, int ch) {
    int index;
    bool op = false;
    string s;
    if (ch == 1) {
        for (int i = 0; i < len - 1; i++) {
            s = vec[i];
            op = false;
            for (int j = i + 1; j < len; j++) {
                if (s > vec[j]) {
                    index = j;
                    s = vec[j];
                    op = true;
                }
            }
            if (op) {
                vec[index] = vec[i];
                vec[i] = s;
            }
        }
    } else {
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (vec[i] > vec[j]) {
                    s = vec[i];
                    vec[i] = vec[j];
                    vec[j] = s;
                }
            }
        }
    }

}