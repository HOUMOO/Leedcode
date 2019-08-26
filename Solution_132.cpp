//
// Created by houmo on 19-8-6.
//

#include "Solution_132.h"

int Solution_132::minCut(string s) {
    vector<vector<int>> palindrmeMatrix(s.size(), vector<int>(s.size()));
    for(int i=s.size()-1; i>=0; i--){
        palindrmeMatrix[i][i] = 1;
        for(int j=i+1; j<s.size(); j++){
            if(s[i] == s[j] &&(j-i<=2 || palindrmeMatrix[i+1][j-1]==1)){
                palindrmeMatrix[i][j] = 1;
            }
        }
    }

    vector<int> cuts(s.size()+1);
    cuts[s.size()] = -1;

    for(int i=s.size()-2; i>=0; i--){
        cuts[i] = 1+cuts[i+1];
        for(int j=i+1; j<s.size();j++){
            if(palindrmeMatrix[i][j] == 1){
                cuts[i] = min(cuts[i], 1 + cuts[j+1]);
            }
        }
    }

    return cuts[0];

}

void Solution_132::run() {
    string s = "cbbbcc";
    cout << minCut(s) << endl;


}
