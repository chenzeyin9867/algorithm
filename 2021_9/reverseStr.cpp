#include "head.h"
class Solution {
public:
    string reverseStr(string s, int k) {
        string &rt = s;
        int i = 0;
        while(i < rt.size()){
            if(i % (2*k) == 0){
                if((i+k) < rt.size()){
                    // reverse from [i, i + k - 1]]
                    reverse(rt.begin()+i, rt.begin() + i + k);
                }else{
                    // reverse from [i, rt.end()]
                    reverse(rt.begin()+i, rt.end());
                }
            }
            i += k;
        }
        return rt;
    }
};