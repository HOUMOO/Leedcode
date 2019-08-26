//
// Created by houmo on 19-7-22.
//

#include "Solution_49_faster.h"

vector<vector<string>> Solution_49_faster::groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;

    if(strs.empty()){
        return result;
    } else{
        sort(strs.begin(), strs.end());
        map<string, vector<string>> mapHash;

        for(int i=0; i<strs.size(); i++){
            string strTemp = strs[i];
            sort(strTemp.begin(), strTemp.end());
            mapHash[strTemp].push_back(strs[i]);
        }

        for(map<string, vector<string>>::iterator iter = mapHash.begin(); iter != mapHash.end(); iter++){
            result.push_back(iter->second);
        }
        return result;
    }


}
