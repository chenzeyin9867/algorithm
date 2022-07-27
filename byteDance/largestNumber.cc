#include "head.h"
/* Cmp func base on whether a:b > b:a */
bool cmp(string& p1, string& p2){
    return p1 + p2 > p2 + p1;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_vec;
        for(auto &n : nums){
            str_vec.push_back(std::move(to_string(n)));
        }
        std::sort(str_vec.begin(), str_vec.end(), cmp);
        string result;
        for(auto &s : str_vec){
            if(s == "0" && result.empty()) continue;
            result.append(s);
        }
        if(result.empty()){
            result = "0";
        }
        return result;
    }
};