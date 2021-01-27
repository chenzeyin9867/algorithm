//
// Created by 56224 on 2021/1/27.
//
#include <iostream>
#include <set>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int i,j; // left and right pointer
        i = 0;
        j = 0;
        map <char , bool> hashMap;

        int cur_max_len = 0;
        int tmp = 0;
        while(j < len){
            if(hashMap[s[j]] == false){
                tmp ++;
                hashMap[s[j]] = true;
                j++;
            }else{

                int cnt = 0;
                if(tmp > cur_max_len){
                    cur_max_len = tmp;
                }
                while(s[i]!= s[j]){
                    hashMap[s[i]] = false;
                    i++;
                    cnt++;
                    tmp--;
                }
                i++;
                j++;
            }
        }
        if(tmp > cur_max_len){
            cur_max_len = tmp;
        }
        return cur_max_len;

    }
};
int main(){
    Solution s;
    string str = " ";
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}