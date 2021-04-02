#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        if(nums.size() == 1) return;
        if(nums.size() == 0) return;
        for(int i = 1; i < nums.size(); i++){
            int cur = nums[i];
            int prev = i - 1;
            // if(prev >=0 ){
            while(cur < nums[prev]){
                prev --;
                if(prev < 0){
                    break;
                }
            }
            
            prev = prev + 1;
            nums.erase(nums.begin()+i);
            nums.insert(nums.begin() + prev, cur);
        }
        
    }
};
int main(){
    Solution s;
    vector<int> nums{2,0,2,1,1,0};
    s.sortColors(nums);
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}