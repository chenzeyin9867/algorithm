#include "head.h"
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        // if(turnedOn == 0) return 
        vector<vector<int>> numIndex;
        vector<string> result;
        if(turnedOn == 0) return vector<string>{"0:00"};
        if(turnedOn >= 9) return result;
        vector<int> tmp;
        recursive_load(turnedOn, 0, tmp, result);

        return result;
    }

    void recursive_load(int num, int start, vector<int> &cur, vector<string> &result){
        if(num == 0 && !cur.empty()){
            // load finish, update the result according to the index
            int hour = 0;
            int min = 0;
            for(auto t:cur){
                if(t < 4){
                    hour+= hourMap[t];
                }else{
                    min += minMap[t-4];
                }

            }
            if(hour >= 12) return;
            if(min > 59) return;
            string ans="";
            ans += to_string(hour);
            ans += ":";
            if(min < 10) ans+='0';
            ans += to_string(min);
            result.emplace_back(ans);
            return ;
        }
        if(10 - start < num) return; // prune
        
        //whether choose current node
        cur.emplace_back(start);
        recursive_load(num-1, start+1, cur, result);
        cur.pop_back();
        recursive_load(num, start+1, cur, result);
        return ;
        
    }

    vector<int> hourMap {1, 2, 4, 8};
    vector<int> minMap {1,2,4,8,16,32};
    
};

int main(){
    
    Solution s;
    vector<string> result = s.readBinaryWatch(2);
    sort(result.begin(), result.end());
    printVector(result);
    return 0;

    
}