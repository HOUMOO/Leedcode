//
// Created by houmo on 19-6-9.
//

#include "Solution_44.h"

int length(string p){
    int count = 0;
    for(int i=0; i<p.length(); i++){
        if(p[i] != '*'){
            count++;
        }
    }
    return count;
}

bool Match(string s, string p){
    if(p.empty()){
        return s.empty();
    }else{
        if(s.empty()){
            if(length(p)==0)return true;
            else return false;
        }else if(p[0] == '*'){
            if(length(p) > s.length()){
                return false;
            }else if(Match(s, p.substr(1))){
                return true;
            }else{
                return Match(s.substr(1),p);
            }

        } else if(!s.empty() && (p[0]==s[0] || p[0]=='?')){
            return Match(s.substr(1), p.substr(1));
        } else{
            return false;
        }
    }
}

bool Solution_44::isMatch(string s, string p) {
    int i = 0;
    char flag = 'H';
    int begin = 0;
    while(i<p.length()){
        if(flag == 'H' && p[i]=='*'){
            flag = '*';
            begin = i;
            i++;
        }else if(flag=='*' && p[i]!='*'){
            p.erase(begin, i-begin-1);
            flag = 'H';
            i = begin+1;
        }else{
            i++;
        }
    }

    return Match(s,p);


}
