/**
 * @file		numIslands.cpp
 * @brief       compute the number of unicom islands
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-24
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */
#include "head.h"
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size(), w = grid[0].size();
        vector<vector<int>> visited(h, vector<int>(w, 0));  // whether this grid has been visited
        int num_islands = 0;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                if(grid[i][j] == '1' && visited[i][j] == 0){
                    // cout << "i: " << i << " j:" << j << endl;
                    ++num_islands;
                    dfs(grid, visited, i, j);
                }
            }
        }  
        return num_islands;
    }

    void dfs(const vector<vector<char>> &grid, vector<vector<int>>& visited, int i, int j){
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()){
            return;
        }
        if(visited[i][j] == 1 || grid[i][j] == '0') return;
        // if(grid[i][j] == 0) return;
        visited[i][j] = 1;
        dfs(grid, visited, i, j - 1);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i + 1, j);
    }
};