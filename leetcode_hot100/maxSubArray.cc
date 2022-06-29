#include "head.h"
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int m_ret = 0;
        if (nums.size() == 0)
            return 0;
        /* m_scores represent the max sum ends with nums[i] */
        vector<int> m_scores(nums.size(), 0);
        m_scores[0] = nums[0];
        m_ret = m_scores[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            m_scores[i] = m_scores[i - 1] > 0 ? m_scores[i - 1] + nums[i] : nums[i];
            m_ret = std::max(m_ret, m_scores[i]);
        }
        return m_ret;
    }
};