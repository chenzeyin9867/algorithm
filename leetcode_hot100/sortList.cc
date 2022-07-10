#include "head.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        /* use extra space to store the val */
        vector<ListNode*> m_vec;
        ListNode *cur = head;
        while(cur){
            m_vec.push_back(cur);
            cur = cur->next;
        }
        /* sort the list according the node->val */ 
        std::sort(m_vec.begin(), m_vec.end(), [](ListNode *l1, ListNode* l2){
            return l1->val < l2->val;            
        });
        
        ListNode *new_head = head, *new_cur = head;
        new_head->next = nullptr;
        for(int i = 1; i < m_vec.size(); ++i){
            new_cur->next = m_vec[i];
            new_cur = new_cur->next;
            new_cur->next = nullptr;
        }
        return new_head;
        
    }
};