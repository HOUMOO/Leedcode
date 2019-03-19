//
// Created by houmo on 19-1-15.
//

#include "Solution_5.h"


/*
 *  Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
    Example 1:

    Input: "babad"
    Output: "bab"
    Note: "aba" is also a valid answer.
    Example 2:

    Input: "cbbd"
    Output: "bb"
 */

string Solution_5::longestPalindrome(string s) {
    string String2get = "";

    if(s.size() == 0){
        return "";
    }else{
        String2get = s.substr(0,1);
    }


    for(int i=1; i<s.size(); i++){
        int forward = i-1;
        int backward = i;
        string getPalindromic = "";


        while(forward>=0 && backward<s.size() && s[forward] == s[backward]){
            getPalindromic = s.substr(forward, backward - forward + 1);
            forward--;
            backward++;
        }
        if(getPalindromic.size() > String2get.size()){
            String2get = getPalindromic;
        }

        forward = i-1;
        backward = i+1;
        getPalindromic = "";
        while(forward>=0 && backward<s.size() && s[forward] == s[backward]){
            getPalindromic = s.substr(forward, backward - forward + 1);
            forward--;
            backward++;
        }
        if(getPalindromic.size() > String2get.size()){
            String2get = getPalindromic;
        }
    }

    return String2get;
}
