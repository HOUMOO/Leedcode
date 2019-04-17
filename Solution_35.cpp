//
// Created by houmo on 19-4-9.
//
/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:

Input: [1,3,5,6], 5
Output: 2
Example 2:

Input: [1,3,5,6], 2
Output: 1
Example 3:

Input: [1,3,5,6], 7
Output: 4
Example 4:

Input: [1,3,5,6], 0
Output: 0
 */

#include "Solution_35.h"

int Solution_35::searchInsert(vector<int> &nums, int target) {
    int head = 0;
    int tail = nums.size()-1;
    int mid = (head + tail) / 2;

    while(nums[head]!=target && head < tail){
        if(nums[mid] < target){
            head = mid + 1;
            mid = (mid + tail + 1) / 2;
        }else{
            tail = mid;
            mid = (head + mid) / 2;
        }
    }
    if(head > tail){
        return 0;
    }else if(nums[head]==target){
        return  head;
    }else{
        if(nums[head]>target){
            return head;
        }else{
            return head+1;
        }
    }

}
