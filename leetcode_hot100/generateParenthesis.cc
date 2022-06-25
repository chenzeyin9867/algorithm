#include "head.h"
class Solution {
public:
    vector<string> m_result;
    vector<string> generateParenthesis(int n) {
        if(n == 0) return m_result;
        string m_tmp;
        recursiveGenerate(0, 0, n, m_tmp);
        return m_result;
    }
    
    void recursiveGenerate(int l, int r, int n, string &m_tmp){
        if(l == n && r == n){
            m_result.push_back(m_tmp);
            return;
        }
        if(l > n) return;
        if(l == r){
            m_tmp.push_back('(');
            recursiveGenerate(l + 1, r, n, m_tmp);
            m_tmp.pop_back();
        }else if(l > r){ /* l > r */
            m_tmp.push_back('(');
            recursiveGenerate(l + 1, r, n, m_tmp);
            m_tmp.pop_back();
            m_tmp.push_back(')');
            recursiveGenerate(l, r + 1, n, m_tmp);
            m_tmp.pop_back();
        }
        return;
    }
};

int main(){
    Solution s;
    int in_s;
    cin >> in_s;
    vector<string> m_result = s.generateParenthesis(in_s);
    for(auto &str : m_result){
        std::cout << str << std::endl;
    }
    
    return 0;
}