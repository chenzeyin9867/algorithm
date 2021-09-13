#include "head.h"
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int pointNum = points.size();
        if(pointNum <= 1) return 0;
        int numResult = 0;
        for(auto p: points){
            unordered_map<int, int> disMap;
            for(auto q: points){
                disMap[squareDis(p , q)]++;
            }
            for(auto dis: disMap){
                if(dis.second > 1){
                    numResult += dis.second*(dis.second - 1);
                }
            }
            disMap.clear();
        }
        return numResult;
        
    }

    int squareDis(vector<int> px, vector<int> py){
        return (px[0] - py[0]) * (px[0] - py[0]) + (px[1] - py[1]) * (px[1] - py[1]);
    }
};