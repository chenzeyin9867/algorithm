#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dis[201][201];
        dis[0][0] = grid[0][0];
        for(int i = 1; i < grid[0].size(); i++){
            dis[0][i] = dis[0][i-1] + grid[0][i];
        } 
        for(int i = 1; i < grid.size(); i++){
            dis[i][0] = dis[i-1][0] + grid[i][0];
        }           
        for(int i = 1; i< grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                dis[i][j] = min(dis[i-1][j], dis[i][j-1]) + grid[i][j];
            }
        }
        return dis[grid.size()-1][grid[0].size()-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid{{1,2,3}, {4,5,6}};
    cout << s.minPathSum(grid) << endl;
    return 0;
}