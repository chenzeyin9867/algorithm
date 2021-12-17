#include "head.h"
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0;
        // cnt += numBottles;
        while(numBottles > 0){
            int back_num = numBottles / numExchange;
            int left = numBottles > numExchange ? numBottles - back_num * numExchange : 0;
            int drink = numBottles - left;
            
            cnt += drink;
            numBottles = back_num + left;
        }
        return cnt;
    }
};