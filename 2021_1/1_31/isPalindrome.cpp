#include <iostream>
using namespace std;
#include<string>
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        if(s[0] == '-'){
            return false;
        }else{
            for(int i = 0 ; i < s.size() / 2; i++){
                if(s[i] != s[s.size() - 1 - i]){
                    return false;
                }
            }
            return true;
            
        }
    }
};


int main(){
    Solution s;
    int r;
    while(1)
    {
    std::cin >> r;
    std::cout << s.isPalindrome(r) << endl;
    }
    return 0;
}