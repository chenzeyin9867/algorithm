
#include <iostream>
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int i = 1;
        if(x == 0) return 0;
        // cout << x << endl;
        while(i < (int)(x / i)){
            i++;
            // cout << i << endl;
        }
        if(i  == (x / i) ){
            // cout << "here" << i << endl;
            return i;
        }else{
            return i-1;
        }
    }
};

int main(){
    Solution s;
    int num;
    while(1){
        cin >> num;
        cout << s.mySqrt(num) << endl;
    }
}