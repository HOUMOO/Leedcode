//
// Created by houmo on 19-1-15.
//

/*
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"

    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string s, int numRows);
    Example 1:

    Input: s = "PAYPALISHIRING", numRows = 3
    Output: "PAHNAPLSIIGYIR"
    Example 2:

    Input: s = "PAYPALISHIRING", numRows = 4
    Output: "PINALSIGYAHRPI"
    Explanation:

    P     I    N
    A   L S  I G
    Y A   H R
    P     I

 */

#include "Solution_6.h"

string Solution_6::convert(string s, int numRows) {
    if (s.size() == 0 || numRows == 1) {
        return s;
    } else {
        char Matrix[1000][1000] = {0};
        int Dirction = 0; //    0-->Down    1-->zigzag
        int x_pre = 0, y_pre = -1;

        for (int i = 0; i < s.size(); i++) {
            if (Dirction == 0 && y_pre < numRows - 2) {
                Matrix[++y_pre][x_pre] = s[i];

            } else if (Dirction == 0 && y_pre == numRows - 2) {
                Matrix[++y_pre][x_pre] = s[i];
                Dirction = 1;

            } else if (Dirction == 1 && y_pre > 1) {
                Matrix[--y_pre][++x_pre] = s[i];

            } else if (Dirction == 1 && y_pre == 1) {
                Matrix[--y_pre][++x_pre] = s[i];
                Dirction = 0;
            } else {
                cout << "something Wrong Dirction: " << Dirction << " , x_pre: "
                     << x_pre << " , y_pre: " << y_pre << endl;
            }
//        cout << s[i] << endl;
        }

        string Answer = "";
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j <= x_pre; j++) {
                if (s.find(Matrix[i][j]) < s.size()) {
                    Answer.push_back(Matrix[i][j]);
                }
            }
        }

        return Answer;
    }
}
