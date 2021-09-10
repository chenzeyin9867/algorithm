#include "head.h"
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int index = -1;
        for(int i = 0; i < nums1.size(); ++i){
            index = -1;
            int f = 0;
            for(int j = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin() + 1; j < nums2.size(); ++j){
                if(nums2[j] > nums1[i]){
                    index = nums2[j];
                    break;
                }
            }
            result.emplace_back(index);
        }
        return result;
    }
};