#include "head.h"
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;
        int ptr = 0, n = s.size();
        int cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(i == 0){
                ptr = s[i];
                cnt = 1;
            }else{
                if(s[i] == ptr){
                    ++cnt;
                }else{
                    counts.emplace_back(cnt);
                    cnt = 1;
                    ptr = s[i];
                }
            }
        }
        cout << "end" << endl;
        if(counts.size() <= 1) return 0;
        int sum = 0;
        for(int i = 0; i < counts.size() - 1; ++i){
            sum += std::min(counts[i], counts[i+1]);
        }
        return sum;
    }
};