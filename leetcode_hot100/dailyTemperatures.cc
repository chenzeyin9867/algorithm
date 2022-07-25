#include "head.h"
/* Get the greater temperature happens after this day. */
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> stk; // Head of this stack used to store the large number.
        vector<int> result(temperatures.size(), 0);
        stk.push(temperatures.size() - 1);
        for(int i = temperatures.size() - 2; i >= 0; --i){
            while(!stk.empty() && temperatures[stk.top()] <= temperatures[i]){
                stk.pop();
            }
            if(!stk.empty()){
                result[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<int> temp{73,74,75,71,69,72,76,73};
    auto ret = s.dailyTemperatures(temp);
    printVector(ret);
    return 0;
}