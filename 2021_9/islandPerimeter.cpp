#include "head.h"
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int edgeCount = 4; // every land got four edges, minus the common edge
        int result = 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[i].size(); ++j){
                if(grid[i][j] == 1){
                    result += edgeCount - CommonEdges(grid, i, j);
                }
            }
        }
        return result;
    }

    int CommonEdges(const vector<vector<int>>& grid, int i, int j) const{
        int cnt = 0;
        if((i - 1) >= 0 && grid[i-1][j] == 1) ++cnt;
        if((j - 1) >= 0 && grid[i][j-1] == 1) ++cnt;
        if((j + 1) < grid[i].size() && grid[i][j+1] == 1) ++cnt;
        if((i + 1) < grid.size()    && grid[i+1][j] == 1) ++cnt;
        return  cnt; 
    }

};