#include "head.h"
/* Looking for the area of the maximal square */
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> squares(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_size = -1;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == '0')
                {
                    squares[i][j] = 0;
                }
                else
                {
                    /* If matrix[i][j] == 1, then classified into some situations */
                    if (i == 0 || j == 0)
                    {
                        squares[i][j] = 1;
                    }
                    else
                    {
                        squares[i][j] = 1 + std::min(squares[i - 1][j],
                                                     std::min(squares[i][j - 1], squares[i - 1][j - 1]));
                    }
                }
                max_size = std::max(max_size, squares[i][j]);
            }
        }
        return max_size * max_size;
    }
};