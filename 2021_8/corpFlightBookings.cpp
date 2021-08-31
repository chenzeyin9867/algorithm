#include "head.h"
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flightCnt(n+2);
        for(auto s: bookings){
            int l = s[0];
            int r = s[1];
            int cnt = s[2];
            flightCnt[l]+=cnt;
            flightCnt[r+1] -= cnt; 
        }
        for(int i = 2; i <= n; i++){
            flightCnt[i] += flightCnt[i-1];
        }
        return vector<int>(flightCnt.begin()+1, flightCnt.begin()+n+1);
    }
};