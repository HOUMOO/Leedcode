//
// Created by houmo on 19-1-16.
//

#include "Solution_7.h"

/*

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21

 Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 */



int Solution_7::reverse(int x) {

    int original = x;
    int answer = 0;
    int getOne;

    if (x < -1 * pow(2, 31) || x > pow(2, 31) - 1){
        cout << "Out 1" << endl;
        return 0;
    }else{
        while (original != 0) {
            getOne = original % 10;
            answer = answer * 10 + getOne;
            original /= 10;

            if((answer>(pow(2, 31) - 1)/10 && original!=0)|| (answer<(-1 * pow(2, 31))/10 && original!=0) ||(answer==(pow(2, 31) - 1)/10 && original>7) || (answer==(-1 * pow(2, 31))/10 && original<-8)){
                return 0;

            }


        }

        return answer;
    }


}
