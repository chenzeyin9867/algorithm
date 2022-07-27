#include "head.h"
/* Sort a LinkList by merge sort */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head){
        // cout << "MergeSort:" << head->val << endl;
        // First step, find the mid point of the list, then merge sort two list
        if(!head || (head && !head->next)) return head;
        // Using fast and slow pointer to find the mid point of list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        // cout << "Start to find the mid " << endl;
        while(fast && fast->next){
            // cout << "fast->next:" << fast->next->val << endl;
            fast = fast->next->next;
            // cout << "fast->next->next:" << fast->val << endl;
            prev = slow;
            slow = slow->next;
        }

        ListNode* mid = slow;
        // cout << "mid:" << mid->val << endl;
        prev->next = nullptr;
        ListNode* h1 = mergeSort(head);
        ListNode* h2 = mergeSort(mid);
        return merge(h1, h2);
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        // cout << "Merge:" << l1->val << "   " << l2->val << endl;
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur = dummyHead;
        while(l1 && l2){
            // cout << "l1:" << l1->val << " l2:" << l2->val << endl; 
            if(l1->val < l2->val){
                ListNode* temp = new ListNode(l1->val);
                cur->next = temp;
                cur = cur->next;
                l1 = l1->next;
            }else{
                ListNode* temp = new ListNode(l2->val);
                cur->next = temp;
                cur = cur->next;   
                l2 = l2->next;   
            }
        }
        if(l1){
            cur->next = l1;
        }else{
            cur->next = l2;
        }
        return dummyHead->next;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    ListNode* ret = s.sortList(head);
    while(ret){
        cout << ret->val << "->";
        ret = ret->next;
    }
    cout << endl;
    return 0;
}