#include "head.h"
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> numMap;
        int maxLen = 0;
        for(auto n: nums){
            ++numMap[n];
        }

        // cout << "*******" << endl;
        for(auto m: numMap){
            // cout << m.first << " " << m.first + 1 << " " <<  numMap.count(m.first+1) << " " << m.second << " "  << maxLen << endl;
            if(numMap.count(m.first+1)){
                maxLen = (numMap[m.first+1] + m.second) > maxLen ? (numMap[m.first+1] + m.second) : maxLen;
            }
            
        }
        return maxLen;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,3,2,2,5,2,3,7};
    cout << s.findLHS(nums) << endl;
    return 0;
}