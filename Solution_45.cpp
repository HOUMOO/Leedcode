//
// Created by houmo on 19-6-30.
//

#include "Solution_45.h"

int Solution_45::jump(vector<int> &nums) {
    if(nums.size()<=1){
        return 0;
    }
    else if(nums.size() == 2){
        return 1;
    }else{
        vector<int> jumpIndex = {int(nums.size() - 2), int(nums.size()-1)};
        for(int i=int(nums.size() - 3); i>=0; i--){
            if(nums[i] < jumpIndex[0]-i){
                continue;
            }else{
                if(nums[i] >= nums.size()-i-1){
                    jumpIndex.erase(jumpIndex.begin(), jumpIndex.end()-1);
                    jumpIndex.insert(jumpIndex.begin(), i);
                }else{
                    for(int j=int(jumpIndex.size()-1); j>=0; j--){

                        if(nums[i] >= jumpIndex[j]-i){
                            jumpIndex.erase(jumpIndex.begin(), jumpIndex.begin()+j);
                            jumpIndex.insert(jumpIndex.begin(), i);
                            break;
                        }
                    }
                }
            }
        }

        return int(jumpIndex.size() - 1);
    }

}
