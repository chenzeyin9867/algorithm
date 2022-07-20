#include "head.h"
/* Return the number of different bits in x and y */
class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        if (x > y)
        {
            std::swap(x, y);
        }
        int hamin_distance = 0;
        // Makes x the smaller one
        int shift_cnt = 0;
        if ((x & 0x1) != (y & 0x1))
        {
            ++hamin_distance;
        }
        while ((x || y))
        {
            x = x >> 1;
            y = y >> 1;
            if ((x & 0x1) != (y & 0x1))
            {
                ++hamin_distance;
            }
        }
        return hamin_distance;
    }
};