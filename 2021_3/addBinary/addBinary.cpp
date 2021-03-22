#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        string s1, s2;
        if(a.size() > b.size()){
            s1 = a;
            s2 = b;
        }else{
            s2 = a;
            s1 = b;
        }
        if(a == "0") return b;
        if(b == "0") return a;
        string result;
        int flag = 0;
        int i = 0;
        for(; i < s2.size(); i++){
            int cur = (s1[s1.size()-1-i] - '0') + (s2[s2.size()-i-1] - '0') + flag; 
            result.append(1, (cur % 2 + '0'));
            flag = cur / 2;
            // cout << cur << (cur % 2 ) << cur / 2 << endl;
        }
        while(i < s1.size()){
            int cur = s1[s1.size()-i-1] - '0' + flag;
            result.append(1,(cur % 2 + '0'));
            flag = cur / 2;
            i++;
            // cout << cur << endl;
        }
        if(flag) result.append(1, '1');
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution s;
    string s1("110010");
    string s2("100");
    cout << s.addBinary(s1, s2) << endl;
    return 0;
}