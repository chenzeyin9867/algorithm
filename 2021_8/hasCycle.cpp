#include "head.h"

struct ListNode{
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL){}
    ListNode (int x, ListNode* y): val(x), next(y){}
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast){
            if(fast == slow) return true;
            for(int i = 0; i< 2; i++){
                if(fast){
                    fast = fast->next;
                    if(fast == slow) return true;

                }else{
                    return false;
                }
            }
            slow = slow->next;
        }
    }
};

int main(){
    Solution s;
    ListNode * head = new ListNode(3);
    ListNode * tail = new ListNode(2);
    // head->next = tail;
    ListNode * t = new ListNode(0, new ListNode(4, head));
    tail->next = t;
    // head->next = tail;
    tail->next = head;
    cout << s.hasCycle(head) << endl;
    return 0;
}