#include "head.h"
class Solution {
public:
    bool isUgly(int n) {
        if(n == 1) return true;
        if(n <= 0) return false;
        while(n % 2 == 0){
            n = n / 2;
        }
        while(n % 3 == 0){
            n = n / 3;
        }
        while(n % 5 == 0){
            n = n / 5;
        }
        return n == 1;
    }
};

int main(){
    Solution s;
    cout << s.isUgly(15) << endl;
    return 0;
}