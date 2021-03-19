#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int numsList[100000];
        if(nums.size() == 0) return vector<int>{-1,-1};
        // memcpy(numsList, &nums[0], nums.size() * sizeof(int*));
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        if(len == 1 && nums[0] != target){
            return vector<int>{-1,-1};
        }else if (len == 1 && nums[0] == target){
            return vector<int>{0,0};
        }
        int pos = -1;
        while(left <= right){
            // cout << left << " " << right << endl;
            int mid = (left + right) / 2;
            int midNum = nums[mid];
            if(midNum == target){
                pos = mid;
                break;
            }
            if(midNum < target){
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if (pos == -1){
            return vector<int>{-1,-1};
        }
        // cout << "pos:" << pos << endl;
        int left_p = pos;
        int right_p = pos;
        while (left_p >= 0){
            if(nums[left_p] == target){
                left_p --;
            }else{
                break;
            }
        }
        while (right_p < len){
            if(nums[right_p] == target){
                right_p ++;
            }else{
                break;
            }
        }
        if(left_p < pos) left_p++;
        if(right_p > pos) right_p--;
        return vector<int>{left_p, right_p};
    }
};

int main(){
    Solution s;
    vector<int> nums{1,4};
    int target = 1;
    cin >> target;
    vector<int> r = s.searchRange(nums, target);
    cout << "[ " ; 
    for (int i = 0; i < r.size(); i++){
        cout << r[i] << " "; 
    }
    cout << " ]" << endl;
    return 0;
}