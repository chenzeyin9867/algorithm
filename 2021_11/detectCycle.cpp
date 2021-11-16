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
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        int count = 0;
        unordered_set<ListNode*> nodeSet;
        while(head){
            if(nodeSet.count(head)){
                return head;
            }
            // not exist
            nodeSet.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};