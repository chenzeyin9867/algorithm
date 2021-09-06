#include "head.h"

class Solution {
public:
    int arrangeCoins(int n) {
        long long r = n;
        long long l = 1;
        while(l <= r){
            //二分查找
            long long mid = l + (r-l)/2;
            long long tmp = mid * (mid + 1) /2;
            if(tmp ==(long long ) n){
                return mid;
            }else if(tmp < n){
                l = mid + 1;
            }else {
                r = mid - 1;
            }
        }
        if(r * (r + 1)/2 < n) return r;
        if(l * (l + 1)/2 > n) return l;
        return -1;
    }
};