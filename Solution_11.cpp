//
// Created by houmo on 19-1-18.
//

/*
 * Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.





The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.



Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

 */

#include "Solution_11.h"

int Solution_11::maxArea(vector<int> &height) {
    int MaxCapacity = 0;
    int CapacityForward = 0;
    int CapacityBackWard = 0;
    int head;
    int tail;

    for(int i=0; i<height.size(); i++){
        head = 0;
        while(head<i){
            if(height[head] >= height[i]){
                CapacityForward = height[i] * (i-head);
                head = i;
            }else{
                head++;
            }
        }
        tail=height.size()-1;
        while(tail>i){
            if(height[tail] >= height[i]){
                CapacityBackWard = height[i] * (tail-i);
                tail = i;
            }else{
                tail--;
            }
        }
        if(CapacityForward > MaxCapacity){
            MaxCapacity = CapacityForward;
        }
        if(CapacityBackWard > MaxCapacity){
            MaxCapacity = CapacityBackWard;
        }
//        cout << CapacityForward << " , " << CapacityBackWard << endl;
//        cout<<MaxCapacity<<endl;
//        cout<<endl;
    }

    return MaxCapacity;
}
