/**
 * @file		sortList.cpp
 * @brief       Using additional O(n) space to store the Node*
 * @version     0.1
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-21
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */


#include "head.h"
bool cmp(ListNode* n1, ListNode *n2){
    return n1->val < n2->val;
}
class Solution {
friend bool cmp(ListNode*, ListNode*);
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        ListNode * tmp = head;
        while(tmp){
            list_node_.push_back(tmp);
            tmp = tmp->next;
        }
        sort(list_node_.begin(), list_node_.end(), cmp);
        for(int i = 0; i < list_node_.size() - 1; ++i){
            list_node_[i]->next = list_node_[i+1];
        }
        list_node_.back()->next = nullptr;
        return list_node_.front();
    }

private:
    vector<ListNode*> list_node_;
    
};

