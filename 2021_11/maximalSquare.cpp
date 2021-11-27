/**
 * @brief       find the maximal square with all 1
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-27
 */
#include "head.h"
class Solution
{
private:
    int max_length_ = 0;

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        max_length_ = 0;
        // int h = matrix.size(), w = matrix[0].size();
        // // 
        // for (int i = 0; i < h; ++i)
        // {
        //     for (int j = 0; j < w; ++j)
        //     {
        //         if(matrix[i][j] == '1'){
        //             int step = 1;
        //             while (isSqaure(matrix, step, i, j))
        //             {
        //                 ++step;
        //             }             
        //             max_length_ = max(max_length_, step - 1);       
        //             cout << "i:" << i << "j:" << j << step - 1 << endl;
        //         }
                

        //     }
        // }
        dp(matrix);
        return max_length_ * max_length_;
    }

    /**
     * @brief whether the  i, j is a square with length 
     */
    bool isSqaure(const vector<vector<char>> &matrix, int length, int i, int j){
        // only have to compute whether row (i + length -1 ) and col  (j + length - 1) is all 1
        int row = i + length - 1;
        int col = j + length - 1;
        if(row >= matrix.size() || col >= matrix[0].size()){
            return false; // out of boundance
        }
        for(int c = j; c <= col; ++c){
            if(matrix[row][c] == '0') return false;
        }
        for(int r = i; r <= row; ++r){
            if(matrix[r][col] == '0') return false;
        }
        return true;
    }

    void dp(vector<vector<char>> &matrix){
        vector<vector<int>> r(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[0].size(); ++j){
                if( i == 0 || j == 0){
                    r[i][j] = matrix[i][j] - '0';
                    max_length_ = max(max_length_, r[i][j]);
                }else{
                    if(matrix[i][j] == '1')
                        r[i][j] = min(r[i-1][j], min(r[i][j-1], r[i-1][j-1])) + 1;
                    max_length_ = max(max_length_, r[i][j]);

                }
            }
        }
    }
};
int main()
{
}