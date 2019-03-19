//
// Created by houmo on 19-1-21.
//

/*
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, two is written as II in Roman numeral, just two one's added together. Twelve is written as, XII, which is simply X + II. The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral. Input is guaranteed to be within the range from 1 to 3999.

Example 1:

Input: 3
Output: "III"
Example 2:

Input: 4
Output: "IV"
Example 3:

Input: 9
Output: "IX"
Example 4:

Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 5:

Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 */

#include "Solution_12.h"

string Solution_12::intToRoman(int num) {
    string answer = "";
    int theNum = num;

    while(theNum>=1000){
        theNum -=1000;
        answer.append("M");
    }
    if(theNum>=900){
        theNum -= 900;
        answer.append("CM");
    }
    if(theNum>=500){
        theNum -= 500;
        answer.append("D");
    }
    if(theNum>=400){
        theNum -= 400;
        answer.append("CD");
    }
    while(theNum>=100){
        theNum -= 100;
        answer.append("C");
    }
    if(theNum>=90){
        theNum -= 90;
        answer.append("XC");
    }
    if(theNum>=50){
        theNum -= 50;
        answer.append("L");
    }
    if(theNum>=40){
        theNum -= 40;
        answer.append("XL");
    }
    while(theNum>=10){
        theNum -= 10;
        answer.append("X");
    }
    if(theNum >= 9){
        theNum -= 9;
        answer.append("IX");
    }
    if(theNum >= 5){
        theNum -= 5;
        answer.append("V");
    }
    if(theNum >= 4){
        theNum -= 4;
        answer.append("IV");
    }
    while(theNum>=1){
        theNum--;
        answer.append("I");
    }


    return answer;
}
