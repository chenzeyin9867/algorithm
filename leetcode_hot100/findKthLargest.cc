#include "head.h"
/* Look for k'th largest number */
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /* Maitain a min-heap */
        priority_queue<int, vector<int>, greater<int>> large_heap;
        for(int i = 0; i < nums.size(); ++i){
            if(large_heap.size() < k){
                large_heap.push(nums[i]);
            }else{
                /* heap.size() == k */
                if(nums[i] > large_heap.top()){
                    large_heap.pop();
                    large_heap.push(nums[i]);
                }
            }
        }
        int pop_cnt = 0;
        int k_num = -1;
        // while(pop_cnt < k && !large_heap.empty()){
        //     k_num = large_heap.top();
        //     large_heap.pop();
        //     ++pop_cnt;
        // }
        return large_heap.top();
        // return k_num;
    }
};
