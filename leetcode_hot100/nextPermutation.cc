#include "head.h"
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        if (nums.size() == 1)
            return;
        bool flag = false;
        /* If reverse order, reverse it */
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i - 1])
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        /* start from the last one, find the last reverse pair which (x < y) && (nums[x] < nums[y]) */
        // int r = -1;
        int cur_l, cur_r;
        for (int l = nums.size() - 2; l >= 0; --l)
        {
            for (int r = nums.size() - 1; r > l; --r)
            {
                if (nums[l] < nums[r])
                {
                    cur_l = l, cur_r = r;
                    goto find_flag;
                }
            }
        }

    find_flag:
        /* swap the cur_l and cur_r */
        std::swap(nums[cur_l], nums[cur_r]);
        /* sort the array from cur_l + 1 to the end */
        std::sort(nums.begin() + cur_l + 1, nums.end());
        return;
    }
};

int main()
{
    Solution s;
    vector<int> nums{7, 6, 5, 4, 3, 2, 1, 7, 5, 4, 4, 3, 2};
    s.nextPermutation(nums);
    for (auto &t : nums)
    {
        std::cout << t << std::endl;
    }
    return 0;
}