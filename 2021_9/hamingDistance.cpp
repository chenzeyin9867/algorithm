#include "head.h"
class Solution {
public:
    int hammingDistance(int x, int y) {
        int r = x ^ y;
        int cnt = 0;
        for(int i = 0; i < 31; i++)
        {
            cnt += r >> i & 0x1;
        }
        return cnt;
        return __builtin_popcount(x^y);
    }
};