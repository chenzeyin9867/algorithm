#include "head.h"
/* Remove Least Number Of () To Make It A Legal One */
class Solution {
public:
    vector<string> m_ret_;
    int len = 0;
    vector<string> removeInvalidParentheses(string s) {
        /* Use DFS, for each () delete or not */
        string tmp("");
        stack <char> stk;
        dfs(s, 0, tmp, stk);
        return m_ret_;
    }

    /* idx represents the idx in s */
    void dfs(string &s, int idx, string &tmp, stack<char> &stk){
        if(idx == s.size()){
            // cout << "here1" << endl;
            if(stk.empty()){ // This is a legal string
                // cout << "here" << endl;
                if(tmp.size() < len) return;
                if(tmp.size() > len){
                    // std::cout << "tmp:" << tmp << " len:" << len << " size(): " << tmp.size() <<endl;
                    len = tmp.size();
                    m_ret_.clear();
                    // len = tmp.size();
                }
                // if(tmp.size() == 0)
                if(find(m_ret_.begin(), m_ret_.end(), tmp) == m_ret_.end())
                    m_ret_.push_back(tmp);
            }
            return;
        }
        
        if(s[idx] != '(' && s[idx] != ')'){
            tmp.push_back(s[idx]); // normal char
            dfs(s, idx + 1, tmp, stk);
            tmp.pop_back();
            return;
        }else {
            /* Not delete s[idx] */
            if(s[idx] == ')'){
                if(stk.empty() || stk.top() != '('){
                    // return; /* not legal */
                    goto F_delete;
                }
                stk.pop();
            }else{
                /* '(' */
                stk.push(s[idx]);
            }
            tmp.push_back(s[idx]);
            dfs(s, idx + 1, tmp, stk);
            /* return, process the tmp and stk */
            tmp.pop_back();
            if(s[idx] == '('){
                stk.pop();
            }else {
                stk.push('(');
            }
    F_delete:
            /* Delete s[idx] */
            dfs(s, idx + 1, tmp, stk);
            return;
        }
    }
};

int main(){
    Solution s;
    auto ret = s.removeInvalidParentheses("(a)())()");
    cout << "len of result: " << ret.size() << endl;
    printVector(ret);
    return 0;
}