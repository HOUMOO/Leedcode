//
// Created by houmo on 19-6-21.
//

#include "Solution_44_faster.h"

bool Solution_44_faster::isMatch(string s, string p) {
    int indexS = 0;
    int indexP = 0;

    /*
    string back;
    string sequence;

    while(!s.empty()){
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
    }

    while(p[0] == '*'){
        p = p.substr(1);
    }

    return p.empty();
    */

    string back;
    string sequence;

    while(!s.empty()){
        if(p=="*"){
            break;
        }else if(p[0] == '*'){
            back = s;
            sequence = p.substr(1);
            p = p.substr(1);
        }else if(p[0]=='?' || p[0]==s[0]){

            s = s.substr(1);
            p = p.substr(1);
        }else if(!sequence.empty()){
            s = back.substr(1);
            back = back.substr(1);
            p = sequence;
        }else{
            return false;
        }
    }

    while(p[indexP] == '*'){
        indexP++;
    }

    return p.empty();
    
}
