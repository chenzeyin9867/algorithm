#include "head.h"
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        vector<vector<int>> visit(grid.size(), vector<int>(grid[0].size(), 0));
        
        dfs(grid, row, col, visit, grid[row][col]);
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(visit[i][j] == 100){
                    grid[i][j] = color;
                }
                cout << visit[i][j] << " ";
            }
            cout << endl;
        }
        return grid;
    }

    void dfs(vector<vector<int>> &grid, int row, int col, vector<vector<int>>&visit, int color){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()){
            return;
        }
        
        if(visit[row][col] !=0 ){
            return;
        }
        
        visit[row][col] = 1;
        if(grid[row][col] != color) return;
        
        if(isEdge(grid, row, col, color)){
            visit[row][col] = 100;
        }
        dfs(grid, row + 1, col, visit, color);
        dfs(grid, row - 1, col, visit, color);
        dfs(grid, row,     col + 1, visit, color);
        dfs(grid, row,     col - 1, visit, color);
        return;
    }

    bool isEdge(vector<vector<int>> &grid, int row, int col, int color){
        // whether grid[row][col] is a edge element
        if(row - 1 >= 0  && row + 1 < grid.size()  && col - 1 >= 0 && col + 1 < grid[1].size() &&  grid[row-1][col] == color && grid[row+1][col] == color && grid[row][col-1] == color && grid[row][col+1] == color ){
            return false;
        }
        return true;
    
    }
};