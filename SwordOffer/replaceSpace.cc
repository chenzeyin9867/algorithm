#include "head.h"
/** Replace all the space in s with '%20' inplace or copy. */
class Solution {
public:
    string replaceSpace(string s) {
        // First scan the s and reserve #space in the end of s
        int space_cnt = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' ') ++space_cnt;
        }
        string replace_str = "%20";
        int old_size = s.size();
        // cout << "resize" << endl;
        s.resize(s.size() + 2 * space_cnt);
        // cout << s << endl;
        // cout << "resize failed" << endl;
        int rptr = s.size();
        // cout << s << endl;
        for(int i = old_size - 1; i >= 0; --i){
            // cout << i << "  ";
            // cout << s << endl;
            if(s[i] == ' '){
                rptr -= 3;
                s[rptr] = '%';
                s[rptr+1] = '2';
                s[rptr+2] = '0';
            }else{
                --rptr;
                s[rptr] = s[i];
            }
        }
        // cout << s[0] << endl;
        // cout << "Here" << endl;
        // cout << s << endl;
        string cpy = s;
        return cpy;
    }
};
int main(){
    Solution s;
    string input_str = "We are happy.";
    cout << "Transfer " << input_str << " to: " << s.replaceSpace(input_str) << endl;
    return 0;
}