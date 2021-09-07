#include "head.h"
bool cmp(int a, int b){
    return a > b;
}
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), cmp);
        sort(s.begin(), s.end(), cmp);
        int l = 0, t = 0;
        int cnt = 0;
        while(l < s.size() && t < g.size()){
            if(s[l] >= g[t]){
                cnt++;
                l++;
            }
            t++;
        }
        return cnt;
    }
    
};