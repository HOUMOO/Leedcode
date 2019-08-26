//
// Created by houmo on 19-7-15.
//

#include "Solution_48.h"

vector<vector<int >> get90DegreeLocation(int width){
    vector<vector<int>> box;
    vector<int> loction = {0,0};
    box.push_back(loction);
    for(int i=1; i<width; i++){
        loction = {i, 0};
        box.push_back(loction);
    }
    for(int i=1; i<width; i++){
        loction = {width-1, i};
        box.push_back(loction);
    }
    for(int i=2*width-3; i>0; i--){
        loction = {box[i][1], box[i][0]};
        box.push_back(loction);
    }
    return box;
}

void Solution_48::rotate(vector<vector<int>> &matrix) {

    vector<vector<int>> temp = matrix;

    int width = matrix.size();
    for(int i=0; i<width/2; i++){
        vector<vector<int >> locations = get90DegreeLocation(width-i*2);
        int nextloc = width-i*2-1;
        for(int l=0; l<locations.size();l++){
            temp[locations[l][0]+i][locations[l][1]+i] = matrix[locations[nextloc][0]+i][ locations[nextloc][1]+i];
            nextloc++;
            if(nextloc>=locations.size()){
                nextloc = 0;
            }
        }
    }
    matrix = temp;

}
