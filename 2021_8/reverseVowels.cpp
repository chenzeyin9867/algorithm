#include "head.h"

class Solution {
public:
    string reverseVowels(string s) {
        int l = 0;
        int r = s.size()-1;
        set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        while(l < r){
            while(vowel.find(s[l])==vowel.end() && l < r){
                l++;
            }
            while(vowel.find(s[r])==vowel.end() && l < r)
            {
                r--;
            }
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            l++;
            r--;
            // swap(s[l], s[r]);
        }     
        return s;   
    }
};

int main(){
    Solution s;
    string str = "leetcode";
    cout << s.reverseVowels(str) << endl;
    return 0;
}