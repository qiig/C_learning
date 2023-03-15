#include<iostream>
#include<string>
#include<vector>
#include<iterator>

using namespace std;

int main() {
    int n;
    string str;
    while (cin >> n) {
        //cin >> n;
        vector<string> vec;
        for (int i = 0; i < n; i++) {
            cin >> str;
            vec.push_back(str);
            cout << "vec[i]   ---   " << vec[i] << endl;
        }
        // sort
        string chg;
        string chc;
        int index = 1;
        bool op = false;
        for (int i = 0; i < vec.size() - 1; i++) {
            op = false;
            chg = vec[i];
            for (int j = i + 1; j < vec.size(); j++) {
                chc = vec[j];
                if (chg > chc) {
                    index = j;
                    chg = vec[j];
                    op = true;
                }
                cout << "  Name    |    Value" << endl;
                cout << "     i   ---   " << i << endl;
                cout << "     j   ---   " << j << endl;
                cout << "   chg   ---   " << chg << endl;
                cout << "    op   ---   " << op << endl;
                cout << " index   ---   " << index << endl;
                cout << "  End i --- " << endl;

            }
            if (op) {
                vec[index] = vec[i];
                vec[i] = chg;
            }
        }
        // print
        cout << " ---  Result  --- " << endl;
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << endl;
        }

        cout << "--------- end ---------" << endl;
        vec.clear();
        cout << "--------- new ---------" << endl;
    }
    return 0;
}