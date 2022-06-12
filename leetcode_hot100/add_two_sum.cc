#include "head.h"
class Solution {
public:

    /* Reverse the List, and return the head of new List */
    ListNode* reverseList(ListNode *l){
        ListNode *head = l, *cur = l, *next = nullptr;
        ListNode *prev = nullptr;
        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    /* Add two List */
    ListNode* addTwoList(ListNode* l1, ListNode *l2){
        ListNode * head = new ListNode(0), *cur = head;
        ListNode *h1 = l1, *h2 = l2;
        int flag_add = 0;
        while(l1 || l2){
            int add_ = 0;
            if(l1) add_ += l1->val;
            if(l2) add_ += l2->val;
            add_ += flag_add;
            flag_add = add_ / 10;
            add_ = add_ % 10;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
            cur->next = new ListNode(add_);
            cur = cur->next;
        }
        if(flag_add) cur->next = new ListNode(flag_add);
        ListNode *tmp = head->next;
        delete head;
        return tmp;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_rev = reverseList(l1);
        ListNode* l2_rev = reverseList(l2);
        ListNode* l_sum  = addTwoList(l1_rev, l2_rev);
        return reverseList(l_sum);
    }
};

int main(){

    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(3))); 
    ListNode *l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
    Solution s;
    ListNode *l = s.addTwoNumbers(l1 , l2);
    return 0;  
}