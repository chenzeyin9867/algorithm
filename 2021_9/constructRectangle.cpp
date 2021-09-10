#include "head.h"
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = 1;
        int l = 1;
        for(int i = sqrt(area); i >= 1; --i){
            if(area % i == 0){
                w = i;
                l = area / w;
                break;
            }
        }

        return vector<int>{l, w};

    }
};