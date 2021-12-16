#include "head.h"
class Solution {
public:

    bool cmp(pair<char, int> p1, pair<char, int> p2){
        return p1.second > p2.second;
    }
    int leastInterval(vector<char>& tasks, int n) {
        pair<char, int> task_list;
        unordered_map<char, int> task_map;
        unordered_map<char, int> left_time;
        for(auto &c : tasks){
            ++task_map[c];
            left_time[c] = 0; // the latest time can handle
        }

        vector<pair<char, int>> wait_list; // <name, num>
        // vector<pair<char, int>> 
        for(auto &kv: task_map){
            wait_list.emplace_back(kv.first, kv.second);
        }

        // sort the list
        std::sort(wait_list.begin(), wait_list.end(), cmp);


        int cur_time = 0;
        while(1){
            int process = 0;
            for(auto it = wait_list.begin(); it != wait_list.end(); ++it){
               if(left_time[it->first] >= cur_time){
                   // can handle
                   left_time[it->first] = cur_time + n + 1;
                   --it->second;
                   ++cur_time;
                   if(it->second == 0){
                       wait_list.erase(it);
                       break;
                   }
               } 
            }
            if(wait_list.empty()) break;
        }
        

    }
};