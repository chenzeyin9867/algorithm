#include "head.h"
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        // check the number 'x' == 'o' || 'x' == 'o' + 1
        int x = 0, o = 0;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[i].size(); ++j){
                if(board[i][j] == 'X') ++x;
                else if (board[i][j] == 'O') ++o;
            }
        }
        cout << "o:" << o << "x:" << x << endl;
        if(x != o && x != (o + 1)) return false;
        // check whether exist a row or col or diagonal are all the same of 'x'
        // check each row
        int x_finish = 0;
        int o_finish = 0;
        for(int i = 0; i < 3; ++i){ 
            if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
                if(board[i][0] == 'X') ++x_finish;
                else if(board[i][0] == 'O') ++o_finish;
            }
            // check colom
            if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
                if(board[0][i] == 'X') ++ x_finish;
                else if(board[0][i] == 'O') ++ o_finish;
            }
        }
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            if(board[0][0] == 'X'){
                ++x_finish;
            }else if(board[1][1] == 'O'){
                ++o_finish;
            }
        }

        if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
            if(board[1][1] == 'X') ++x_finish;
            else if(board[1][1] == 'O') ++ o_finish;
        }


        cout << "x_finish:" << x_finish << "o_finish:" << o_finish << endl;

        if(x_finish == 0 && o_finish == 0) return true;
        if(x_finish > 0 && o_finish > 0) return false;
        if(x_finish == 0) {
            // o_finish = 1
            if(x == o) return true;
            return false;
        }
        if(x_finish >= 1){
            return x == (o + 1);
        }



        return false;

    }
};