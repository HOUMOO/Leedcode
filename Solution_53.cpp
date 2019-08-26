//
// Created by houmo on 19-8-6.
//

#include "Solution_53.h"

int Solution_53::maxSubArray(vector<int> &nums) {
    vector<int> maxBox (nums.size(), INT16_MIN);
    maxBox[0] = nums[0];
    int maxOne = nums[0];

    for(int i=1; i<nums.size(); i++){
        maxBox[i] = max(nums[i]+maxBox[i-1], nums[i]);
        maxOne = max(maxBox[i], maxOne);
    }

    return maxOne;
}

int Solution_53::run() {
    vector<int> numberArray = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(numberArray) << endl;
    return 0;
}
