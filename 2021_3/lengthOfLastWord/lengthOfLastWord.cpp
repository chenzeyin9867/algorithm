#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool ischar(char c){
        if((c >='a' && c <='z') || (c>='A' && c<='Z')) return true;
        else return false;
    }

    int lengthOfLastWord(string s) {
        string cur = "";
        char last = NULL;
        int curLen = 0;
        int lastLen = 0;
        int i = 0; 
        while(i < s.size()){
            if(s[i]==' ') {
                cur = "";
                if(curLen) lastLen = curLen;
                curLen = 0;
                i++;
                continue;
            }else if(ischar(s[i])){
                curLen ++;
                i++;
            }
        }
        if(curLen) lastLen = curLen;
        return lastLen;
    }
};

int main(){
    Solution s;
    cout << s.lengthOfLastWord(" fuck sda d mom sdsadh sdsa ") << endl;
    return 0;
}