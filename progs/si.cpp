#include<iostream>
#include<vector>

using namespace std;

void getSort(vector<string>& na, vector<int>& gr, int n, int isA);

int main() {
    int n, gr, isA;
    string na;
    vector<string> name;
    vector<int> grad;
    while (cin >> n >> isA) {
        for (int i = 0; i < n; i++) {
            cin >> na >> gr;
            name.push_back(na);
            grad.push_back(gr);
        }
        getSort(name, grad, n, isA);
        for (int i = 0; i < n; i++) {
            cout << name[i] << " " << grad[i] << endl;
        }
    }
    return 0;
}

void getSort(vector<string>& na, vector<int>& gr, int n, int isA) {
    vector<string> name;
    vector<int> grad;
    for (int i = 0; i < n; i++) {
        name.push_back(na[i]);
        grad.push_back(gr[i]);
    }
    if (isA) { // 1: 从低到高
        int index, cmp;
        string str;
        for (int i = 0; i < n - 1; i++) {
            index = i;
            cmp = gr[i];
            for (int j = i + 1; j < n; j++) {
                if (cmp > gr[j]) {
                    index = j;
                    cmp = gr[j];
                }
            }
            if (index != i) {
                gr[index] = gr[i];
                gr[i] = cmp;
                str = na[index];
                na[index] = na[i];
                na[i] = str; 
            }
        }
    } else {
        int index, cmp;
        string str;
        for (int i = 0; i < n - 1; i++) {
            index = i;
            cmp = gr[i];
            for (int j = i + 1; j < n; j++) {
                if (cmp < gr[j]) {
                    index = j;
                    cmp = gr[j];
                }
            }
            if (index != i) {
                gr[index] = gr[i];
                gr[i] = cmp;
                str = na[index];
                na[index] = na[i];
                na[i] = str; 
            }
        }
    }
    // 
    
}