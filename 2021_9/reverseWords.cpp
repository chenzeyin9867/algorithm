#include "head.h"
class Solution {
public:
    string reverseWords(string s) {
        stringstream stringFlow(s);
        string result;
        string tmp;
        while(stringFlow >> tmp){
            reverse(tmp.begin(), tmp.end());
            result.append(tmp + " ");
        }
        result.pop_back();
        return result;
    }
};

int main(){
    Solution s;
    string str{"Let's take LeetCode contest"};
    cout << s.reverseWords(str) << endl;
    return 0;
}