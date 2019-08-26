//
// Created by houmo on 19-7-22.
//

#include "Solution_49.h"
vector<int> whatStringItis(string s){
    vector<int> strCount(26);
    for(int i=0; i<s.size(); i++){
        strCount[s[i]-'a'] ++;
    }
    return strCount;
}

vector<vector<string>> Solution_49::groupAnagrams(vector<string> &strs) {
    vector<vector<string>> result;
    vector<vector<int>> strsCount;

    for(int i=0; i<strs.size(); i++){
        int found = -1;
        vector<int> newCounts = whatStringItis(strs[i]);

        for(int j=0; j<strsCount.size(); j++){
            if(strsCount[j] == newCounts){
                found = j;
            }
        }
        if(found >-1){
            result[found].push_back(strs[i]);
        }else{
            vector<string> newStrs = {strs[i]};
            result.push_back(newStrs);
            strsCount.push_back(newCounts);
        }
    }

    return result;
}
