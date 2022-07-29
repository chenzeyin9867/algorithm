/**  Author Ze-Yin Chen, Date 2022.7.29
    3、一个长度未知的巨型向量分布在 n 台机器上，如何快速找到(近似)中位数？
*/
#include <iostream>
#include <vector>
using namespace std;

template <class T>
T median(vector<T>& nums){
    int mid = nums.size() / 2;
    if(nums.size() % 2 == 1) return nums[mid];
    return (nums[mid] + nums[mid-1]) / static_cast<T>(2);
}

/** Quick Sort Function. */
template <class T>
void quickSort(vector<T>& nums, int start, int end){
    if(start >= end) return;
    T pivot = nums[start];
    int l = start;
    int r = end;
    while(l < r){
        while(r > l && nums[r] > pivot){
            --r;
        }
        if(l < r){
            nums[l++] = nums[r];
        }
        while(l < r && nums[l] < pivot){
            ++l;
        }
        if(l < r){
            nums[r--] = nums[l];
        }
    }

    nums[l] = pivot;
    quickSort(nums, start, l-1);
    quickSort(nums, l+1, end);
}

/* Function to get the median of a huge vector distributed in n files */
template <class T>
T findMedian(vector<vector<T> > &nums){
    /** step1: sort each vector, get its temp median, r used to store these medians */
    vector<T> r;
    for(auto& vec: nums){
        quickSort(vec, 0, vec.size() - 1);
        r.push_back(median(vec));
    }

    quickSort(r, 0, r.size() - 1);
    return median(r);
}

/** Test */
int main(){
    vector<vector<int>> input_base{{4, 2, 5, 6}};
    cout << "median for test1 " << findMedian(input_base) << endl; 
    vector<vector<int>> input_int{{1, 3, 5}, {2, 4, 6}, {3, 7, 8}};
    cout << "median for test2 " << findMedian(input_int) << endl;  
    vector<vector<double>> input_double {{2.1, 3.4, 5.8, 5.5}};
    cout << "median for test3 " << findMedian(input_double) << endl; 
    return 0;
}

