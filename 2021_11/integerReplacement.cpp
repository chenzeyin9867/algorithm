#include "head.h"
/**
 * @brief use dynamic programing
 * 
 */
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n % 2 == 0) return 1 + integerReplacement(n / 2);
        else return 2 + min(integerReplacement(n/2), integerReplacement(n / 2 + 1));
    }
};
