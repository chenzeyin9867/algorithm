#include "head.h"
class Solution {
public:
    int fib(int n) {
        int a[101] = {0, 1, 1};
        // for(int i = 1; i <10; i++) cout << a[i];
        if(n <= 1) return n;
        for(int i = 2; i <= n ; i++){
            a[i] = (a[i-1] + a[i-2]) % 1000000007;
        }
        return a[n];
        // for( )
    }
};

int t(){
    int a;
    cout <<"a"<<a<<endl;
}
int main(){
    Solution s;
    cout << s.fib(100) << endl;
    // t();
    return 0;
}