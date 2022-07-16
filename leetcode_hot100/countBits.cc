#include "head.h"
/* count the 1-bit from [1,n] */
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1, 0);
        bits[0] = 0;
        int bit_cnt = 0;
        for(int i = 1; i <= n; ++i){
            // count the all bit of the num
            if(i == (1 << (bit_cnt+1))){ // e.g 2, 4, 8, 16
                bits[i] = 1;
                ++bit_cnt;
            }else{
                bits[i] = bits[i - (1 << (bit_cnt))] + 1;
            }
        }
        return bits;
    }
};