class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size() == 0 ) return false;
        // get the last elem
        return dfs(sequence);
    }
    
    bool dfs(vector<int> sequence){
         if(sequence.size() == 0 || sequence.size() == 1) return true;
        // get the last elem
        int m_root = sequence.back();
        // find the first elem greater than it
        int l_start = 0;
        while(sequence[l_start] < m_root){
            ++l_start;
        }
        // check whether [l_start, back -1] all greater than root
        for(int i = l_start; i < sequence.size() - 1; ++i){
            if(sequence[i] < m_root){
                return false;
            }
        }
        
        return dfs(vector<int>(sequence.begin(), sequence.begin() + l_start))
                && dfs(vector<int>(sequence.begin() + l_start, sequence.end() - 1));
        
    }
};