//
// Created by houmo on 19-6-19.
//

#include "Solution_10.h"

bool Solution_10::isMatch(string s, string p) {
    if(p.length()==0){
        return s.empty();
    } else if(p.length()==1 || p[1]!='*'){
        if(!s.empty() && (p[0]==s[0] || p[0]=='.')){
            return isMatch(s.substr(1), p.substr(1));
        }else{
            return false;
        }
    }else{
        if(s.empty() || (p[0]!=s[0] && p[0]!='.')){
            return isMatch(s, p.substr(2));
        } else{
            if(isMatch(s, p.substr(2))){
                return true;
            }else{
                return isMatch(s.substr(1), p);
            }
        }
    }
}
