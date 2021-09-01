#include "head.h"
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0;
        int r = num;
        // for(int i = 0; i< 15; i++){
        //     r*=2;
        //     // cout << r << endl;
        // }
        // cout << r * r << endl;; 
        // if(num * num == l || num  == r * r) return true;
        while( l <= r){
            long mid = l + (r - l) / 2;
            cout << l << " " << r << " " << mid << endl;
            long s = mid * mid;
            if(s == num) return true;
            else if(s < num){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isPerfectSquare(1) << endl;
    return 0;
}