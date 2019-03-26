//
// Created by houmo on 3/22/19.
//
/*
You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

Example 1:

Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]
Output: [0,9]
Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
The output order does not matter, returning [9,0] is fine too.
Example 2:

Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
Output: []
 */
#include "Solution_30.h"

vector<int> Solution_30::findSubstring(string s, vector <string> &words) {
    vector<int> Answer;

    if(words.size()==0 || s.size()==0 || s.size()<words[0].size()){
        return Answer;
    }else{
        int lengthOfAWord = words[0].length();
        int sizeOfvec = words.size();

        vector<int> FoundGoal{1};
        vector<string> wordsTemp{words[0]};
        for(int i=1;i<words.size();i++){
            if(find(wordsTemp.begin(), wordsTemp.end(),words[i])!=wordsTemp.end()){
                FoundGoal[find(wordsTemp.begin(), wordsTemp.end(),words[i])-wordsTemp.begin()]++;
            }else{
                wordsTemp.push_back(words[i]);
                FoundGoal.push_back(1);
            }
            
        }
        vector<int> Found(FoundGoal.size(),0);

        int inFinding = 0;

        for(int i=0; i<=s.size()-lengthOfAWord; i++){
            vector<string>::iterator Index  = find(wordsTemp.begin(),wordsTemp.end(),s.substr(i,lengthOfAWord));
            if(Index != wordsTemp.end()){
                inFinding = 1;
                Found[Index-wordsTemp.begin()] ++;
                for(int j=1; j<sizeOfvec;j++){
                    Index = find(wordsTemp.begin(),wordsTemp.end(),s.substr(i+j*lengthOfAWord,lengthOfAWord));
                    if(Index == wordsTemp.end()){
                        inFinding = 0;
                        for(int k=0; k<Found.size(); k++){
                            Found[k] = 0;
                        }
                        break;
                    }
                    Found[Index-wordsTemp.begin()] ++;
                    if(Found[Index-wordsTemp.begin()] > FoundGoal[Index-wordsTemp.begin()]){
                        inFinding = 0;
                        for(int k=0; k<Found.size(); k++){
                            Found[k] = 0;
                        }
                        break;
                    }
                }
                if(inFinding == 1){
                    Answer.push_back(i);
                    for(int k=0; k<Found.size(); k++){
                        Found[k] = 0;
                    }
                }

            }
        }

        return Answer;
    }

}
