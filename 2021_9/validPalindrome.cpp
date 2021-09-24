#include "head.h"
class Solution {
public:
    bool validPalindrome(string s) {
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        if(tmp == s) return true; // no need to delete
        int modify = 0;
        for(int i = 0; i < tmp.size()/2; ++i){
            if(tmp[i] != tmp[tmp.size() -1 - i]){
                // delete i or size() - 1 - i
                // if delete i
                string base = tmp;
                string tmp1 = tmp;
                string tmp2 = tmp;
                tmp1.erase(i, 1);
                string cmp1 = tmp1;
                reverse(tmp1.begin(), tmp1.end());
                tmp2.erase(tmp.size() - 1 - i, 1);
                string cmp2 = tmp2;
                reverse(tmp2.begin(), tmp2.end());
                cout << tmp1 << " " << tmp2 << endl;
                if(tmp1==cmp1 || tmp2 == cmp2) return true;
                return false;
            
            }
        }
        return true;
    }
};