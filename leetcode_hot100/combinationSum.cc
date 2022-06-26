#include "head.h"
class Solution
{
public:
    vector<vector<int>> m_result;
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> m_record;
        recursiveCombination(candidates, m_record, 0, 0, target);
        return m_result;
    }

    /* Recursive generate target using candidates from start */
    void recursiveCombination(vector<int> &candidates, vector<int> &cur_record,
                              int start, int cur, int target)
    {
        if (cur == target)
        {
            m_result.push_back(cur_record);
            return;
        }
        if (cur > target || start == candidates.size())
        {
            return;
        }
        /* Add the candidates[start] from [0, max) into m_record */
        int max_cur_num = (target - cur) / candidates[start];
        for (int i = 0; i <= max_cur_num; ++i)
        {
            if(i > 0)
                cur_record.push_back(candidates[start]);
            int new_cur = i * candidates[start] + cur;
            recursiveCombination(candidates, cur_record, start + 1, new_cur, target);
        }
        /* Pop out all the canditats[start] */
        for (int i = 0; i < max_cur_num; ++i)
        {
            cur_record.pop_back();
        }
        return;
    }
};

int main()
{
    Solution s;
    vector<int> candidates{2, 3, 5, 7};
    vector<vector<int>> m_ret = s.combinationSum(candidates, 8);
    for (auto &v : m_ret)
    {
        for (auto &t : v)
        {
            std::cout << t << "->";
        }
        std::cout << std::endl;
    }
    return 0;
}