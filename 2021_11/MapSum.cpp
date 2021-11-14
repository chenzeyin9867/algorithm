#include "head.h"
class MapSum {
public:
    MapSum() {

    }
    
    void insert(string key, int val) {
        strMap[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        for(auto &str: strMap){
            auto ind = (str.first).find(prefix);
            if(ind != string::npos &&  ind == 0){
                // std::cout << str.first << " " << prefix << " " << str.second << endl;
                sum += str.second;
            }
        }
        return sum;
    }

    unordered_map<string, int> strMap;
    // unordered_map<string, int> prefixSumMap;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */