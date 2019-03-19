//
// Created by houmo on 19-1-8.
//

#ifndef LEETCODE_SOLUTION1_H
#define LEETCODE_SOLUTION1_H

#include <vector>
#include <iostream>

using namespace std;

/*
    Given an array of integers, return indices of the two numbers such that they add up to a specific target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    Example:
    Given nums = [2, 7, 11, 15], target = 9,
    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/

class Solution1 {
public:
    vector<int> twoSum(vector<int> &nums, int target);
};


#endif //LEETCODE_SOLUTION1_H
