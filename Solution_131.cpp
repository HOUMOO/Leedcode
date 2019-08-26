//
// Created by houmo on 19-8-6.
//

#include "Solution_131.h"

//vector<vector<string>> getResult(string s, vector<vector<int>> & breakPoints){
//    vector<vector<string>> result;
//    for(int i=0; i<breakPoints.size(); i++){
//        vector<string> str;
//        for(int j=1; j<breakPoints[i].size(); j++){
//            if(breakPoints[i][j]==1){
//                str.push_back(s.substr(breakPoints[i][j-1], breakPoints[i][j]-breakPoints[i][j-1]));
//            }
//        }
//    }
//}

vector<vector<string>> Solution_131::partition(string s) {
    vector<vector<int>> palindrmeMatrix(s.size(), vector<int>(s.size()));
    for(int i=s.size()-1; i>=0; i--){
        palindrmeMatrix[i][i] = 1;
        for(int j=i+1; j<s.size(); j++){
            if(s[i] == s[j] &&(j-i<=2 || palindrmeMatrix[i+1][j-1]==1)){
                palindrmeMatrix[i][j] = 1;
            }
        }
    }

    vector<vector<string>> result;
    vector<string> strs;
    vector<int> addNums = {1};
    result.push_back(strs);

    for(int i=s.size()-1; i>=0; i--){
        for(int j=0; j<result.size(); j++){
            vector<string> str = result[j];
            str.insert(str.begin(), s.substr(i,1));
            result[j] = str;
        }
        int count = 0;
        for(int j=i+1; j<s.size(); j++){

            if(palindrmeMatrix[i][j] == 1){

                if(j ==s.size()-1){
                    vector<string> str = {s.substr(i)};
                    result.push_back(str);
                    count++;
                }else{
//                    vector<string> str = {s.substr(i,j+1-i), s.substr(j+1)};
//                    result.push_back(str);
//                    count++;

                    if(s.size()-j-1 >= 1){
                        int beforeOnes =0;
                        for(int k=0; k<=s.size()-j-1; k++){
                            beforeOnes += addNums[k];
                        }
                        for(int k=0; k<beforeOnes; k++){

                            int index = result[k].size()-1;
                            vector<string> strTemp = {result[k][index]};
                            int length = result[k][index].size();
                            while(length < s.size()-j-1){
                                strTemp.insert(strTemp.begin(), result[k][--index]);
                                length += result[k][index].size();
                            }
                            strTemp.insert(strTemp.begin(), s.substr(i,j+1-i));
                            result.push_back(strTemp);
                            count++;
                        }
                    }

                }
            }
        }

        addNums.push_back(count);
    }

    return result;


    }

void Solution_131::run() {
    string s = "abcddddd";
    vector<vector<string>> result = partition(s);
    cout << "Solution_131" << endl;
}
