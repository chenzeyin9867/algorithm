#include "head.h"
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        int f = num >= 0 ? 1 : -1;
        num *= f;
        string result;
        while(num){
            result.push_back(num % 7 + '0');
            num /= 7;
        }
        if(f == -1) result.push_back('-');
        reverse(result.begin(), result.end());
        return result;
    }
};