//
// Created by houmo on 19-3-1.
//

#include "Solution_22.h"

vector<string> Solution_22::generateParenthesis(int n) {
    vector<string> getParentheses;
    for(int i=int(pow(2,2*n-1)-1);i<pow(2,2*n)-1;i=i+2){
        stack<char> parentheses;
        string getP(2*n, '_');
        int left = n;
        int right = n;
        int numSig = i;

        int NotThis = 0;
        for(int j=0; j<2*n; j++){
            if(numSig%2==1){
                if(right > 0){
                    parentheses.push(')');
                    getP[2*n-j-1] = ')';
                    right--;
                } else{
                    NotThis = 1;
                    break;
                }

            } else{
                if(left > 0 && !parentheses.empty()){
                    left--;
                    if(parentheses.top()==')'){
                        getP[2*n-j-1] = '(';
                        parentheses.pop();
                    } else{
                        NotThis = 1;
                        break;
                    }
                } else{
                    NotThis = 1;
                    break;
                }
            }
            numSig = int((numSig-1) / 2);
        }
        if(NotThis==1 || !parentheses.empty()){
            continue;
        }else{
            int seen = 0;
            for(int k=0; k<getParentheses.size(); k++){
                if(getP == getParentheses[k]){
                    seen = 1;
                    break;
                }
            }
            if(seen == 0){
                getParentheses.push_back(getP);
            }
        }

//        cout << getP << endl;
//        cout << numSig << ", " << i << endl;

    }
    return getParentheses;
}
