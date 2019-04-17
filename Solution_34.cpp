//
// Created by houmo on 19-4-9.
//
/*
 * Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
 */
#include "Solution_34.h"

vector<int> Solution_34::searchRange(vector<int> &nums, int target) {
    vector<int> answer = {-1, -1};
    int head = 0;
    int tail = nums.size()-1;
    int mid = (head + tail) / 2;
    if(head>tail){
        return answer;
    }else{
        while(nums[head] != target && head<tail){
            if(nums[mid] < target){
                head = mid+1;
                mid = (mid + tail + 1) / 2;
            }else{
                tail = mid;
                mid = (head + mid) / 2;
            }
//        cout << 1 << endl;
        }
    }

    if(nums[head] != target){
        return answer;
    } else{
        answer[0] = head;
        tail = nums.size()-1;
        mid = (head + tail) / 2;
        while(nums[tail] != target && head<tail){
            if(nums[mid] > target){
                tail = mid-1;
                mid = (head + mid - 1) / 2;

            }else{
                head = mid;
                mid = (mid + tail + 1) / 2;
            }
        }
        answer[1] = tail;
        return answer;
    }

}
