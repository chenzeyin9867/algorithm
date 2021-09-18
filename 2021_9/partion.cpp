#include "head.h"
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessList = new ListNode(1), *lcur = lessList;
        lessList->next = lcur;
        ListNode *greaterList = new ListNode(2), *gcur = greaterList;
        greaterList->next = gcur;
        if(!head) return nullptr;
        ListNode* cur = head;
        while(cur){
            if(cur->val < x){
                lcur->next = cur;
                lcur = lcur->next;
            }
            else{
                gcur->next = cur;
                gcur = gcur->next;
            }
            cur = cur->next;
        }
        lcur->next = greaterList->next;
        return lessList->next;
        
    }
};