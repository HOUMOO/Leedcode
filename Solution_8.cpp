//
// Created by houmo on 19-1-17.
//

#include "Solution_8.h"
/*
 Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
 */

int Solution_8::myAtoi(string str) {

    int answer = 0;
    int minus = 1;
    char firstChar = 'H';

    for (int i = 0; i < str.size(); i++) {
        if (firstChar == 'H' && str[i] == ' ') {

        } else if (firstChar == 'H' && (str[i] != '+' && str[i] != '-' && (str[i] < '0' || str[i] > '9'))) {
            return 0;
        } else if (firstChar == 'H' && (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))) {
            firstChar = str[i];
            if (firstChar == '-') {
                minus = -1;
            } else if (firstChar >= '0' && firstChar <= '9') {
                answer = 10 * answer + firstChar - '0';
            }
        } else if (firstChar != 'H' && ((str[i] >= '0' && str[i] <= '9'))) {
            answer = 10 * answer + str[i] - '0';

            if (i + 1 < str.size()) {

                if ((answer > (pow(2, 31) - 1) / 10 && isANumber(str[i + 1]))) {
                    return (minus > 0) ? pow(2, 31) - 1 : -1 * pow(2, 31);
                } else if (minus == 1 && answer == int((pow(2, 31)) / 10) && str[i + 1] > '7') {
                    return pow(2, 31) - 1;
                } else if (minus == -1 && answer == int((pow(2, 31)) / 10) && str[i + 1] > '8') {
                    return -1 * pow(2, 31);
                }
            }

        } else if (firstChar != 'H' && (str[i] < '0' || str[i] > '9')) {
            return minus * answer;
        }
    }

    return minus * answer;
}

bool Solution_8::isANumber(char C) {
    if (C >= '0' && C <= '9') {
        return true;
    } else {
        return false;
    }
}
