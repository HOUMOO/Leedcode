//
// Created by houmo on 19-3-1.
//

/*
 *Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 *
 */

#ifndef LEETCODE_SOLUTION_22_H
#define LEETCODE_SOLUTION_22_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <math.h>
#include "DataDtructure.h"
using namespace std;

class Solution_22 {
public:
    vector<string> generateParenthesis(int n);

};


#endif //LEETCODE_SOLUTION_22_H
