#include "head.h"
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m1;
        unordered_map<int, int> m2;
        for(auto t: nums1){
            m1[t]++;
        }
        for(auto t: nums2){
            m2[t]++;
        }
        vector<int> result;
        if(m1.size() > m2.size()){
            swap(m1,m2);
        }
        for(auto t: m1){
            if(m2[t.first]){
              result.insert(result.end(),min(m1[t.first], m2[t.first]), t.first);
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums1{4,9,5};
    vector<int> nums2{9,4,9,8,4};
    printVector(s.intersect(nums1, nums2));
    return 0;
}