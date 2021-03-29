#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        int dis[101][101] = {0};
        int flag = 0;
        // cout << "1" << endl;
        for(int i = 0; i < height; i++){
            if(obstacleGrid[i][0]==1){
                dis[i][0] = 0;
                flag = 1;
                break;
            }else{
                dis[i][0] = 1;
            }
        }
        // cout << "2 " << endl;
        // cout << "width" << width << endl;
        for(int j = 0; j < width; j++){
            if(obstacleGrid[0][j]==1){
                dis[0][j] = 0;
                flag = 1;
                break;
            }else{
                dis[0][j] = 1;
            }          
        }
        // cout << "here" << endl;
        if(dis[0][0]==0) return 0;
        if((height ==1  || width == 1) && flag == 0) return 1;
        if((height ==1  || width == 1) && flag == 1) return 0;
        for(int i = 1; i < height ; i++){
            for(int j = 1; j < width; j++){
                if(obstacleGrid[i][j]==1){
                    dis[i][j] = 0;
                }else{
                    dis[i][j] = dis[i][j-1] + dis[i-1][j];
                }
            }
        }

        // for(int i = 0; i< height;i++){
        //     for(int j = 0; j< width; j++){
        //         cout << dis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dis[height-1][width-1];

    }
};


int main(){
    Solution s;
    // vector<vector<int > > obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int > > obstacleGrid = {{0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0; 
}