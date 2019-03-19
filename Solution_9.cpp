//
// Created by houmo on 19-1-17.
//

#include "Solution_9.h"

bool Solution_9::isPalindrome(int x) {
    if(x<0){
        return false;
    } else{
        string NumString = to_string(x);
        int head=0, tail = NumString.size()-1;

        while(head<=tail){
            if(NumString[head] != NumString[tail]){
                return false;
            } else{
                head ++;
                tail --;
            }
        }
        return true;
    }

}
