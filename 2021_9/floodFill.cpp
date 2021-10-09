#include "head.h"
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int h = image.size(), w = image[0].size();
        vector<vector<int>> result(h, vector<int>(w));
        dfs(result, sr, sc, newColor, image, image[sr][sc]);
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(result[i][j] == 0){
                    result[i][j] = image[i][j];
                }
            }
        }
        return result;
        
    }

    void dfs(vector<vector<int>> &image, int row, int col, int newColor, vector<vector<int>> &base, int baseColor){
        if(row < 0 || row >= image.size() || col < 0 || col >= image[0].size()) return;
        if(image[row][col] != 0) return;
        if(base[row][col] == baseColor){
            image[row][col] = newColor;
            dfs(image, row-1, col,   newColor, base, baseColor);
            dfs(image, row+1, col,   newColor, base, baseColor);
            dfs(image, row,   col-1, newColor, base, baseColor);
            dfs(image, row,   col+1, newColor, base, baseColor);
        }

        return;
    }
};