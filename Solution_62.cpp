//
// Created by houmo on 19-8-8.
//

#include "Solution_62.h"

int Solution_62::uniquePaths(int m, int n) {
    vector<vector<int>> path(m, vector<int>(n));
    path[m-1][n-1] = 1;

    int steps = m+n-3;
    if(m==1 || n==1){
        return 1;
    }else{
        for(int i=steps; i>0; i--){
            for(int j=0; j<m; j++){
                if(i-j>=n || i-j<0){
//                continue;
                }else{
                    int pathNums=0;
                    if(i-j+1<n){
                        pathNums += path[j][i-j+1];
                    }
                    if(j+1<m){
                        pathNums += path[j+1][i-j];

                    }
                    path[j][i-j] = pathNums;
                }
            }
        }

        return path[1][0] + path[0][1];
    }

}

void Solution_62::run() {
    int m = 1;
    int n = 10;
    cout << uniquePaths(m, n) << endl;
}

int Solution_62::uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    return 0;
}
