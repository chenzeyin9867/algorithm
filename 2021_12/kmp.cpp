/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "head.h"
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0), *cur = head;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        while(h1 && h2){
            if(h1->val < h2->val){
                cur->next = h1;
                cur = cur->next;
                h1 = h1->next;
            }else{
                cur->next = h2;
                cur = cur->next;
                h2 = h2->next;
            }
        }
        if(h1){
            cur->next = h1;
        }else{
            cur->next = h2;
        }
        return head->next;
    }
};