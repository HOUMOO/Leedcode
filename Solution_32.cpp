//
// Created by houmo on 3/28/19.
//

/*
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

Example 1:

Input: "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()"
Example 2:

Input: ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()"
 */

#include "Solution_32.h"

int Solution_32::longestValidParentheses(string s) {
    int MaxLength = 0;
    if(s.size()==0){
        return 0;
    }else{
        for(int i=0; i<s.size()-1; i++){
            stack<char> brackets;
            int length = 0;
            int tempLength = 0;

            for(int j=i; j<s.size(); j++){
                if(s[j] == '('){
                    brackets.push(s[j]);
                    length ++;
                } else{
                    if(brackets.empty()){
                        break;
                    }else if(brackets.top() == '('){
                        brackets.pop();
                        length ++;
                        if(brackets.empty()){
                            tempLength = length;
                        }
                    }else{
                        break;
                    }
                }
            }

            if(tempLength > MaxLength){
                MaxLength = tempLength;
            }
        }

        return MaxLength;
    }

}
