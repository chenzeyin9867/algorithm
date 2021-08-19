#include <string>
#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};



int main(){
    Solution s;
    string str="race a car";
    string str2 = "A man, a plan, a canal:Panama";
    cout << s.isPalindrome(str2) << endl;

    return 0;
}