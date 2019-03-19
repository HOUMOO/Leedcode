//
// Created by houmo on 19-2-22.
//

/*
 * Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.


 */
#include "Solution_14.h"


string Solution_14::longestCommonPrefix(vector<string> &strs) {
//    vector<string> A = strs;
    if(strs.empty()){
        return "";
    }else{
        int length = strs.size();
        string found = "";
        int flag = 1;
        for(int j=0; j<strs[0].size(); j++){
            found = found + strs[0][j];
            for(int i=0; i<length; i++){
                if(strs[i][j] != strs[0][j]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                break;
            }
        }
        if(flag==1){
            return found;
        }else{
            found.pop_back();
            return found;
        }
    }

}
