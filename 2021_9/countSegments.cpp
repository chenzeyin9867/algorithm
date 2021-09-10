#include "head.h"
class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        int i = 0;
        while(i < s.size()){
            if(s[i]!=' '){
                cnt++;
            }
            while(i < s.size() && s[i]!=' '){
                i++;
            }
            while(i < s.size() && s[i] == ' '){
                i++;
            }
        }
        return cnt;
    }
};