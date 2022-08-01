#include "head.h"

class Solution {
public:
    string generateTheString(int n) {
        string result;
        if(n == 0) return result;
        for(int i = 0; i < n-1; ++i)
            result.push_back('x');
        if(n % 2 == 0){
            // n-1 'x' and 1 'y'
            result.push_back('y');
        }else{
            result.push_back('x');
        }
        return result;
    }
};