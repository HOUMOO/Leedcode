//
// Created by houmo on 19-3-20.
//

#include "Solution_28.h"

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
