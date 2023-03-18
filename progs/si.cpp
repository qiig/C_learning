#include<iostream>

using namespace std;

bool isRight(int row, int col, int val);
void findnull(int row, int col);

int sdk[9][9] = { 0 }; // 存储数独
bool found = false; // 判断是否已寻得 val

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sdk[i][j];
        }
    }
    findnull(0, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sdk[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
// 判断填入的值是否合适
bool isRight(int row, int col, int val) {
    for (int i = 0; i < 9; i++) {  // row
        if (sdk[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { // column
        if (sdk[j][col] == val) {
            return false;
        }
    }
    // 9 * 9
    int triRow = row / 3 * 3 + 3;
    int triCol = col / 3 * 3 + 3;
    for (int i = triRow - 3; i < triRow; i++) {
        for (int j = triCol - 3; j < triCol; j++) {
            if (sdk[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}
// 搜索 0 处的值
void findnull(int row, int col) {
    if (col > 8) {
        row++;
        col = 0;
    }
    if (row > 8) {
        found = true;
        return ;
    }
    if (sdk[row][col] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (isRight(row, col, i)) {
                sdk[row][col] = i;
                findnull(row, col + 1);
                if (found) {
                    return ;
                } else {
                sdk[row][col] = 0;}
            }
        }
    } else {
        findnull(row, col + 1);
    }
}