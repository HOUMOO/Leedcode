//
// Created by houmo on 19-4-29.
//
/*
 * Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
 */
#include "Solution_41.h"

int Solution_41::firstMissingPositive(vector<int> &nums) {
    int i=0;
    if(nums.size() == 0){
        return 1;
    }else{
        while(i<nums.size()){
            if(nums[i] != i+1 && nums[i] > 0 && nums[i]<=nums.size()){
                if(nums[nums[i]-1] == nums[i]){
                    i++;
                }else{
                    swap(nums[i], nums[nums[i]-1]);
                }
            }else{
                i++;
            }
        }

        i=0;
        while(i<nums.size() && nums[i] == i+1 && nums[i]>0 && nums[i]<=nums.size()){
            i++;
        }
        if(i==nums.size() && nums[0]==1){
            return nums[nums.size()-1]+1;
        }else if(i==nums.size() && nums[0]!=1){
            return 1;
        }
        else{
            return i+1;
        }
    }

}
