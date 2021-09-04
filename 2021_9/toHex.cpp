#include "head.h"
char tochar(int n){
    if(n < 10) return n + '0';
    else return 'a'+ n - 10;
}
class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        
        // if(num < 0) n += bias ;
        // printf("%x\n", n);
        string result = "";
        while(n > 15){
            int cur = n % 16;
            n /= 16;
            result += tochar(cur);
            // cout << tochar(cur) << endl;
        }

        result += tochar(n);
        reverse(result.begin(), result.end());
        // cout << result << endl;
        return result;
    }
};

int main(){
    Solution s;
    cout << s.toHex(-1) << endl;
    return 0;
}