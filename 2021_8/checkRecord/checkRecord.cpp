#include <iostream>
using namespace std;
#include <string>
class Solution {
public:
    bool checkRecord(string s) {
        if (s.length() < 2){
            return true;
        }
        if (s.length() == 2 )
         if(!(s[0]== 'A' && s[1] == 'A' )){
            return true;
        }else{
            return false;
        }
        // length >= 3
        int absent = 0;
        int continue_late_cnt = 0;
        if(s[0] == 'A') absent ++;
        else if (s[0] == 'L') continue_late_cnt ++;
        for ( int i = 1; i < s.length(); i++){
            if (s[i] == 'A'){
                ++absent;
                continue_late_cnt = 0;
                if(absent >= 2){
                    return false;
                }
            }else if(s[i] == 'L'){
                continue_late_cnt ++;
                if(continue_late_cnt >= 3 ){
                    return false;
                }
            }else{
                // P
                continue_late_cnt = 0;
            }
        }
        return true;
        
    }
};
int main(){
    string s = "ALL";
    Solution S;
    string a = S.checkRecord(s) == true? "true" : "false";
    cout << a << endl;
    return 0;
}