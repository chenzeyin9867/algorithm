#include "head.h"
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int sz1 = word1.size();
        int sz2 = word2.size();
        if (sz1 == 0)
            return sz2;
        if (sz2 == 0)
            return sz1;
        vector<vector<int>> m_dp(sz1, vector<int>(sz2, 0));
        if (word1.front() == word2.front())
        {
            m_dp[0][0] = 0;
        }
        else
        {
            m_dp[0][0] = 1;
        }
        for (int i = 0; i < sz1; ++i)
        {
            for (int j = 0; j < sz2; ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                {
                    if (word2[j] == word1[0])
                    {
                        m_dp[i][j] = j;
                    }
                    else
                    {
                        m_dp[i][j] = m_dp[i][j - 1] + 1;
                    }
                }
                else if (j == 0)
                {
                    if (word1[i] == word2[j])
                    {
                        m_dp[i][j] = i;
                    }
                    else
                    {
                        m_dp[i][j] = m_dp[i - 1][j] + 1;
                    }
                }
                else
                {
                    m_dp[i][j] = std::min(std::min(m_dp[i - 1][j] + 1, m_dp[i][j - 1] + 1),
                                          m_dp[i - 1][j - 1] + (word1[i] == word2[j] ? 0 : 1));
                }
            }
        }
        return m_dp[sz1 - 1][sz2 - 1];
    }
};

int main()
{
    Solution s;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int ret = s.minDistance(s1, s2);
    cout << "Modified Distance: " << ret << endl;
    return 0;
}