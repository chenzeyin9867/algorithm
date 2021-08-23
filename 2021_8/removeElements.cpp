#include "head.h"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return nullptr;
        ListNode *ret = new ListNode(0);
        ret->next = head;
        ListNode *cur = ret;
        ListNode *prev = ret;
        while(cur->next){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }else{
                cur = cur->next;
            }
        }
        // if(prev) prev->next = nullptr;
        return ret->next;
    }
};

int main(){
    Solution s;
    ListNode* l = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    ListNode* r = s.removeElements(l, 6);
    while(r){
        cout << r->val << " "; 
        r = r->next;
    }
    cout << endl;
    return 0;
}