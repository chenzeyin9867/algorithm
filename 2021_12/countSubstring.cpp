#include "head.h"
class Solution {
    
public:
    int countSubstrings(string s) {
        vector<vector<int>> substring_list(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); ++i) substring_list[i][i] = 1;
        int cnt = s.size();
        for(int i = 1; i < s.size(); ++i){
            for(int j = 0; j + i < s.size(); ++j){
                int k = i + j;
                if(s[j] != s[k]) continue;
                else{
                    if(i == 1 || i == 2) {
                        ++cnt;
                        substring_list[j][k] = 1;
                    }else{
                        if(substring_list[j+1][k-1] == 1){
                            ++cnt;
                            substring_list[j][k] = 1;
                        }
                    }
                }
            }
        }
        return cnt;

    }
};

