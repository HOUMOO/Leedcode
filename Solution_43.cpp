//
// Created by houmo on 5/22/19.
//

#include "Solution_43.h"

vector<int> mult(vector<int> A, int b){
    int carry=0;
    vector<int> answer{};
    for(int i=A.size()-1; i>=0; i--){
        int onebit = carry+(A[i]*b);
        answer.insert(answer.begin(), onebit%10);
        carry = int(onebit/10);
    }
    if(carry != 0){
        answer.insert(answer.begin(), carry);
    }

    return answer;
}



string Solution_43::multiply(string num1, string num2) {
    if(num1 == "0" || num2=="0"){
        return "0";
    }else{
        vector<int> num_1;
        vector<int> num_2;
        string answer = "";

        for(int i=0; i<num1.size(); i++){
            num_1.push_back(num1[i]-'0');
        }
        for(int i=0; i<num2.size(); i++){
            num_2.push_back(num2[i]-'0');
        }

        vector<vector<int>> everyMult;
        for(int i=int(num_2.size()-1); i>=0; i--){
            everyMult.push_back(mult(num_1, num_2[i]));
        }

        int carry=0;

        for(int i=0; i<everyMult.size()+everyMult[everyMult.size()-1].size()-1; i++){
            int onebit=0;
            for(int j=0; j<everyMult.size(); j++){
//                cout << "i:" << i << ", j:" << j << ", second:"<<everyMult[j].size() -1 - (i-j) << endl;
                if(j<=i && everyMult[j].size() > i-j){
                    onebit += everyMult[j][everyMult[j].size() -1 - (i-j)];
                }

            }



            onebit += carry;
            carry = onebit/10;
            int insert = onebit%10;
            answer.insert(answer.begin(), insert+'0');
        }
        if(carry != 0){
            answer.insert(answer.begin(), carry+'0');
        }

        return answer;
    }

}
