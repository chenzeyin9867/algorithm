#include "head.h"
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int l_x = board.size(), l_y = board[0].size();
        for (int x = 0; x < l_x; ++x)
        {
            for (int y = 0; y < l_y; ++y)
            {
                vector<vector<bool>> visit(l_x, vector<bool>(l_y, false));
                if (dfs_search(board, x, y, word, 0, visit))
                    return true;
            }
        }
        return false;
    }

    bool dfs_search(vector<vector<char>> &board, int x,
                    int y, string &word, int idx, vector<vector<bool>> &visit)
    {
        if (idx == word.size())
        {
            return true;
        }
        if (x < 0 || x >= board.size() || y < 0 || y > board[0].size())
        {
            return false;
        }
        if (visit[x][y] || board[x][y] != word[idx])
        {
            return false;
        }
        /* board[x][y] == word[idx] */
        visit[x][y] = true;
        bool m_exist = dfs_search(board, x + 1, y, word, idx + 1, visit) ||
                       dfs_search(board, x - 1, y, word, idx + 1, visit) ||
                       dfs_search(board, x, y + 1, word, idx + 1, visit) ||
                       dfs_search(board, x, y - 1, word, idx + 1, visit);
        visit[x][y] = false;
        return m_exist;
    }
};