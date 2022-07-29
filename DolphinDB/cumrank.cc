#include <iostream>
#include <vector>
#include <set>
using namespace std;
/** 示例：cumrank([1,3,2,3,4]) 返回结果： [0,1,1,2,4] */
/** Author Ze-Yin Chen, Date 2022.7.29 */
vector<int> cumrank(vector<int>& nums){
    // Using set to speed up to nlogn
    vector<int> result;
    multiset<int> num_set;

    for(int i = 0; i < nums.size(); ++i){
        num_set.insert(nums[i]);
        int rank = 0;
        for(auto &n : num_set){
            if(n == nums[i]){
                result.push_back(rank);
                break;
            }
            ++rank;
        }
    }
    return result;
}

int main(){
    // Test
    vector<int> input{1, 3, 2, 3, 4};
    auto ret = cumrank(input);
    for(int x : ret){
    cout << x << " ";
    }
    cout << endl;
    return 0;
}