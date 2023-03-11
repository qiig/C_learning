#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

int main() {

    char str[100] = { 0 };
    cin.getline(str, sizeof(str));
    // write your code here......
    int slen = strlen(str);

    int count = 0;
    char opei;
    int num1 = 0, num2 = 1, len_num1 = 0;
    char num[11] = { 0 };


    for (int i = 0; i < slen; i++){
        if (str[i] == '\040'){
            count++;
            cout <<i<<" --- "<<count<<endl;
        }
        // check operator
        if (count == 0 && i == 0) {
            // add == 0
            if (str[0] == 'a' && str[1] == 'd' && str[2] == 'd') {
                opei = '+';
            }
            // sub == 1
            else if (str[0] == 's' && str[1] == 'u' && str[2] == 'b') {
                opei = '-';
            }
            // mul == 2
            else if (str[0] == 'm' && str[1] == 'u' && str[2] == 'l') {
                opei = '*';
            }
            // div == 3
            else if (str[0] == 'd' && str[1] == 'i' && str[2] == 'v') {
                opei = '/';
            }
            // ILLEGAL INPUT
            else {
                cout <<"ILLEGAL INPUT !"<< endl;
                break;
            }

            i ++; // skip 2 loops
        }

      //  cout<<"ope --- "<<opei<<endl;
      //  cout<<endl;
        // check num1 & num2
        if (count == 1) {
            num[i] = str[i];
            len_num1++;
            num1 = atoi(num);
        }
        else if (count == 2) {
                //cout <<endl;
                //cout <<"count == 2 :::"<<i<<endl;

            num[i - len_num1 - 1] = str[i];
        }
        else if (i == slen -1) {
            num2 = atoi(num);
        }

    }

    #if 0
        cout << num1 <<";"<< num2 << endl;
    #endif // 1

    // calculator
    switch (opei) {
        // +
        case '+':
            cout << num1 + num2; break;
        // -
        case '-':
            cout << num1 - num2; break;
        // *
        case '*':
            cout << num1 * num2; break;
        // /
        case '/':
            if (num2 == 0) {
                cout <<"Error";
                break;
            }
            else {
                cout << num1 / num2;
            }
    }

    return 0;
}
