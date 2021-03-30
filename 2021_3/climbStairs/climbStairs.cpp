#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int r[1000];
        if(n == 1) return 1;
        else if(n == 2) return 2;
        int sum = 0;
        r[1] = 1;
        r[2] = 2;
        for(int i = 3; i<= n; i++){
            r[i] = r[i-1] + r[i-2];
        }
        return r[n];
    }
};
int main(){
    Solution s;
    int n;
    cin >> n;
    cout << s.climbStairs(n) << endl;
    return 0;
}