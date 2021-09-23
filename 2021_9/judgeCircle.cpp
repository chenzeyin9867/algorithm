#include "head.h"
class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0 , h = 0;
        for(auto c: moves){
            switch (c)
            {
            case 'U':
                v++;
                break;
            case 'D':
                --v;
                break;
            case 'L':
                --h;
                break;
            case 'R':
                ++h;
            
            default:
                break;
            }
        }
        return v == 0 && h == 0;
    }
};