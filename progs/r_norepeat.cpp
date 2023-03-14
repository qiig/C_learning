#include<iostream>
#include<cstring>
#include<string>

using namespace std;
// 提取不重复的数
// 输入一个整形数，从右往左输出不重复的数
// 输入 [1,10^8]

int main() {
    string str;
    while (cin >> str)
    {
        char *ch = new char[10];
        const int len = str.length();
        strcpy(ch, str.c_str());
        char *chs = new char[10];

        chs[0] = ch[len - 1];
        int count = 1;
        bool ju = true;
        for (int i = len - 1; i >= 0; i--) {
            ju = true;
            for (int j = 0; j < count; j++)
            {
                if (*(ch + i) == *(chs + j)) {
                    ju = false;
                // cout << "------new------"<<endl;
                // cout << "  i ---  "<<i <<endl;
                // cout << "  j ---  "<<j <<endl;
                // cout << "cot ---  "<<count<<endl;
                // cout << " ch ---  "<<*(ch + i) <<endl;
                // cout << "chs ---  "<<*(chs + j) <<endl;
                // cout << "------end------"<<endl;
                    break;
                } 
            }
            if (ju) {
                *(chs + count) = *(ch + i);
                count++;
            }
        }
        for (int i = 0; i < count; i++)
        {
            cout << *(chs + i);
        }
        cout << endl;
        
        delete[] chs;
        delete[] ch;

    }

    return 0;
}

