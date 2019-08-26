//
// Created by houmo on 19-4-29.
//

#include "Solution_42.h"

int find_otherside(vector<int> &height, int nowIndex){
    int heightNow = height[nowIndex];
    int i;
    for(i=nowIndex+1; i<height.size(); i++){
        if(height[i] >= heightNow){
            break;
        }
    }

    return i;
}
int find_otherside2(vector<int> &height, int nowIndex){
    int heightNow = height[nowIndex];
    int i;
    for(i=nowIndex-1; i>=0; i--){
        if(height[i] >= heightNow){
            break;
        }
    }

    return i;
}

int Solution_42::trap(vector<int> &height) {
    vector<int> water(height.size(), 0);

    for(int i=0; i<height.size(); i++){
        if(height[i]>0){
            int otherSide = find_otherside(height, i);
            if(otherSide<height.size() && otherSide-i > 1){
                for(int j=i+1; j<otherSide; j++){
                    water[j] = height[i] - height[j];
                }
                i=otherSide-1;
            }
        }
    }

    for(int i=height.size()-1; i>=0; i--){
        if(height[i]>0){
            int otherSide = find_otherside2(height, i);
            if(otherSide >= 0 && i-otherSide > 1){
                for(int j=i-1; j>otherSide; j--){
                    if(water[j] < height[i]-height[j]){
                        water[j] = height[i]-height[j];
                    }
                }
                i = otherSide+1;
            }
        }
    }

    int allWater = 0;

    for(int i=0; i<water.size(); i++){
        allWater += water[i];
    }

    return allWater;
}
