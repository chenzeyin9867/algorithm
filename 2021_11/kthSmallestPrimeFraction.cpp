/**
 * @brief       Look for the k'th smalleset num in table
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-29
 */
#include "head.h"
bool pairCmp(pair<int, int> p1, pair<int, int>p2){
    int a = p1.first, b = p1.second;
    int c = p2.first, d = p2.second;
    return a * d < (b * c);
}
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<int, int>> vecs;
        for(int i = 0; i < arr.size() - 1; ++i){
            for(int j = i + 1; j < arr.size(); ++j){
                vecs.emplace_back(make_pair(arr[i], arr[j]));
            }
        }
        sort(vecs.begin(), vecs.end(), pairCmp);
        return {vecs[k-1].first, vecs[k-1].second};
    }
};