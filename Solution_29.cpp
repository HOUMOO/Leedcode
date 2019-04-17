//
// Created by houmo on 19-3-21.
//
/*
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 2^31 − 1 when the division result overflows.
 */

#include "Solution_29.h"

int Solution_29::divide(int dividend, int divisor) {

    int symbol = 1;

    if(dividend > 0 && divisor<0){
        symbol = -1;
    } else if(dividend < 0 && divisor>0){
        symbol = -1;
    }

    long Dividend = labs(dividend);
    long Divisor = labs(divisor);
    long result = 0;

    while(Dividend >= Divisor) {
        long result_onestep = 1;
        long Divisor_onestep = Divisor;

        while (Dividend >= Divisor_onestep << 1) {
            Divisor_onestep <<= 1;
            result_onestep <<= 1;
        }

        Dividend -= Divisor_onestep;
        result += result_onestep;

        if (symbol == 1 && result > 2147483647) {
            return 2147483647;
        } else if (symbol == -1 && result > 2147483648) {
            return 2147483647;
        }

    }
    if (symbol == 1) {
        return result;
    } else {
        return 0 - result;
    }

}

