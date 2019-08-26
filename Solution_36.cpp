//
// Created by houmo on 19-4-9.
//
/*
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true
Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
The given board contain only digits 1-9 and the character '.'.
The given board size is always 9x9.
 */
#include "Solution_36.h"

bool Solution_36::isValidSudoku(vector<vector<char>> &board) {
    vector<int> mark(9,0);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            mark[j] = 0;
        }
        for(int j=0; j<9; j++){
            if(board[i][j] != '.'){
                int index =  board[i][j] - '0' - 1;
                if(mark[index] != 0){
//                    cout << i << ", 0 , " << j << ", " << board[i][j] << endl;
                    return false;
                }else{
                    mark[index] = 1;
                }
            }
        }
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            mark[j] = 0;
        }
        for(int j=0; j<9; j++){
            if(board[j][i] != '.'){
                int index =  board[j][i] - '0' - 1;
                if(mark[index] != 0){
//                    cout << j << ", 1 , " << i <<  ", " << board[j][i] << endl;
                    return false;
                }else{
                    mark[index] = 1;
                }
            }
        }
    }

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            mark[j] = 0;
        }
//        cout << "---------------------------" << endl;
        for(int j=0; j<9; j++){
//            cout << board[(i/3)*3 + j/3][(i%3)*3 + j%3] << endl;
            if(board[(i/3)*3 + j/3][(i%3)*3 + j%3] != '.'){
                int index =  board[(i/3)*3 + j/3][(i%3)*3 + j%3] - '0' - 1;
                if(mark[index] != 0){
                    return false;
                }else{
                    mark[index] = 1;
                }
            }
        }
    }


    return true;
}
