/**
 * @brief       search a target in a col and row ascending order, using z-shape search
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-01
 */
#include "head.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0){
            int cur = matrix[i][j];
            if(cur == target){
                return true;
            }else if(cur > target){
                --j;
            }else{
                ++i;
            }
        }
        return false;
    }
};
int main(){
    
}