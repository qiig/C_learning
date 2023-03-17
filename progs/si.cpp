#include<iostream>
#include<vector>
using namespace std;
int main() {
    int n;
    vector<int> vec;
    while (cin >> n && n > 0)
    {
        int a;
        for (int i = 0; i < n; i++) {
            cin >> a;
            vec.push_back(a);
        }
        int len = vec.size();
        for (int i = 0; i < len; i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
        vec.clear();
    }

    return 0;
}