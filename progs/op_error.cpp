#include<iostream>
#include<string>
using namespace std;

class Expression {
    public:
        Expression(string strr);
        ~Expression();
        int Compute();
    private:
        string str;
        int Compare(char str1, char str2);
};
Expression::Expression(string strr) { // Init Expression
    this->str = strr + "#";
}
Expression::~Expression() {
}
int Expression::Compute() {
    int Nu[1001] = { 0 };
    char Op[1001], op;
    Op[0] = '#';
    bool n = false, m = false;
    int top1 = -1, top2 = 0;  // Init 2 Stacks
    int num = 0, x, y, z;
    int len = str.length();
    //cout << " len --- " << len << endl;
    for (int i = 0; str[i] != '\0'; ) {
        if (str[i] <= '9' && str[i] >= '0') {
            num = num * 10 + str[i] - '0';
            //cout << " i --- " << i << "  str[i]  ---  "<< str[i] << "  :num ---  "<< num << endl;
            n = false; i++;
        } else {
            if (!n) {
                if (m) {num = - num; m = false;}
                Nu[++top1] = num;
                //cout << "top1 --- " << top1 << "   :num --- " << Nu[top1] << " num --- " << num << endl;
                num = 0;
                n = true;
            }
            if (Compare(str[i], Op[top2]) == 1) { // New operator has priority
                Op[++top2] = str[i++];
                //cout << " top2 -- " << top2 << " Op[top2] -- " << Op[top2] << endl;
            } else if (Compare(str[i], Op[top2]) == 0) { // Op.pop()
                top2--; i++;
                //cout << " top2 -- " << top2 << "Op.pop()" << endl;
            } else if (Compare(str[i], Op[top2]) == 2) { // Nu[top1] may be negative num
                if (str[i - 1] == '+' || str[i - 1] == '-' || str[i - 1] == '*' || str[i - 1] == '/') {
                    m = true; // str[i + 1] < 0
                    i++;
                } else {
                    Op[++top2] = str[i++];
                }
            } else if (Compare(str[i], Op[top2]) == 3) { // Nu[top1] may be negative num
                if (top1 == -1) {
                    m = true; // str[i + 1] < 0
                    i++;
                } else {
                    Op[++top2] = str[i++];
                }
            } else { // Stack Top has priority
                y = Nu[top1--];
                x = Nu[top1--];
                op = Op[top2--];
                switch (op)
                {
                case '+':
                    z = x + y; break;
                case '-':
                    z = x - y; break;
                case '*':
                    z = x * y; break;
                case '/':
                    if (y == 0) {
                        cout << "Error: divided by Zero." << endl; break;
                    } else {
                        z = x / y; break;
                    }
                
                default:
                    break;
                }
                Nu[++top1] = z;
                cout << Nu[top1] << "  z  --  " << z << " i++ " << i << endl;
            }
        }
    }
    return Nu[top1];
}
int Expression::Compare(char str1, char str2) {
    switch (str1)
    {
    case '+':
        if (str2 == '(' || str2 == '[' || str2 == '{' || str2 == '#') {
            return 1;
        } else {
            return -1;
        }
        break;
    case '-':
        if (str2 == '(' || str2 == '[' || str2 == '{') {
            return 1;
        } else if (str2 == '#') {
            return 3;
        } else if (str2 == '+' || str2 == '-' || str2 == '*' || str2 == '/') {
            return 2;
        } else {
            return -1;
        }
        break;
    case '*':
    case '/':
        if (str2 == '*' || str2 == '/') {
            return -1;
        } else {
            return 1;
        }
        break;
    case '(':
    case '[':
    case '{':
        return 1; break;
    case ')':
    case ']':
    case '}':
        if (str2 == '(' || str2 == '[' || str2 == '{') {
            return 0;
        } else {
            return -1;
        }
        break;
    case '#':
        if (str2 == '#') {
            return 0;
        } else {
            return -1;
        }
        break;

    default:
        break;
    }
    return 0;
}

int main() {
    string str;
    while (cin >> str)
    {
        Expression exp(str);
        cout << exp.Compute() << endl;
    }
    return 0;
}