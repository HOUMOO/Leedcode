//
// Created by houmo on 6/20/19.
//

#include "Solution_44.h"

bool Solution_44::isMatch(string s, string p) {
    string back;
    string sequence;

    if(p[0] == '*'){
        back = s;
        sequence = p.substr(1);
        p = p.substr(1);
    }else if(p[0]==s[0] || p[0] == '?'){
        s = s.substr(1);
        p = p.substr(1);
    }else if(!sequence.empty()){
        s = back.substr(1);
        back = back.substr(1);
        p=sequence;
    }else{
        return false;
    }
    while(p[0] == '*'){
        p = p.substr(1);
    }

    return p.empty();
}
