#include "head.h"
class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        for(int i = left; i <= right; ++i){
            if(isSelfDividingNumber(i)) result.push_back(i);
        }
        return result;
    }

    bool isSelfDividingNumber(int x){
        int tmp = x;
        while(tmp){
            int left = tmp % 10;
            if(left == 0) return false;
            if(x % left !=0 ) return false;
            tmp /= 10;
        }
        return true;
    }
};