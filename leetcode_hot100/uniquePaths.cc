#include "head.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> m_paths(m, vector<int> (n, 0));
        for(int i = 0; i < n; ++i){
            m_paths[0][i] = 1;
        }
        for(int i = 0; i < m; ++i){
            m_paths[i][0] = 1;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                m_paths[i][j] = m_paths[i-1][j] + m_paths[i][j-1];
            }
        }
        return m_paths[m-1][n-1];
    }
};

int main(){
    Solution s;
    int m_ret = s.uniquePaths(3, 2);
    std::cout << "Path count :" << m_ret << std::endl;
    return 0;
}