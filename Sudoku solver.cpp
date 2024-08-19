#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
using namespace std;

bool isPossible(int arr[9][9], int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (arr[i][col] == val || arr[row][i] == val)
            return false;
    }
    int startRow = 3 * (row / 3); 
    int startCol = 3 * (col / 3);

    for (int i = startRow; i < startRow + 3; i++) {
        for (int j = startCol; j < startCol + 3; j++) {
            if (arr[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku(int arr[9][9], int row, int col) {
    if (col == 9) {
        if (row == 8) {
            return true;
        }
        col = 0;
        row++;
    }

    if (arr[row][col] != 0) {
        return sudoku(arr, row, col + 1);
    }

    for (int i = 1; i <= 9; i++) {
        if (isPossible(arr, row, col, i)) {
            arr[row][col] = i;
            if (sudoku(arr, row, col + 1))
                return true;
            arr[row][col] = 0;
        }
    }
    return false;
}

void display(int arr[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << arr[i][j] << " ";
            if ((j + 1) % 3 == 0 && j < 8) {
                cout << "| ";
            }
        }
        cout << endl;
        if ((i + 1) % 3 == 0 && i < 8) {
            cout << "------+------+------" << endl;
        }
    }
}
int main() {
    int arr[9][9] = { {5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9} };

    display(arr);
    if (sudoku(arr, 0, 0)) {
        cout << "\nSudoku solved:\n";
        display(arr);
    }
    else {
        cout << "\nSudoku not solved";
    }
}


