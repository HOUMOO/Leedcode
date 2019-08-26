//
// Created by houmo on 19-6-30.
//

#include "Solution_45_faster.h"

int Solution_45_faster::jump(vector<int> &nums) {
    int low = 0;
    int high = nums[0];
    int count = 0;
    if(nums.size()==1){
        return 0;
    }else{
        while(high < nums.size()-1){
            int MaxSide = 0;
            for(int i=low; i<=high; i++){
                MaxSide = max(MaxSide, nums[i]+i);
            }

            low++;
            count++;
            high = MaxSide;
        }

        return count+1;
    }
}
