#include "head.h"
class Solution {
public:
    vector<string> result;
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> cur;
        generateIpAddresses(s, 4, cur);
        return result;
    }

    void generateIpAddresses(string s, int num, vector<string>& cur){
        if(num == 0 && s.size() == 0){
            string tmp;
            for(int i = 0; i < 4; ++i){
                if(i > 0) tmp.push_back('.');
                tmp.append(cur[i]);
            }
            result.emplace_back(tmp);
            return;
        }         
        if(s.size() < num || (num == 0 && s.size() > 0) || (num * 3 < s.size())) return;

        // if(num == 0 && s.size() > 0) return;

        if(s[0] == '0'){
            cur.emplace_back("0");
            generateIpAddresses(s.substr(1), --num, cur); // only one fork
            cur.pop_back();
        }else{
            string t;
            t.push_back(s[0]);
            cur.emplace_back(t);
            generateIpAddresses(s.substr(1), num - 1, cur);
            cur.pop_back();
            if(s.size() >= 2){
                cur.emplace_back(s.substr(0,2));
                generateIpAddresses(s.substr(2), num - 1, cur);
                cur.pop_back();
            }

            if(s.size() >= 3 && stoi(s.substr(0, 3)) <= 255){
                cur.emplace_back(s.substr(0, 3));
                generateIpAddresses(s.substr(3), num - 1, cur);
                cur.pop_back();
            }  
        }
        
    }
};

int main(){
    Solution s;
    string ip = "010010";
    vector<string> result = s.restoreIpAddresses(ip);
    printVector(result);
    return 0;

}