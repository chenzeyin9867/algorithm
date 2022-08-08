#include "basic_head.h"

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int l = 0, r = 0;
        while(l < pushed.size()){
            if(pushed[l] == popped[r]){
                ++l;
                ++r;
            }else if(!stk.empty() && r < popped.size() && stk.top() == popped[r]){
                ++r;
                stk.pop();
            } else{
                stk.push(pushed[l]);
                ++l;
            }
        }
        
        while(!stk.empty() && r < popped.size() && stk.top() == popped[r]){
            ++r;
            stk.pop();
        }
        return stk.empty();
    }

};