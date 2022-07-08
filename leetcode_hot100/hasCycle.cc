#include "head.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> m_set;
        ListNode* cur = head;
        while(cur){
            if(m_set.find(cur) == m_set.end()){
                m_set.insert(cur);
                cur = cur->next;
            }else{
                return true;
            }
        }
        return false;
    }
};