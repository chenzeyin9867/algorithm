#include "head.h"
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> m_ways(n + 1, 0);
        if (n <= 2)
        {
            return n;
        }
        m_ways[1] = 1;
        m_ways[2] = 2;
        for (int i = 3; i <= n; ++i)
        {
            m_ways[i] = m_ways[i - 1] + m_ways[i - 2];
        }
        return m_ways[n];
    }
};

int main()
{
    Solution s;
    int m_stair;
    cin >> m_stair;
    int ret = s.climbStairs(m_stair);
    cout << "v:" << ret << endl;
    return 0;
}