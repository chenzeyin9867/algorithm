class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        if(pushed.empty() && popped.empty()) return true;
        if(pushed.empty() || popped.empty()) return false;
        int i = 0, j = 0;
        while(i < pushed.size() && j < popped.size()){
            if(pushed[i] == popped[j]){
                ++i;
                ++j;
            }else{
                if(!stk.empty() && stk.top() == popped[j]){
                    ++j;
                    stk.pop();
                }else{
                    // push until popped[j]
                    while(i < pushed.size() && pushed[i] != popped[j]){
                        
                        stk.push(pushed[i]);
                        ++i;
                    }
                }
            }
        }

        while(!stk.empty()){
            // cout << "pop:" << stk.top() << endl;
            if(stk.top() != popped[j]){
                return false;
            }
            stk.pop();
            ++j;
        }
        return true;

    }
};