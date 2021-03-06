//
// Created by houmo on 19-2-26.
//
/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
 */

#include "Solution_20.h"

bool Solution_20::isValid(string s) {
    stack<char> brackets;
    int noLeft = 0;
    for(int i=0; i<s.size(); i++){

        if(s[i]=='('){
            brackets.push(s[i]);
        }else if(s[i] == '['){
            brackets.push(s[i]);
        }else if(s[i] == '{'){
            brackets.push(s[i]);
        }else if(s[i] == ')'){
            if (brackets.empty()) {
                noLeft = 1;
                break;
            }else if(brackets.top() == '('){
                brackets.pop();
            }else{
                break;
            }
        }else if(s[i] == ']'){
            if (brackets.empty()) {
                noLeft = 1;
                break;
            }else if(brackets.top() == '['){
                brackets.pop();
            }else{
                break;
            }
        }else if(s[i] == '}'){
            if (brackets.empty()) {
                noLeft = 1;
                break;
            }else if(brackets.top() == '{'){
                brackets.pop();
            }else{
                break;
            }
        }
    }
    if(brackets.empty() && noLeft==0){
        return true;
    } else{
        return false;
    }

}
