#include "head.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* Return the first Node into cycle. */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> m_set;
        ListNode *cur = head;
        while(cur){
            if(m_set.find(cur) != m_set.end()){
                return cur;
            }
            m_set.insert(cur);
            cur = cur->next;
        }
        return nullptr;
    }
};