/**
 * @brief       Looking for the longeset continus substring contains one char
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-01
 */
#include "head.h"
class Solution {
public:
    int maxPower(string s) {
        int max_len = 1;
        int cur_len = 1;
        int i = 1;
        while(i < s.size()){
            if(s[i] == s[i-1]){
                ++cur_len;
            }else{
                cur_len = 1;
            }
            ++i;
            // cur_len = 1;
            max_len = std::max(max_len, cur_len);
        }
        return max_len;
    }
};