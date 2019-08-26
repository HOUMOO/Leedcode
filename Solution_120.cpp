//
// Created by houmo on 19-8-6.
//

#include "Solution_120.h"

int Solution_120::minimumTotal(vector<vector<int>> &triangle) {
    if(triangle.size() < 2){
        return triangle[0][0];
    }
    else{
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }

}

int Solution_120::run() {
    vector<vector<int>> triangle = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3}
    };

    cout << minimumTotal(triangle) << endl;
    return 0;
}
