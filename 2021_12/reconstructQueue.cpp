/**
 * @brief 
 *  You are given an array of people, people, which are the attributes of some people in a queue (not necessarily in order). Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki other people in front who have a height greater than or equal to hi.
    Reconstruct and return the queue that is represented by the input array people. The returned queue should be formatted as an array queue, where queue[j] = [hj, kj] is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-12-06
 */
#include "head.h"   
struct cmp{
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return p1.first > p2.first; 
    }
};

class Solution {
public:

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        vector<vector<int>> tmp = people; 
        vector<int> visited(people.size(), 0);
        vector<vector<int>> rets;
        int cnt = 0;
        int flag = 1;
        while(1){
            // push all nodes which value==0
            flag = 0;
            for(int i = 0; i < tmp.size(); ++i){
                if(tmp[i][1] == 0 && visited[i] == 0){
                    q.emplace(people[i][0], people[i][1]);
                    visited[i] = 1;
                }
            }
            if(q.empty()) break;
            rets.push_back(vector<int>{q.top().first, q.top().second});
            int val = q.top().first;
            // cout << val << endl;
            q.pop();
            flag = 0;
            for(int i = 0 ; i < tmp.size(); ++i){
                if(val >= tmp[i][0]){
                    --tmp[i][1];
                }
            }
        }

        return rets;
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& u, const vector<int>& v) {
            return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]);
        });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int>& person: people) {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i) {
                if (ans[i].empty()) {
                    --spaces;
                    if (!spaces) {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
