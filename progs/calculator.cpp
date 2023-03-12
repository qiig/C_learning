#include <iostream>
#include <cstring>
using namespace std;
// 简易计算器，以整行字符串形式输入
class Calculator
{
private:
    char op, s[100];
    int num1, num2, slen;
public:
    Calculator(char* str, int sl);
    ~Calculator();
    void getoperator();
    void getnum();
    void calresult();
};

Calculator::Calculator(char* str, int sl)
{
    slen = sl;
    for (int i = 0; i < slen; i++){
        s[i] = *(str + i);
    }
}

Calculator::~Calculator()
{
}

void Calculator::getoperator() {
    if (s[0] == 'a' && s[1] == 'd' && s[2] == 'd' && s[3] == ' ') 
    {
        op = '+';
    }
    else if (s[0] == 's' && s[1] == 'u' && s[2] == 'b' && s[3] == ' ')
    {
        op = '-';
    }
    else if (s[0] == 'm' && s[1] == 'u' && s[2] == 'l' && s[3] == ' ')
    {
        op = '*';
    }
    else if (s[0] == 'd' && s[1] == 'i' && s[2] == 'v' && s[3] == ' ')
    {
        op = '/';
    }
    else
    {
        cout << "illegal input !" << endl;
    }
}

void Calculator::getnum(){
    num1 = 0;
    num2 = 1;
    int count = 0;
    char ss[20];
    int numlen = 0;

    memset(ss,' ',20);
    for (int i = 4; count == 0; i++)
    {
        if (s[i] == ' ')
        {
            num1 = atoi(ss);
            numlen++;
            count++;
        }
        else
        {
            ss[i - 4] = s[i];
            numlen++;
        }
    }

    #if 0
        cout << "num1 = " << num1 << endl;
    #endif

    memset(ss,' ',20);
    for (int i = 4 + numlen; count == 1; i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {  
            num2 = atoi(ss);
            count++;
        }
        else
        {
            ss[i - 4 - numlen] = s[i];
        }        
    }
    
    #if 1
        cout << "num2 = " << num2 << endl;
    #endif

}

void Calculator::calresult() {

    #if 0
        cout << "op = " << op << endl;
    #endif

    switch (op) {
        // +
        case '+':
            cout << num1 + num2 << endl; break;
        // -
        case '-':
            cout << num1 - num2 << endl; break;
        // *
        case '*':
            cout << num1 * num2 << endl; break;
        // /
        case '/':
            if (num2 == 0) {
                cout <<"Error"<<endl;
                break;
            }
            else {
                cout << num1 / num2 << endl; break;
            }
    }
}

int main() {

    char str[100] = { 0 };

    while (cin.getline(str, sizeof(str)))
    {
        int l = strlen(str);
        Calculator strr(str, l);

        strr.getoperator();
        strr.getnum();
        strr.calresult();
    }
    
    return 0;
}