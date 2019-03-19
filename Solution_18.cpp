//
// Created by houmo on 19-2-26.
//

/*
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
 */
#include "Solution_18.h"

vector<vector<int>> Solution_18::fourSum(vector<int> &nums, int target) {
    vector<vector<int>> answer;
    sort(nums.begin(), nums.end());

    if(nums.size() < 4){
        return answer;
    } else{
        for(int i=0; i<=nums.size()-3; i++){
            for(int j=i+1; j<nums.size()-2; j++){
                for(int k=j+1; k<nums.size()-1; k++){
                    int find = target - nums[i] - nums[j] - nums[k];
                    for(int m=k+1; m<nums.size(); m++){
                        int seen = 0;
                        if(nums[m] == find){
                            for(int a=0; a<answer.size(); a++){
                                if(answer[a][0]==nums[i] && answer[a][1]==nums[j] && answer[a][2] == nums[k] && answer[a][3]==nums[m]){
                                    seen = 1;
                                    break;
                                }
                            }
                            if(seen == 0){
                                answer.push_back({nums[i], nums[j], nums[k], nums[m]});
                                break;
                            }
                        }else if(nums[m] > find){
                            break;
                        }
                    }
                }
            }
        }
        return answer;
    }


}
