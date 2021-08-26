#include "head.h"
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1) return false;
        if (n == 1) return true;
        while(true){
            int div = n / 2;
            int lef = n % 2;
            if(lef != 0) return false;
            if(div == 1) return true;
            n = n / 2;
        }
    }
};

int main(){
    Solution s;
    cout << s.isPowerOfTwo(1024) << endl;
    return 0;
}