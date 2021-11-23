/**
 * @file		buddyStrings.cpp
 * @brief       switch two charcs to match the goal words
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-23
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */
#include "head.h"
class Solution
{
public:
    bool buddyStrings(string s, string goal)
    {
        int cnt = 0;
        if (s.size() != goal.size())
            return false;
        // int first_error = -1, second_error = -1;
        vector<int> ind;
        unordered_set<int> num_set;
        int flag = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if(!flag){
                if(num_set.count(s[i])){
                    flag = 1;
                }else{
                    num_set.insert(s[i]);
                }
            }
            if (s[i] != goal[i])
            {
                ++cnt;
                if (cnt > 2)
                    return false;
                ind.push_back(i);
                
            }
        }
        if (cnt == 1)
            return false;
        if (cnt == 2){
            int firse_ind = ind.front();
            int sec_ind = ind.back();
            return s[firse_ind] == goal[sec_ind] && s[sec_ind] == goal[firse_ind];
        }else {
            // cnt == 0
            return flag == 1;
        }
    }
};