#include <iostream>
#include <string>
using namespace std;

string toHexString(int n);
string h = "0123456789ABCDEF";

int main() {

    int n;
    cin >> n;

    string hexStr = toHexString(n);
    cout << hexStr << endl;

    return 0;
}

string toHexString(int n) {
    // write your code here......
    string str = "";
    int x;

    while (n != 0)
    {
        x = n % 16;
        str = h[x] + str;
        n = n / 16;
    }

    if (str == "")
    {
        return "Error";
    }
    else {
        return str;
    }
    
}
