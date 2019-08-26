//
// Created by houmo on 19-3-20.
//

#include "Solution_28.h"
/*
int Solution_28::strStr(string haystack, string needle) {
    if(needle.size() ==0){
        return 0;
    } else if(haystack.size() < needle.size()){
        return -1;
    }else{
        int index = -1;

        for(int i=0; i<=haystack.size()-needle.size(); i++){

            int j;
            for(j=0; j<needle.size(); j++){
                if(haystack[i+j] != needle[j]){
                    break;
                }
            }

            if(j==needle.size()){
                index = i;
                break;
            }
        }
        return index;
    }

}
*/

int Solution_28::strStr(string haystack, string needle) {
    int machIndex = -1;
    if(needle.empty()){
        return 0;
    }else if(needle.size()<=haystack.size()){
        vector<int> Next = getNext(needle);
        int j=0;
        for(int i=0; i<haystack.size(); i++){
            if(haystack[i]==needle[j]){
                if(j==needle.size()-1){
                    return i-j;
                }
                j++;
            }else{
                if(j!=0){
                    j = Next[j-1];
                    i--;
                }
            }
        }
    }

    return machIndex;

}

vector<int> Solution_28::getNext(string pattarn) {
    vector<int> Next(pattarn.size(), 0);
    int j = 0;
    for(int i=1; i<pattarn.size(); i++){
        j = Next[i-1];
        if(pattarn[i] == pattarn[j]){
            Next[i] = j+1;
        }else{
            bool noMatch = false;
            while(pattarn[i] != pattarn[j]){
                if(j==0){
                    noMatch = true;
                    break;
                }
                j=Next[j-1];
            }
            if (noMatch){
                Next[i] = 0;
            }else{
                Next[i] = Next[j]+1;
            }
        }
    }
    return Next;
}

void Solution_28::run() {
    string haystack = "mississippi";
    string needle = "issip";
    cout << strStr(haystack, needle) << endl;
}
