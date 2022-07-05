#include "head.h"
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> m_dp(n + 10, 0);
        m_dp[0] = 1;
        m_dp[1] = 1;
        m_dp[2] = 2;
        if (n <= 2)
            return m_dp[n];
        for (int node_cnt = 3; node_cnt <= n; ++node_cnt)
        {
            /* node_cnt means total nodes, root_idx means the root's idx */
            for (int root_idx = 0; root_idx < node_cnt; ++root_idx)
            {
                /* ltree has root_idx nodes, while rtree has node_cnt - root_idx - 1 */
                m_dp[node_cnt] += m_dp[root_idx] * m_dp[node_cnt - root_idx - 1];
            }
        }
        return m_dp[n];
    }
};

int main()
{
    Solution s;
    int node_cnt;
    while (cin >> node_cnt)
    {
        std::cout << "total num for " << node_cnt << "node: " << s.numTrees(node_cnt) << endl;
    }
    return 0;
}