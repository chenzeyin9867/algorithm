#include "head.h"
class Solution {
public:
    int superEggDrop(int k, int n) {
        int l = 0, r = n;
        int cnt = 0;
        while(l <= n){
            ++cnt;
            if(l == r) break;
            int mid = l + (r - l) / 2;
            if(mid <= k){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return cnt;
    }
};

int main(){
    Solution s;
    int k = 3, n = 14;
    cout << "cnt:" << s.superEggDrop(k, n);
    return 0;
}