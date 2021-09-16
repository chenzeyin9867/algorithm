#include "head.h"
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int h = mat.size(), w = mat[0].size();
        if(h * w != r * c) return mat;
        vector<vector<int> > result(r, vector<int>(c));
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; ++j){
                int index = i * w + j;
                int row = index / c;
                int col = index % c;
                result[row][col] = mat[i][j];
            }
        }
        return result;
    }
};