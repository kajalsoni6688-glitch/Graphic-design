#include <iostream>
using namespace std;
const int SIZE = 9;
void printGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {

    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num)
            return false;
    }
    for (int x = 0; x < SIZE; x++) {
        if (grid[x][col] == num)
            return false;
    }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}
bool solveSudoku(int grid[SIZE][SIZE]) {
    int row = -1, col = -1;
    bool foundEmpty = false;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                foundEmpty = true;
                break;
            }
        }
        if (foundEmpty)
            break;
    }

    if (!foundEmpty)
        return true;

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {

    int grid[SIZE][SIZE];

    cout << "Enter the Sudoku puzzle (9x9).\n";
    cout << "Use 0 for empty cells:\n\n";

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> grid[i][j];
        }
    }

    cout << "\nOriginal Sudoku:\n";
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolved Sudoku:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists!";
    }

    return 0;
}