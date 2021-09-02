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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* prev = head;
        ListNode* fast = head;
        for(int i = 0; i < k-1; i++){
            fast = fast->next;
        }
        while(fast->next){
            fast = fast->next;
            prev = prev->next;
        }
        return prev;
    }
};