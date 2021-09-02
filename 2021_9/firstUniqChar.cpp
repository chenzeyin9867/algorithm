#include "head.h"
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> cnt;
        for(auto c:s){
            cnt[c]++;
        }
        for(auto c:s){
            if(cnt[c] == 1) return s.find(c);
        }
        return -1;
    }
};

int main(){
    Solution s;
    cout << s.firstUniqChar("loveleetcode") << endl;
    return 0;
}