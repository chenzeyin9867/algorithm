
#include <iostream>
using namespace std;
class Solution {
public:
    long long factorial(int m){
        if(m == 1) return m;
        else{
            return m * factorial(m-1);
        }
    }
    int uniquePaths(int m, int n) {
        if(m == 1) return 1;
        if(n == 1) return 1;
        
        if(n > m){
            int tmp = m;
            m = n;
            n = tmp;
        }

        long long molecular = factorial(m + n - 2);
        long long denominator = factorial(n - 1) * factorial(m-1);
        // cout << m << " " << n << endl;
        // cout <<  molecular << " " << denominator << endl;
        return molecular / denominator;
    }
};
int main(){
    Solution s;
    cout << s.uniquePaths(10,10) << endl;
    // cout << 0 << endl;
    return 0;
}