#include "head.h"
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int s1 = computeRectangle(ax1, ay1, ax2, ay2);
        int s2 = computeRectangle(bx1, by1, bx2, by2);
        int duplicateArea = 0;
        pair<int, int> duplicateX = make_pair(max(ax1, bx1), min(ax2, bx2));
        if(duplicateX.second <= duplicateX.first) return s1 + s2;
        else{
            int y0 = max(ay1, by1);
            int y1 = min(ay2, by2);
            if(y1 <= y0) return s1 + s2;
            duplicateArea = (y1 - y0) * (duplicateX.second - duplicateX.first);
            
            return s1 + s2 - duplicateArea; 

        }
    }

    int computeRectangle(int a, int b, int x, int y){
        return abs((x - a) * (y - b));
    }
};