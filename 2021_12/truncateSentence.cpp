/**
 * @brief       truncate head k strings
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-06
 */
#include "head.h"
class Solution {
public:
    string truncateSentence(string s, int k) {
        int blank_cnt = 0;
        int ind = 0;
        while(ind < s.size()){
            while(ind < s.size() && s[ind] != ' '){
                ++ind;
            }
            if(ind == s.size()) break;
            ++blank_cnt;
            if(blank_cnt == k){
                break;
            }
            ++ind;
        }
        if(ind == s.size()){
            return s;
        }else{
            return s.substr(0, ind); 
        }
    }
};