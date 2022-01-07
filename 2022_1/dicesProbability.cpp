class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> m_prob(n + 1, vector<double>(6 * n + 1, 0.0));
        for(int i = 1; i <= 6; ++i){
            m_prob[1][i] = 1.0 / 6.0;
        }

        for(int i = 2; i <= n; ++i){ // the i'th dices
            for(int j = i - 1; j <= 6 * (i - 1); ++j) { // previs dices's prob
                for(int k = 1; k <= 6; ++k){ // current dices's prob
                    m_prob[i][j + k] += 1.0 / 6.0 * m_prob[i-1][j];
                }
            }
        }
        return vector<double>(m_prob[n].begin() + n, m_prob[n].end());
        
    }
};