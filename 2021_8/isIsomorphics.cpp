#include "head.h"
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> relation;
        map<char, char> charMap;
        set<char> collisionSet;
        if(s.size() != t.size()) return false;
        


        for(int i = 0; i < s.size(); i++){
            char c = s[i];
            if(charMap.count(c)==0){
                charMap[c] = t[i];
                if(collisionSet.find(t[i])!=collisionSet.end()){
                    //already be used this char
                    return false;
                }else{
                    collisionSet.emplace(t[i]);
                }
            }else{
                if(t[i]!=charMap[c])
                return false;
            }
            
        }
        return true;
    }
};

int main(){
    Solution s;
    string str1 = "fooe";
    string str2 = "baaa";
    cout << s.isIsomorphic(str1, str2) << endl;
    return 0;
}

