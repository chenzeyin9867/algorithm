#include "head.h"
class Solution {
public:
    bool hasAlternatingBits(int n) {
        if(n <= 1) return true;
        int prev = -1;
        int cur = 0;
        int f = 0;
        while(n){
            if(f){
                prev = cur;
                cur = n % 2;
            }else{
                cur = n % 2;
                prev = cur;
            }
            n /= 2;
            if(f == 1){
                if(cur == prev) return false;
            }
            f = 1;
            // n = n / 2;
        }
        return true;
    }
};