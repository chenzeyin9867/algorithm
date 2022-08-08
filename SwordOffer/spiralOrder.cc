#include "basic_head.h"
/** Print the matirx in spiralOrder */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return vector<int>();
        int left = 0, right = matrix[0].size() - 1;
        int up = 0, down = matrix.size() - 1;
        vector<int> result;
        
        while(left <= right && up <= down){
            int x = up, y = left;
            if(left == right && up == down){
                result.push_back(matrix[x][y]);
                break;
            }
            while(y < right){
                result.push_back(matrix[x][y]);
                // cout << matrix[x][y] << endl;
                ++y;
            }
            // Move Down
            while(x < down){
                result.push_back(matrix[x][y]);
                // cout << matrix[x][y] << endl;
                ++x;
            }
            // Move left
            if(right > left){
                while(y > left){
                    result.push_back(matrix[x][y]);
                    // cout << matrix[x][y] << endl;
                    --y;
                }
            }
            // Move up
            if(down > up){
                while(x > up){
                    result.push_back(matrix[x][y]);
                    // cout << matrix[x][y] << endl;
                    --x;
                }
            }
            ++left;
            --right;
            ++up;
            --down;
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> input{{1,2,3}, {4, 5, 6}, {7, 8, 9}};
    auto ret = s.spiralOrder(input);
    printVector(ret);
    return 0;
}