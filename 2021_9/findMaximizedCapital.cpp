#include "head.h"
struct item{
    int profits;
    int capital;
    int visit;
    item(int p, int c, int v=0): profits(p), capital(c), visit(v){}
    bool operator <(const item &i2){
        return profits >= i2.profits;
    }
};
// bool cmp(item i1, item i2){
//     if(i1.profits == i2.profits) return i1.capital < i2.capital;
//     return i1.profits >= i2.profits;
// }
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        // vector<item> itemList;
        priority_queue<item> itemList;
        for(int i = 0; i < profits.size(); i++){
            itemList.emplace(item(profits[i], capital[i]));
        }
        // sort(itemList.begin(),itemList.end(), cmp);
        // cout << "end sort" << endl;

        int totalProfits = 0;
        int itemCnt = 0;
        int currentMoney = w;
        while(itemCnt <= k){
            // cout << itemCnt << endl;
            int f = 0;
            while(!itemList.empty()){
                item& curItem = itemList.top();
                if(curItem.visit == 0 && curItem.capital <= currentMoney){
                    ++itemCnt;
                    curItem.visit = 1;
                    currentMoney += curItem.profits;
                    totalProfits += curItem.profits;
                    f = 1;
                    break;
                }
                // if(itemCnt >= k ) break;
            }
            
            if(f == 0 || itemCnt == k) break;

        }
        return totalProfits + w;
        
    }
};

typedef pair<int,int> pii;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        int curr = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        vector<pii> arr;

        for (int i = 0; i < n; ++i) {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; ++i) {
            while (curr < n && arr[curr].first <= w) {
                pq.push(arr[curr].second);
                curr++;
            }
            if (!pq.empty()) {
                w += pq.top();
                pq.pop();
            } else {
                break;
            }
        }

        return w;
    }
};



int main(){
    Solution s;
    vector<int> profits{1, 2, 3};
    vector<int> capital{1, 1, 2};
    cout << s.findMaximizedCapital(1, 2, profits, capital) << endl;
    return 0;
    
}