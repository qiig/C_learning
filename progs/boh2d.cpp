#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void getNum(char* arr, int len, int O);

int main() {
	int O;
	string str;
	while (cin >> O >> str) {

		if (str == "!") {
			break;
		}

		const int length = str.length();

		char* s = new char[length + 1];

		strcpy(s, str.c_str());
		getNum(s, length, O);

		delete[](s);
	}

	return 0;
}

void getNum(char* arr, int len, int O) {
	int num = 0;
	int n = 0;
	int op = 0; // o == +; 1 == -;
	char ss;
	if (*arr == '-') { // 判断符号
		op = 1;
	}
	if (*(arr + op) == '0' && *(arr + op + 1) == 'x') {
		for (int i = len - 1; i > 1 + op; i--) {
			ss = *(arr + i);
			n = int(ss - '0');
			if (isalpha(*(arr + i))) {
				switch (ss)
				{
				case 'A':
				case 'a':
					n = 10; break;
				case 'B':
				case 'b':
					n = 11; break;
				case 'C':
				case 'c':
					n = 12; break;
				case 'D':
				case 'd':
					n = 13; break;
				case 'E':
				case 'e':
					n = 14; break;
				case 'F':
				case 'f':
					n = 15; break;
				default:
					break;
				}
			}
			num += n * pow(O, len - i -1);
		}
		if(op == 1) {
			num = -num;
		}
		cout << num << endl;
	}
	else if(*(arr + op) == '0') {
		for(int i = len - 1; i > op; i--) {
			ss = *(arr + i);
			n = (int)(ss - '0');
			num += n * pow(O, len - i - 1);
		}
		if(op == 1) {
			num = -num;
		}
		cout << num << endl;
	}
	else if(O == 2) {
		for(int i = len - 1; i >= op; i--) {
			ss = *(arr + i);
			n = (int)(ss - '0');
			num += n * pow(O, len - i - 1);
		}
		if(op == 1) {
			num = -num;
		}
		cout << num << endl;
	}
	else {
		cout << "Error" << endl;
	}
}