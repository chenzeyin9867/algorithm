#include "head.h"
bool cmp(vector<int> &p1, vector<int> &p2)
{
    return p1.front() < p2.front();
}
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> m_result;
        vector<int> tmp = intervals.front();
        for (int i = 1; i < intervals.size(); ++i)
        {
            int l = intervals[i].front(), r = intervals[i].back();
            if (l <= tmp.back())
            {
                tmp[1] = std::max(tmp[1], r);
            }
            else
            {
                m_result.push_back(tmp);
                tmp = intervals[i];
            }
        }
        m_result.push_back(tmp);
        return m_result;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> input = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> input = {{1, 4}, {4, 5}};
    auto ret = s.merge(input);
    for (auto &v_ : ret)
    {
        for (auto &t : v_)
        {
            std::cout << t << " ";
        }
        std::cout << std::endl;
    }
}