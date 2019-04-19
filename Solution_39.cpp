//
// Created by houmo on 19-4-18.
//

#include "Solution_39.h"



vector<vector<int>> Solution_39::combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> answer;

    vector<int>::iterator iter = find(candidates.begin(), candidates.end(), target);
    if(iter != candidates.end()){
        answer.push_back({target});
    }
    if(target > candidates[0]){
        int index = 0;

        while(index<candidates.size() && candidates[index] < target){
            vector<vector<int>> queueAnswer = combinationSum(candidates, target-candidates[index]);
            if(!queueAnswer.empty()){
                for(int i=0;i<queueAnswer.size();i++){
                    vector<int> temp = queueAnswer[i];
                    temp.push_back(candidates[index]);
                    sort(temp.begin(), temp.end());
                    answer.push_back(temp);
                }
            }
            index++;
        }
    }

    if(!answer.empty()){

        for(int k=1; k<answer.size(); k++){

            for(int n=0; n<k; n++){

                if(answer[n].size() == answer[k].size()){
                    int j;
                    for(j=0; j<answer[n].size(); j++){
                        if(answer[n][j] != answer[k][j]){
                            break;
                        }
                    }
                    if(j>=answer[n].size()){
                        answer.erase(answer.begin()+k);
                        k--;
                    }
                }
            }

        }
    }
    return answer;
}
