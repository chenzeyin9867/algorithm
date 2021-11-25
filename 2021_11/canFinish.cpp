/**
 * @file		canFinish.cpp
 * @brief       Diag Graph problem, check whether exist a circle
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-25
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */
#include "head.h"
class GNode{
public:
    GNode(int v): val_(v) {};
    int val_;
    vector<int> next_;
    vector<int> prev_;
    
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<GNode*> node_list(numCourses, new GNode(0));
        unordered_map<int, GNode*> node_map;
        for(int i = 0; i < numCourses; ++i){
            node_map.insert(make_pair(i, new GNode(i)));
        }

        /**
         * @brief Create a graph
         */
        for(auto &l : prerequisites){
            int cur = l[0];
            int prev = l[1];
            node_map[cur]->prev_.push_back(prev);
            node_map[prev]->next_.push_back(cur);
        }
        
        while(!node_map.empty()){
            int f = 0;
            for(auto &node: node_map){
                if(node.second->prev_.empty()){
                    cout << node.first << endl;
                    for(int p: node.second->next_){
                        GNode* next_node = node_map[p];
                        cout << "remove:" << node.first << endl;
                        next_node->prev_.erase(find(next_node->prev_.begin(), next_node->prev_.end(), node.first));
                    }
                    // delete this node from node_map
                    node_map.erase(node_map.find(node.first));
                    f = 1;
                    break;
                }
            }
            if(f == 0) return false;
        }

        return true;
    }
};

int main(){
    Solution s;
    vector<vector<int>> nums{{1, 0}};
    bool ret = s.canFinish(2, nums);
    cout << ret << endl;
    return 0;
}