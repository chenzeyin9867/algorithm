#include "head.h"
class Solution
{
public:
    vector<vector<int>> m_result;
    vector<vector<int>> permute(vector<int> &nums)
    {
        recursivePermute(nums, 0);
        return m_result;
    }

    void recursivePermute(vector<int> &nums, int idx)
    {
        if (idx == nums.size())
        {
            m_result.push_back(nums);
            return;
        }
        /* Iterativly swap the idx with index from idx to size() - 1 */
        for (int i = idx; i < nums.size(); ++i)
        {
            /* swap the idx with i */
            std::swap(nums[i], nums[idx]);
            recursivePermute(nums, idx + 1);
            std::swap(nums[i], nums[idx]);
        }
        return;
    }
};

int main()
{
    Solution s;
    vector<int> input{1, 2, 3, 4, 5};
    vector<vector<int>> m_ret = s.permute(input);
    for (auto &line_ : m_ret)
    {
        for (auto &t : line_)
        {
            std::cout << " " << t;
        }
        std::cout << std::endl;
    }
    return 0;
}