#include "head.h"
/*  Judge whether the vector could be splited into two
    parts with same sum */
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // First phase, sum the nums, got the half of the sum
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        int half = sum / 2;

        // Use a 2-dimension array to transfer this problem into
        // a bag one
        vector<vector<int>> bags(nums.size(), vector<int>(half +1, 0));
        
        // bags[i][j] indicates whether nums[0...i] could weight j
        for(int i = 0; i < nums.size(); ++i){
            bags[i][0] = 1;
        }

        for(int i = 0; i < nums.size(); ++i){
            for(int w = 0; w <= half; ++w){
                if(i == 0){
                    if(nums[0] <= half && nums[0] == w){
                        bags[0][w] = 1;
                        break;
                    }
                }else{
                    if(nums[i] <= half){
                        bags[i][w] = (bags[i-1][w]);
                        if(w >= nums[i]){
                            bags[i][w] |= bags[i-1][w-nums[i]];
                        } 
                                    
                    }
                }
            }
        }
        // for(int i = 0; i < nums.size(); ++i){
        //     for(int j = 0; j <= half; ++j){
        //         printf("[%d][%d]:%d ", i, j, bags[i][j]);
        //     }
        //     printf("\n");
        // }
        return bags[nums.size() - 1][half];
    }
};

int main(){
    Solution s;
    vector<int> input{1, 5, 10, 6};
    if(s.canPartition(input)) cout << "could split" << endl;
    else cout << "can't split" << endl;
    return 0;
}