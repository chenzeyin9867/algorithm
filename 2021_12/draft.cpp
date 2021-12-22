class Solution {
public:
    // vector<vector<int>> visit;
    bool exist(vector<vector<char>>& board, string word) {
        h = board.size();
        w = board[0].size();
        // visit= vector<vector<int>>(h, vector<int>(w, 0));
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                int l = 0;
                bool ret = dfs(board, i, j, word, l);
                if(ret) return true;
            }
        }
        return false;
    }
    int h, w;
    bool dfs(vector<vector<char>> &board, int r, int c, string& word, int l){
        if(l >= word.size()) return true;
        if(r < 0 || r >= h || c < 0 || c >= w) return false;
        // if(visit[r][c]) return false;
        if(word[l] != board[r][c]){
            return false;
        }
        // visit[r][c] = 1;
        // char tmp = board[r][c];
        board[r][c] = '.';
        bool b1 =  dfs(board, r, c+1, word, l+1)
                || dfs(board, r, c-1, word, l+1)
                    || dfs(board, r-1, c, word, l+1)
                    || dfs(board, r+1, c, word, l+1);
        // visit[r][c] = 0;
        board[r][c] = word[l];
        return b1;
    }
};