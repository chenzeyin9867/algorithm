#include "head.h"
class Solution {
public:
    int numTrees(int n) {
        vector<int> g(20, 0);
        vector< vector<int>> f(20, vector<int>(20, 0));
        g[0] = 1;
        g[1] = 1;
        g[2] = 2;
        for(int i = 3; i <= n; i++){
            int sum = 0;
            for(int j = 1; j <= i; j++){
                // f(i, j) = epsilo(g(k)*g(i - k));
                f[i][j] = g[j - 1] * g[i - j];
                sum += f[i][j];
            }
            g[i] = sum;
        }
        // int sum = 0;
        // for(int i = 1; i <= n; i++){
            // sum += 
        // }
        return g[n];
    }
};