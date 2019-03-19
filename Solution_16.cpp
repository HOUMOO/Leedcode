//
// Created by houmo on 19-2-24.
//
/*
 * Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
#include "Solution_16.h"

int Solution_16::threeSumClosest(vector<int> &nums, int target) {
    int close = abs(nums[0] + nums[1] + nums[2] - target);
    vector<int> answer = {nums[0], nums[1], nums[2]};
    for (int i = 0; i <= nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (abs(nums[i] + nums[j] + nums[k] - target) < close){

                    close = abs(nums[i] + nums[j] + nums[k] - target);
                    answer[0] = nums[i];
                    answer[1] = nums[j];
                    answer[2] = nums[k];
                    int abs_ = abs(nums[i] + nums[j] + nums[k] - target);
                }
                if(close == 0){
                    break;
                }
            }
            if(close == 0){
                break;
            }
        }
        if(close == 0){
            break;
        }
    }
    return answer[0] + answer[1] + answer[2];

}
