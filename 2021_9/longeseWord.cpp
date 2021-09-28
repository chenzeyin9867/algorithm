#include "head.h"
bool cmp(const string& s1, const string & s2){
    return s1.size() < s2.size();
}
class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        for(auto &w : words){
            cout << "  " << w;
        }
        cout << endl;
        unordered_set<string> set;
        vector<string> result;
        int maxLen = 0;
        for(auto &w : words){
            if(w.size() == 1) {
                set.insert(w);
                cout << "insert :" << w << endl;
            }
            else{
                cout << "in else:" << w << endl;
                if(set.find(w.substr(0, w.size() - 1)) != set.end()){
                    set.insert(w);
                    cout << "insert :" << w << endl;
                    if(w.size() == maxLen){
                        result.emplace_back(w);
                    }else if(w.size() > maxLen){
                        result.clear();
                        result.emplace_back(w);
                        maxLen = w.size();           
                    }
            }
            }
        }
        for(auto s: result){
            cout << s << endl;
        }

        for(auto s: set){
            cout << " " << s;
        }
        cout << endl;
        sort(result.begin(), result.end());
        return result.size() > 0 ? result[0] : string();
    }
};

int main(){
    Solution s;
    vector<string> dict{"ts","e","x","pbhj","opto","xhigy","erikz","pbh","opt","erikzb","eri","erik","xlye","xhig","optoj","optoje","xly","pb","xhi","x","o"};
    cout << s.longestWord(dict) << endl;
    return 0;
}