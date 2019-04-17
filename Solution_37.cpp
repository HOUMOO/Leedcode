//
// Created by houmo on 19-4-10.
//

#include "Solution_37.h"

vector<int> Available(int index, vector<vector<char>> &Matrix){
    vector<int> Availa{1,2,3,4,5,6,7,8,9};
    int beginPointX = ((index%9) / 3) * 3;
    int beginPointY = ((index/9) / 3) * 3;

    for(int i=0; i<9; i++){
        if(Matrix[index/9][i] != '.'){
            Availa[Matrix[index/9][i] - '1'] = 0;
        }
        if(Matrix[i][index%9] != '.'){
            Availa[Matrix[i][index%9] - '1'] = 0;
        }

        if(Matrix[beginPointY+(i/3)][beginPointX+(i%3)] != '.'){
//            cout << Matrix[beginPointY+(i/3)][beginPointX+(i%3)] << endl;
            Availa[Matrix[beginPointY+(i/3)][beginPointX+(i%3)] - '1'] = 0;
        }
    }
    for(int i=0; i<Availa.size(); i++){
        if(Availa[i] == 0){
            Availa.erase(Availa.begin()+i);
            i--;
        }
    }

    return Availa;
}

typedef pair<int, int> PAIR;

struct cmp{
    bool operator()(const PAIR& P1, const PAIR& P2)
    {
        return P1.second < P2.second;
    }
};

void flush(vector<PAIR> &waitForDef, vector<vector<char>> &board, stack<vector<int>> &ChangeOfBoard){
    vector<vector<int> > SpaceOfNotDef;
    vector<int> ChangeB;
    int numberOfSure = 1;

    while(numberOfSure > 0){
        numberOfSure = 0;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    vector<int> space = Available(i*9 + j, board);
                    if(space.size() == 1){
                        board[i][j] = '0' + space[0];
                        ChangeB.push_back(i*9 + j);
                        numberOfSure ++;
                    }
                }
            }
        }
    }
    waitForDef.clear();

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                vector<int> space = Available(i*9 + j, board);
//                SpaceOfNotDef.push_back(space);
                waitForDef.push_back(PAIR(i*9 + j, space.size()));
            }
        }
    }
    sort(waitForDef.begin(), waitForDef.end(), cmp());
    ChangeOfBoard.push(ChangeB);
}

void changePop(stack<vector<int>> &ChangeOfBoard, vector<vector<char>> &board){
    vector<int> ChangeB = ChangeOfBoard.top();
    ChangeOfBoard.pop();

    for(int i=0; i<ChangeB.size(); i++){
//        cout << ChangeB[i] << endl;
        board[ChangeB[i]/9][ChangeB[i]%9] = '.';
    }
}

void Solution_37::solveSudoku(vector<vector<char>> &board) {
    vector<vector<int> > SpaceOfNotDef;

    int numberOfSure = 1;

    while(numberOfSure > 0){
        numberOfSure = 0;

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.'){
                    vector<int> space = Available(i*9 + j, board);
                    if(space.size() == 1){
                        board[i][j] = '0' + space[0];
                        numberOfSure ++;
                    }
                }
            }
        }
    }

    vector<PAIR> waitForDef;

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(board[i][j] == '.'){
                vector<int> space = Available(i*9 + j, board);
//                SpaceOfNotDef.push_back(space);
                waitForDef.push_back(PAIR(i*9 + j, space.size()));
            }
        }
    }
    sort(waitForDef.begin(), waitForDef.end(), cmp());

    stack<int> notDef;
    stack<vector<int>> TakenOfNotDef;
    stack<vector<int>> ChangeOfBoard;
    stack<vector<int>> AvailableStack;

    while(waitForDef.size() != 0){
        int index1 = waitForDef[0].first;
        vector<int> space = Available(index1, board);

        if(space.size() > 0){
            notDef.push(index1);
            TakenOfNotDef.push({space[0]});
            AvailableStack.push(space);
            board[index1/9][index1%9] = '0' + space[0];
            flush(waitForDef, board, ChangeOfBoard);

        }else{

            int backIndex = notDef.top();

            while(TakenOfNotDef.top().size() == AvailableStack.top().size()){
                board[backIndex/9][backIndex%9] = '.';

                TakenOfNotDef.pop();
                AvailableStack.pop();
                changePop(ChangeOfBoard, board);

                notDef.pop();
                backIndex = notDef.top();
            }

            board[backIndex/9][backIndex%9] = '0' + AvailableStack.top()[TakenOfNotDef.top().size()];
            vector<int> temp = TakenOfNotDef.top();
            temp.push_back(AvailableStack.top()[TakenOfNotDef.top().size()]);
            TakenOfNotDef.pop();
            TakenOfNotDef.push(temp);
            changePop(ChangeOfBoard, board);
            flush(waitForDef, board, ChangeOfBoard);
            cout << 1 << endl;
        }

    }

    cout << 1 << endl;

}
