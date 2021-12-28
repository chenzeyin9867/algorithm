class Solution {
public:
    vector<vector<char>> can_palce;
    vector<vector<string>> ret;
    int solution = 0;
    vector<vector<string>> solveNQueens(int n) {
        can_palce = vector<vector<char>> (n,vector<char>(n,'.'));
        dfs(0, n);
        cout << "Solution:" << solution << endl;
        return ret;
    }

    void dfs(int row, int n){
        if(row >= n) {
            solution ++;
            parse_result(n);
            return;
        }else{
            // looking for j col that can place in row i
            for(int i = 0; i < n; ++i){
                if(can_palce[row][i] == '.'){
                    // can_palce[row][i] = false;
                    // these col and diag can't place anymore
                    can_palce[row][i] = 'Q';
                    for(int r = row + 1; r < n; ++r){
                        if(can_palce[r][i] == '.')
                            can_palce[r][i] = row - 0 + '0';
                        if(r- row + i < n && can_palce[r][r-row+i] == '.')
                            can_palce[r][r - row + i] = row - 0 + '0';
                        if(i - (r - row) >= 0 && can_palce[r][i-r+row] == '.')
                            can_palce[r][i-r + row] = row - 0 + '0';
                    }
                    dfs(row+1, n);
                    // remove these place
                    can_palce[row][i] = '.';
                    for(int r = row + 1; r < n; ++r){
                        if(can_palce[r][i] == row - 0 + '0')
                            can_palce[r][i] = '.';
                        if(r- row + i < n && can_palce[r][r-row+i] == row - 0 + '0')
                            can_palce[r][r - row + i] = '.';
                        if(i - (r - row) >= 0 && can_palce[r][i-r+row] == row - 0 + '0')
                            can_palce[r][i-r + row] = '.';
                    }
                    
                }
            }
        }
        return;
    }

    void parse_result(int n){
        vector<string> solu;
        for(int i = 0; i < n; ++i){
            string tmp;
            for(int j = 0; j < n; ++j){
                if(can_palce[i][j] == 'Q'){
                    tmp.push_back('Q');
                }else{
                    tmp.push_back('.');
                }
            }
            solu.push_back(tmp);
        }
        ret.push_back(solu);
    }

};