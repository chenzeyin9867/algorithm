#include "head.h"
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int l1 = 0, l2 = 0;
        int len1 = s.size(), len2 = t.size();
        while(l1 < len1 && l2 < len2){
            while(l2 < len2 && t[l2] != s[l1]){
                l2 ++;
            }
            if(l2 < len2){
                l1 ++;
                l2 ++;
            }
        }
        if(l1 < len1) return false;
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isSubsequence("a", "c") << endl;
    return 0;
}