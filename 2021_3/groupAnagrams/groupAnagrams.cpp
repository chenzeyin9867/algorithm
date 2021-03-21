#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <algorithm>
using namespace std;
class Solution {
private:
    unordered_map<string, vector<string> > rList; 
public:
    bool myEqual(string &s1, string &s2){
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(int i = 0 ; i < strs.size(); i++){
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            rList[cur].emplace_back(strs[i]);
            
        }
        vector<vector<string>> ans;
        for(auto it = rList.begin(); it != rList.end(); it ++){
            // cout << it->first << endl;
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<string> > ans;
    vector<string>strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    ans = s.groupAnagrams(strs);
    // cout <<"size:" << ans.size() << endl;
    for(int i = 0; i< ans.size(); i++){
        vector<string> r = ans[i];
        for(int j = 0; j < r.size(); j++){
            cout << r[j] << " ";
        }
        cout << endl;
    }
    
}