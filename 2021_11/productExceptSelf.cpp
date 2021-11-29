/**
 * @brief       product except self/ note: dont use divide
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-29
 */
#include "head.h"
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> L;
        vector<int> R;
        vector<int> ans;
        L.push_back(1);

        int l_product = 1;
        int r_product = 1;
        R.push_back(1);
        for (int i = 1; i < nums.size(); ++i)
        {    
            l_product = l_product * nums[i - 1];
            L.push_back(l_product);
        }
        for (int i = nums.size() - 2; i >= 0; --i)
        {
            r_product = r_product * nums[i+1];
            R.push_back(r_product);
        }
        reverse(R.begin(), R.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            ans.push_back(L[i] * R[i]);
        }
        return ans;
    }
};