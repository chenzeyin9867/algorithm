#include "head.h"
class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;
        if(num1.size() > num2.size()) swap(num1, num2); //num1 < num2
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int carry = 0;
        for(int i = 0; i < num1.size(); i++){
            int add = num1[i] - '0' + num2[i] - '0' + carry;
            // cout << add << endl;
            carry = add / 10;
            add = add % 10;
            result += add + '0';
        }
        for(int i = num1.size(); i < num2.size(); i++){
            int add = num2[i] - '0' + carry;
            carry = add / 10;
            add = add % 10;
            result += add + '0';
        }
        if(carry){
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    cout << s.addStrings("19187", "0") << endl;
    return 0;
}