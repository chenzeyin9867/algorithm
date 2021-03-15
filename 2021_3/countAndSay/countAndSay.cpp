#include <iostream>
// #include <cstring>
#include <string>
using namespace std;
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string r = countAndSay(n - 1);
        // cout <<n << " " <<  r << endl;
        int sLen = r.size();
        int cur = r[0] - '0';
        int cnt = 0;
        string result = "";
        for(int i = 0; i < sLen; i++){
            int tmp = r[i] - '0';
            if(tmp == cur){
                cnt ++;
            }else{
                result += to_string(cnt);
                result += to_string(cur);
                cur = tmp;
                cnt = 1;
            }

            if(i == sLen - 1){
                result += to_string(cnt);
                result += to_string(cur);

            }
 
        }
        // cout << result << endl;
        return result;
    }
};

int main(){
    Solution s;
    cout << s.countAndSay(5) << endl;

}