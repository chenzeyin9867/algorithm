#include "head.h"
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++){
            unordered_map<char, int> numCnt;
            for(int j = 0; j < board[0].size(); ++j){
                if(board[i][j] == '.') continue;
                if(numCnt.count(board[i][j])){
                    cout << "fail" << ":" << i << " " << j << endl;
                    return false;
                }
                numCnt[board[i][j]]++;
            }
        }
        cout << "finish 1" << endl;
        for(int i = 0; i < board.size(); i++){
            unordered_map<char, int> numCnt;
            for(int j = 0; j < board[0].size(); ++j){
                if(board[j][i] == '.') continue;
                if(numCnt.count(board[j][i])){
                    return false;
                }
                numCnt[board[j][i]]++;
            }
        }
        cout << "finish col" << endl;

        // check 3x3
        for(int i = 0; i < 3 ; i++){
            for(int j = 0; j < 3; ++j){
                unordered_map<char, int> smallboard;
                for(int m = 0; m < 3; ++m){
                    for(int n = 0; n < 3; ++n){
                        if(board[i*3 + m][j*3 + n] == '.') continue;
                        if(smallboard.count(board[i*3 + m][j*3 + n])){
                            return false;
                        }
                        smallboard[board[i*3 + m][j*3 + n]]++;
                    }
                }
            }
        }
        return true;
    }
};