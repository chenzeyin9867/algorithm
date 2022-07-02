#include "head.h"
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> m_score(grid);
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (i == 0 && j == 0)
                    continue;
                if (i == 0)
                {
                    m_score[i][j] = m_score[i][j - 1] + grid[i][j];
                }
                else if (j == 0)
                {
                    m_score[i][j] = m_score[i - 1][j] + grid[i][j];
                }
                else
                {
                    m_score[i][j] = std::min(m_score[i - 1][j], m_score[i][j - 1]) + grid[i][j];
                }
            }
        }
        return m_score.back().back();
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> grid {{1,3,1},{1,5,1},{4,2,1}};
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    int score = s.minPathSum(grid);
    std::cout << "score:" << score << std::endl;
    return 0;
}