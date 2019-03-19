//
// Created by houmo on 19-1-13.
//

/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

#include "Solution_3.h"

int Solution_3::lengthOfLongestSubstring(string s) {
    int count[95];
    int begin = 0;
    int max = 0, tempLength = 0;

    for (int z = 0; z < 95; z++) {
        count[z] = -1;
    }

    int i;
    for (i = 0; i < s.size(); i++) {
//        cout << count[int(s[i]) - 32] << " ? " << endl;
        if (count[int(s[i]) - 32] == -1) {
            count[int(s[i]) - 32] = i;
        } else {
            tempLength = i - begin;

            if (tempLength > max) {
                max = tempLength;
//                cout << max << endl;
            }
            int tempBegin = count[int(s[i]) - 32] + 1;
            for(int z=begin; z<i; z++){
                count[int(s[z]) - 32] = -1;
            }
            begin = tempBegin;
            i = begin - 1;
        }
//        cout << s[i] << i << endl;
//        cout << endl;
    }

    tempLength = i - begin;

    if (tempLength > max) {
        max = tempLength;

    }

    return max;
}
