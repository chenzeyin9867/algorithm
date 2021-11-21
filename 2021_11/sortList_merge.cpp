/**
 * @file		sortList_merge.cpp
 * @brief       using O(1) space to meet the command(using bottom to top merge sort)
 * @author 		chenzeyin (chenzeyin9867@buaa.edu.cn)
 * @date		2021-11-21
 * @copyright	Copyright (c) 2021  chenzeyin9867
 */

#include "head.h"
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head) return nullptr;
        /* cal the head's length */
        int len = 0;
        ListNode* tmp = head;
        while(tmp) {
            ++len;
            tmp = tmp->next;
        }
        ListNode* dummy_head = new ListNode(0, head);
        for(int step = 1; step < len; step = step * 2) /* each iteration, double the step */
        {
            int cnt = 1; // get two list with length = step
            ListNode* prev = dummy_head, *cur = dummy_head->next;
            ListNode* tmp, *l1_head, *l2_head; 
            while(cur){
                l1_head = cur;
                for(int cnt = 1 ; cnt < step && cur->next != nullptr; ++cnt){
                    cur = cur->next;
                }
                l2_head = cur->next;
                cur->next = nullptr;
                /* now tmp points to l2_head; */
                cur = l2_head;
                for(int cnt = 1; cnt < step && cur != nullptr && cur->next != nullptr; ++cnt){
                    cur = cur->next;
                }

                ListNode* next = nullptr;
                if (cur != nullptr) {
                    next = cur->next;
                    cur->next = nullptr;
                }

                ListNode* merged = merge(l1_head, l2_head);
                prev->next = merged;
                while(prev->next){
                    prev = prev->next;
                }
                cur = next;

            }
        }
        return dummy_head->next;
    }
    /**
     * @brief merge two ordered ListNode with length len
     */
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* dummy_head = new ListNode(0), *cur = dummy_head;
        ListNode* d_1 = l1, *d_2 = l2;
        int len1 = 0, len2 = 0;
        while(d_1 || d_2 ){
            if(!d_1){
                cur->next = d_2;
                d_2 = d_2->next;
            }else if(!d_2){
                cur->next = d_1;
                d_1 = d_1->next;
            }else{
                if(d_1->val < d_2->val){
                    cur->next = d_1;
                    d_1 = d_1->next;
                }else{
                    cur->next = d_2;
                    d_2 = d_2->next;
                }
            }
            cur = cur->next;
        }
        return dummy_head->next;
    }

};

// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         if (head == nullptr) {
//             return head;
//         }
//         int length = 0;
//         ListNode* node = head;
//         while (node != nullptr) {
//             length++;
//             node = node->next;
//         }
//         ListNode* dummyHead = new ListNode(0, head);
//         for (int subLength = 1; subLength < length; subLength <<= 1) {
//             ListNode* prev = dummyHead, *curr = dummyHead->next;
//             while (curr != nullptr) {
//                 ListNode* head1 = curr;
//                 for (int i = 1; i < subLength && curr->next != nullptr; i++) {
//                     curr = curr->next;
//                 }
//                 ListNode* head2 = curr->next;
//                 curr->next = nullptr;
//                 curr = head2;
//                 for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
//                     curr = curr->next;
//                 }
//                 ListNode* next = nullptr;
//                 if (curr != nullptr) {
//                     next = curr->next;
//                     curr->next = nullptr;
//                 }
//                 ListNode* merged = merge(head1, head2);
//                 prev->next = merged;
//                 while (prev->next != nullptr) {
//                     prev = prev->next;
//                 }
//                 curr = next;
//             }
//         }
//         return dummyHead->next;
//     }

//     /**
//      * @brief merge two ordered ListNode with length len
//      */
//     ListNode* merge(ListNode* l1, ListNode* l2){
//         if(!l1) return l2;
//         if(!l2) return l1;
//         ListNode* dummy_head = new ListNode(0), *cur = dummy_head;
//         ListNode* d_1 = l1, *d_2 = l2;
//         int len1 = 0, len2 = 0;
//         while(d_1 || d_2 ){
//             if(!d_1){
//                 cur->next = d_2;
//                 d_2 = d_2->next;
//             }else if(!d_2){
//                 cur->next = d_1;
//                 d_1 = d_1->next;
//             }else{
//                 if(d_1->val < d_2->val){
//                     cur->next = d_1;
//                     d_1 = d_1->next;
//                 }else{
//                     cur->next = d_2;
//                     d_2 = d_2->next;
//                 }
//             }
//             cur = cur->next;
//         }
//         return cur;
//     }
    // ListNode* merge(ListNode* head1, ListNode* head2) {
    //     ListNode* dummyHead = new ListNode(0);
    //     ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
    //     while (temp1 != nullptr && temp2 != nullptr) {
    //         if (temp1->val <= temp2->val) {
    //             temp->next = temp1;
    //             temp1 = temp1->next;
    //         } else {
    //             temp->next = temp2;
    //             temp2 = temp2->next;
    //         }
    //         temp = temp->next;
    //     }
    //     if (temp1 != nullptr) {
    //         temp->next = temp1;
    //     } else if (temp2 != nullptr) {
    //         temp->next = temp2;
    //     }
    //     return dummyHead->next;
    // }
// };

int main(){
    Solution s;
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    head = s.sortList(head);
    while(head){
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << endl;
    return 0;
}