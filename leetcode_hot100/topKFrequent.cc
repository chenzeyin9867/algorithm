#include "head.h"
typedef struct node{
    int idx;
    int cnt;
    node(int id, int ct): idx(id), cnt(ct){
        
    }
}node;


bool operator< (node n1, node n2){
    return n1.cnt < n2.cnt;
}
    

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt_map;
        for(auto &t : nums){
            ++cnt_map[t];
        }
        vector<node> vec;
        // for(auto & p: cnt_map){
        //     vec.push_back()
        // }
        priority_queue<node, vector<node>> q;
        for(auto &p : cnt_map){
            q.push(node(p.first, p.second));
        }
        vector<int> result;
        for(int i = 0; i < k; ++i){
            if(!q.empty()){
                result.push_back(q.top().idx);
                q.pop();
            }
        }
        return result;
    }
};