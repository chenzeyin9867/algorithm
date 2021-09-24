#include "head.h"
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head) return nullptr;
        ListNode* prev = new ListNode(0);
        ListNode* result = prev;
        ListNode* cur = head;
        ListNode* reverseHeadPrev;
        ListNode* reverseHead;
        prev->next = cur;
        int cnt = 1;
        while(cnt < left){ // go to the first place for reverse
            ++cnt;
            prev = prev->next;
            cur = cur->next;
        }
        reverseHeadPrev = prev;
        reverseHead = cur;
        // reverse each node between left and right
        while(cnt <= right){
            ListNode* tmpNext = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmpNext;
            ++cnt;
            if(cnt > right){
                reverseHeadPrev->next = prev;
                reverseHead->next = cur; 
            }
        }
        return result->next;
    }
};