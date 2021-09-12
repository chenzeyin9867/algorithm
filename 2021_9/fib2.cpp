#include "head.h"
class Solution {
public:
    int fib(int n) {
        int f[31] = {0, 1};
        
        for(int i = 2; i <= n; i++){
            f[i] = f[i - 1] + f[i-2];
        }
        // if(n == 1 || n == 0) return n;
        // else{
            // int a = fib(n - 1);
            // int b = fib(n - 2);
        return f[n];
        // 
    }
};