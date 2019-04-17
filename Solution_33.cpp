//
// Created by houmo on 19-4-1.
//

#include "Solution_33.h"

int Solution_33::search(vector<int> &nums, int target) {
    int head = 0;
    int tail = nums.size()-1;
    int mid = (head + tail) / 2;

    while(head < tail){
        if(nums[head] == target){
            return head;
        } else if(nums[mid] == target){
            return mid;
        }else if(nums[tail] == target){
            return tail;
        } else{
            if(nums[head] >= nums[tail]){
                if(nums[mid] > nums[head]){
                    if(nums[head] <= target && nums[mid] >= target){
                        tail = mid;
                        mid = (head+mid) / 2;

                    } else{
                        head = mid+1;
                        mid = (mid + tail + 1) / 2;

                    }
//                    cout<<1<<endl;
                }else{
                    if(nums[mid] <= target && nums[tail] >= target){
                        head = mid;
                        mid = (mid + tail) / 2;

                    } else{
                        tail = mid-1;
                        mid = (head+mid-1) / 2;

                    }
//                    cout<<1<<endl;
                };
            }else{
                if(nums[mid]>=target){
                    tail = mid;
                    mid = (head+mid) / 2;

//                    cout<<1<<endl;
                }else{
                    head = mid+1;
                    mid = (mid + tail + 1) / 2;

//                    cout<<1<<endl;
                }
            }
        }
    }
    if(head>tail){
        return -1;
    }
    else if(nums[head] != target){
        return -1;
    }else{
        return head;
    }

}
