#include "head.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_map<char, int> m_map;
        int max_length = 1;
        int l = 0, r = 0;
        while(r < s.size()){
            if(m_map.find(s[r]) == m_map.end()){
                m_map[s[r]] = r;
                max_length = std::max (r -l + 1 , max_length);
                ++r; 
            }else{
                int mv_l = m_map[s[r]] + 1;
                for(int i = l; i < mv_l; ++i){
                    m_map.erase(s[i]);
                }
                l = mv_l;
                m_map[s[r]] = r;
                max_length = std::max (r -l + 1 , max_length);
                ++r;
            }
        }
        return max_length;
    }
};

int main(){
    Solution s;
    string str;
    cin >> str;
    std::cout << "ret for str:" << str << " is: " << s.lengthOfLongestSubstring(str) << std::endl;
    return 0;
}