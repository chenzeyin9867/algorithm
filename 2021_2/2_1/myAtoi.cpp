#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        int pt = 0; // the pointer
        int flag = 1;
        while(s[pt] == ' '){
            pt++;
        }
        if(s[pt] == '-' || s[pt] =='+'){
            flag = s[pt] == '-'  ? -1 : 1;
            pt++;
        }
        int rt = 0;
        while(s[pt] >= '0' && s[pt] <= '9' && pt < len){
            int cur = s[pt] - '0';
            if(rt > (INT_MAX - cur)/10 ) {
                if(flag == 1)
                    return INT_MAX;
                else return INT_MIN;
            }
            rt = rt * 10 + cur;
            pt++;
            
        }
        return flag * rt;
    
    }
};
int main(){
    Solution s;
    string str;
    while(1){
        getline(cin, str);
        // cout << str << endl;
        cout << s.myAtoi(str)<< endl;
    }
    // int r = s.myAtoi("123324134");
    // cout << r << endl;
    return 0;
}