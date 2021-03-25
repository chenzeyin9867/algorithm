#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        if(intervals.size()==1) return intervals;
        vector<vector<int> > result;
        result.push_back(intervals[0]);
        int right = result.back()[1];
        // cout << right << endl;
        for(int i = 1; i < intervals.size(); i++){
            // cout << i << endl;
            vector<int>cur = intervals[i];
            if(cur[0] <= right){
                if(cur[1]>right){
                    right = cur[1];
                    result.back()[1] = right;
                }
            }else{
                result.push_back(cur);
                right = cur[1];
            }
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int> > result;
    // vector<vector<int> > intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<vector<int> > intervals{{1,5}};
    vector<int> newInterval{2,8};
    // cout << "before func" << endl;
    result = s.insert(intervals, newInterval);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j< result[i].size(); j++){
            cout << result[i][j] ;
        }
        cout << endl;
    }
    return 0;
}