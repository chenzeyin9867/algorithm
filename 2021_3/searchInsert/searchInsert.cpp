#include <vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            nums.push_back(target);
            return 0;
        }
        int i = 0;
        while(nums[i] < target){
            i++;
            if(i == len){
                break;
            }
        
        }
        if(i < len){
            if (nums[i] == target){
                return i;
            }else{
                nums.insert(nums.begin() + i, target);
                
            }
        }else if(i == len){
            nums.push_back(target);
        }
        return i;
    }
};

int main(){
    Solution s ;
    vector<int> nums{1,3,5,6};
    int target = 0;
    std::cout << s.searchInsert(nums, target) << std::endl;
    
}