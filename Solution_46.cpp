//
// Created by houmo on 19-7-15.
//

#include "Solution_46.h"

vector<vector<int>> Solution_46::permute(vector<int> &nums) {
    vector<vector<int>> Box;
    if(nums.size()==1){
        vector<int> temp = {nums[0]};
        Box.push_back(temp);
    }
    else{
        for(int i=0; i<nums.size(); i++){
            vector<int>tempNUms = nums;
            tempNUms.erase(tempNUms.begin()+i);
            vector<vector<int>> SubBox = permute(tempNUms);
            for(int j=0; j<SubBox.size(); j++){
                tempNUms = SubBox[j];
                tempNUms.insert(tempNUms.begin(), nums[i]);
                bool isInsert = true;
                for(int k=0; k<Box.size(); k++){
                    if(Box[k] == tempNUms){
                        isInsert = false;
                    }
                }
                if(isInsert){
                    Box.push_back(tempNUms);
                }
            }
        }
    }
    return Box;
}
