#include "head.h"
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */
int pick = 6;
int guess(int num){
    if(num == pick ) return 0;
    if(num > pick) return -1;
    else return 1;
}

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;
        while(l < r){
            long mid = (l+r) / 2;
            // cout << l << " " << mid << " " << r  << endl;

            if(guess(mid) == 0) return mid;
            else if (guess(mid) == 1) {
                // mid < pick
                l = mid + 1;
            }else{ // mid > pick
                r = mid - 1;
            }
        }
        return l;
    }
    // return l;
};

int main(){
    Solution s;
    cout << s.guessNumber(10) << endl;
    return 0;
}