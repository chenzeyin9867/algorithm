#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf = 1e9;
        int minprice = inf, maxprofit = 0;
        for (int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(price, minprice);
        }
        return maxprofit;
    }
};


int main(){
    vector<int> prices{7,6, 4, 3, 1};
    Solution s;
    cout << s.maxProfit(prices) << endl;
    return 0;
    
}