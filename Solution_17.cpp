//
// Created by houmo on 19-2-25.
//

/*
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

#include "Solution_17.h"

vector<string> Solution_17::letterCombinations(string digits) {
    vector<vector<char >> ss;
    vector<char> s2 = {'a','b','c'};
    vector<char> s3 = {'d','e','f'};
    vector<char> s4 = {'g','h','i'};
    vector<char> s5 = {'j','k','l'};
    vector<char> s6 = {'m','n','o'};
    vector<char> s7 = {'p','q','r','s'};
    vector<char> s8 = {'t','u','v'};
    vector<char> s9 = {'w','x','y','z'};
    ss.push_back(s2);
    ss.push_back(s3);
    ss.push_back(s4);
    ss.push_back(s5);
    ss.push_back(s6);
    ss.push_back(s7);
    ss.push_back(s8);
    ss.push_back(s9);


    vector<int> carryBit;
    vector<int> valuesIndex;
    int sizeOfDigits = 1;

    for(int i=0; i<digits.size();i++){
        sizeOfDigits *= ss[digits[i]-50].size();
        carryBit.push_back(0);
        valuesIndex.push_back(0);
    }

    if(digits.size()==0){
        sizeOfDigits = 0;
    }

    vector<string> answer;

    for(int i=0; i<sizeOfDigits; i++){
        string Temp = string(digits.size(),'0');
        valuesIndex[digits.size()-1] = i%ss[digits[digits.size()-1]-50].size();
        Temp[digits.size()-1] = ss[digits[digits.size()-1]-50][valuesIndex[digits.size()-1]];

        if(i%ss[digits[digits.size()-1]-50].size()==0 && i!=0){
            carryBit[digits.size()-2] = 1;
        }
        for(int j=digits.size()-2; j>=0;j--){
            if(carryBit[j] == 1){
                if(valuesIndex[j]+1>=ss[digits[j]-50].size()){
                    valuesIndex[j] = 0;
                    if(j!=0){
                        carryBit[j-1] = 1;
                    }
                } else{
                    valuesIndex[j] += 1;
                }
                carryBit[j] = 0;
            }
            Temp[j] = ss[digits[j]-50][valuesIndex[j]];
        }

        answer.push_back(Temp);
    }

    return answer;
}
