//
// Created by houmo on 19-2-23.
//
/*
 *Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
 */
#include "Solution_15.h"

vector<vector<int>> Solution_15::threeSum(vector<int> &nums) {
    vector<vector<int>> vv;
    sort(nums.begin(), nums.end());
    int ZeroIndex = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] >= 0) {
            ZeroIndex = i;
            break;
        }
    }
    if (ZeroIndex == nums.size()) {
        return vv;
    } else {
//        int zeroFlag = 0;
        for (int i = 0; i <= ZeroIndex; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int target = 0 - nums[i] - nums[j];

                for(int k=ZeroIndex>j+1?ZeroIndex:j+1; k<nums.size(); k++){
                    if(nums[k] == target){
                        int seen = 0;
                        for(int s=0; s<vv.size(); s++){
                            if(vv[s][0]==nums[i] && vv[s][1]==nums[j] && vv[s][2]==nums[k]){
                                seen = 1;
                                break;
                            }
                        }
                        if(seen == 0){
                            vv.push_back({nums[i], nums[j], nums[k]});
                            break;
                        }
                    }else if(nums[k] > target){
                        break;
                    }
                }
            }
        }
        return vv;
    }


}
