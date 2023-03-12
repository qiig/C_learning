#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
    char s;
    string si;
    int count = 0;

    char* str = new char;
    
    getline(cin, si);

    const int len = si.length();
    strcpy(str, si.c_str());

    cin >> s; // input s comparing with str
    s = tolower(s);
    for (int i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
        if(str[i] == s) {count++;}
    }
    cout << count << endl;

    delete[] str;

    return 0;
}