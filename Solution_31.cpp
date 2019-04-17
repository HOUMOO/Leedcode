//
// Created by houmo on 19-3-26.
//

#include "Solution_31.h"

void Solution_31::nextPermutation(vector<int> &nums) {
    int change = 0;
    int numberTest = 2;

    if (nums.size()<=1){
        return;
    } else{
        while (change == 0){
            vector<int> temp;
            temp.assign(nums.end()-numberTest, nums.end());
            sort(temp.begin(), temp.end());
            reverse(temp.begin(), temp.end());
            int notMax = 0;
            for(int i=0; i<numberTest; i++){
                if(temp[i] != nums[nums.size()-numberTest+i]){
                    notMax = 1;
                }
            }
            if(notMax == 1){
                int nextFirst=nums[nums.size()-numberTest];
                int j;
                for(j=temp.size()-1; j>=0; j--){
                    if(nextFirst < temp[j]){
                        nextFirst = temp[j];
                        break;
                    }
                }
                temp.erase(temp.begin()+j);
                sort(temp.begin(),temp.end());

                nums[nums.size()-numberTest] = nextFirst;
                for(j=0; j<temp.size(); j++){
                    nums[nums.size()-numberTest+1+j] = temp[j];
                }
                change = 1;
            }
            if(numberTest>=nums.size() && change == 0){
                sort(nums.begin(), nums.end());
                change = 1;
            } else{
                numberTest++;
            }
        }
    }


}
