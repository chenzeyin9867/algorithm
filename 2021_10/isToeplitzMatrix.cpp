#include "head.h"
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = 0;
        if(h) {
            w = matrix[0].size();
        }
        vector<vector<int>> visit(h, vector<int>(w, 0));
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if((visit[i][j])){
                    continue;
                }
                visit[i][j] = 1;
                int u = i, v = j;
                while(u < h - 1 && v < w - 1){
                    ++u;
                    ++v;
                    if(matrix[u][v] != matrix[i][j]){
                        return false;
                    }
                    visit[u][v] = 1;
                }
            }
        }
        return true;
        
    }
};