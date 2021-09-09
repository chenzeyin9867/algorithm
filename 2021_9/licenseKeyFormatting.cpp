#include "head.h"
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string charString;
        int cnt = 0;
        for(auto &c: s){
            c = toupper(c);
            if(c == '-') ++cnt;
            else charString.push_back(c);
        } // Trnasform to upper case
        
        int charCnt = s.size() - cnt;
        int firstBlockNum = charCnt % k;
        if(firstBlockNum == 0) firstBlockNum = k;
        int restBlockNum = (charCnt - firstBlockNum) / k;
        string result;
        result.append(charString.substr(0, firstBlockNum));
        for(int i = 0; i < restBlockNum; i++){
            result.append("-" + charString.substr(firstBlockNum+i*k, k));
        }
        return result;
        
        
    }
};