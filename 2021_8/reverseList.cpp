#include "head.h"
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* cur , *prev;
        int a, b;
        prev = head;
        cur = head->next;
        head->next = nullptr;
        while(cur){
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;    
        }
        return prev;
    }
    
};

int main(){
    // auto at;
    Solution s;
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    ListNode *ret = s.reverseList(head);
    while(ret){
        cout << ret->val << " ";
        ret = ret->next;

    }
    cout << endl;

    return 0;
}