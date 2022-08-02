#include "basic_head.h"
/** Cutting the rope into x segments, make the multiplication maximal.
 *  We already know that when x >= 4, cut into three segments makes it
 *  maximal. */
class Solution {
public:
    int cuttingRope(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        if(n == 4) return 4;
        vector<int> m{0, 0, 1, 2, 4};
        int product = 1;
        while(n > 3){
            product = product * 3;
            n = n - 3;
            if(n == 4) return product * 4;
        } 
        if(n) product = product * n;
        return product;
    }
};