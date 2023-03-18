#include<iostream>
// 解决数独问题
class Sudoku {
  public:
    Sudoku(int* sdkin); // 读入数独矩阵
    ~Sudoku() {};
    void getPrint(); // 输入读入的矩阵
    void getAns(); // 获取结果
    bool isAns(int row, int col, int val); // 判断是否为正确值
    void findAns(int row, int col); // 搜索解空间
  private:
    int sdk[10][10]; // 存储数独矩阵
    bool found; // 判断是否寻得正确值
};

Sudoku::Sudoku(int* sdkin) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sdk[i][j] = *(sdkin + (i * 10 + j));
        }
    }
}

void Sudoku::getPrint() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sdk[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Sudoku::getAns() {
    findAns(0, 0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sdk[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Sudoku::isAns(int row, int col, int val) {
    // searching the row
    for (int i = 0; i < 9; i++) {
        if (sdk[row][i] == val) {
            return false;
        }
    }
    // searching the column
    for (int j = 0; j < 9; j++) {
        if (sdk[j][col] == val) {
            return false;
        }
    }
    // searching the square
    int triRow = row / 3 * 3;
    int triCol = col / 3 * 3 ;
    for (int i = triRow; i < triRow + 3; i++) {
        for (int j = triCol; j < triCol + 3; j++) {
            if (sdk[i][j] == val) {
                return false;
            }
        }
    }
    return true; // 如果值满足条件 返回 true
}

void Sudoku::findAns(int row, int col) {
    found = false;
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
            if (isAns(row, col, i)) {
                sdk[row][col] = i;
                findAns(row, col + 1);
                if (found) {
                    return ;
                } else {
                sdk[row][col] = 0;
                }
            }
        }
    } else {
        findAns(row, col + 1);
    }
}

int main() {
    int sdkin[10][10] = { 0 };
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cin >> sdkin[i][j];
        }
    }
    Sudoku sudoku(&sdkin[0][0]);
    sudoku.getAns();
    return 0;
}
