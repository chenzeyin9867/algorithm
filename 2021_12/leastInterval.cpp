#include "head.h"
bool cmp(pair<char, int> p1, pair<char, int> p2)
{
    return p1.second > p2.second;
}
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        pair<char, int> task_list;
        unordered_map<char, int> task_map;
        unordered_map<char, int> left_time;
        int task_cnt = tasks.size();
        for (auto &c : tasks)
        {
            ++task_map[c];
            left_time[c] = 0; // the latest time can handle
        }

        vector<pair<char, int>> wait_list; // <name, num>
        // vector<pair<char, int>>
        for (auto &kv : task_map)
        {
            wait_list.emplace_back(kv.first, kv.second);
        }

        // sort the list
        std::sort(wait_list.begin(), wait_list.end(), cmp);

        int cur_time = 0; // task time
        while (task_cnt > 0)
        { // end when all the task finish
            int process = 0;
            for (auto it = wait_list.begin(); it != wait_list.end(); ++it)
            {
                if (left_time[it->first] <= cur_time)
                {
                    // can handle
                    left_time[it->first] = cur_time + n + 1;
                    --it->second;
                    ++cur_time;
                    if (it->second == 0)
                    {
                        wait_list.erase(it);
                        // break;
                    }
                    process = 1;
                    break;
                }
            }
            if(process == 0){
                ++cur_time;
                continue;
            }
            std::sort(wait_list.begin(), wait_list.end(), cmp);
            --task_cnt;
            if (wait_list.empty())
                break;
        }
        return cur_time;
    }
};