/**
 * @file		findKthLargest.cpp
 * @brief       exercise for heap sort/ and Q-sort / merge-sort
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-26
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */
#include "head.h"
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end(), greater<int>());
        // Qsort(nums, 0, nums.size() - 1);
        // heapSort(nums, nums.size() - 1 );
        MergeSort(nums, 0, nums.size() -1);
        return nums[k-1];
    }

    void Qsort(vector<int>& nums, int start, int end){
        if(start >= end) return;
        int pivot = nums[start];
        int i = start;
        int j = end;
        while(i != j){
            while(j > i && nums[j] >= pivot ){
                --j;
            }
            while(i < j && nums[i] <= pivot){
                ++i;
            }
            if(i < j){
                std::swap(nums[i], nums[j]);
            }
        }
        std::swap(nums[i], nums[start]);
        Qsort(nums, start, i-1);
        Qsort(nums, i+1, end);
    }

    void heapSort(vector<int>&nums, int end){
        // build the heap
        for(int i = end/2; i >= 0; --i){
            adjust(nums, i, end);
        }
        // printVector(nums);
        // take the last one, and readjust
        for(int j = end; j > 0; --j){
            std::swap(nums[0], nums[j]);
            adjust(nums, 0, j - 1);
            // printVector(nums);
        }
        // printVector(nums);
        return;
    }

    void adjust(vector<int>&nums, int i, int end){
        int k = i;
        while(k < end){
            int l = 2 * k + 1;
            int r = 2 * k + 2;
            if(r <= end && nums[r] <= nums[l] && nums[r] < nums[k]){
                std::swap(nums[r], nums[k]);
                k = r;
            }else if(l <= end && nums[l] < nums[k]){
                std::swap(nums[l], nums[k]);
                k = l;
            }else{
                return;
            }
        }
    }

    void MergeSort(vector<int>&nums, int l, int r){
        if(l == r) return;
        if(l + 1 == r && nums[l] < nums[r]) {
            std::swap(nums[l], nums[r]);
            return;
        }
        int mid = l + (r - l) /2;
        MergeSort(nums, l, mid);
        MergeSort(nums, mid+1, r);
        // merge two part
        int i = l, j = mid + 1;
        vector<int> tmp;
        while(i <= mid && j <= r){
            if(nums[i] > nums[j]){
                tmp.push_back(nums[i]);
                ++i;
            }else{
                tmp.push_back(nums[j]);
                ++j;
            }
        }
        while(i <= mid)
        {
            tmp.push_back(nums[i]);
            ++i;
        }
        while(j <= r){
            tmp.push_back(nums[j]);
            ++j;
        }
        std::copy(tmp.begin(), tmp.end(), nums.begin() + l);
        return;
        
    }
    
};

int main(){
    Solution s;
    vector<int> nums{3,2,1,5,6,4};
    s.findKthLargest(nums, 2);
    printVector(nums);
    return 0;
    
}