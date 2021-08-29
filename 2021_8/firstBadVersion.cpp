#include "head.h"
class Solution {
public:
    int firstBadVersion(int n) {
        if(isBadVersion(1)) return 1;
        long long l = 1;
        long long r = n;
        int mid;
        while(l <= n){
            mid = (l + r)/ 2;
            if(isBadVersion(mid)){
                if(!isBadVersion(mid-1)) return mid;
                r = mid - 1;
            }else{
                if(isBadVersion(mid+1)) return mid+1;
                l = mid + 1;
            }
        }
        return mid;
        
    }


    // bool isBadVersion(int i){
    //     return true;
    // }
};