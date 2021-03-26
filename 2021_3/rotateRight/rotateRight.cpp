/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * pt = head;
        if(!pt) return head;
        int len = 1;
        while(pt->next){ // compute the length of the link 
            len++; 
            pt = pt->next;
        }
        // cout << len << endl;
        int rotateNum = k % len;
        if(rotateNum == 0) return head;
        int i = 1;
        ListNode * t = head;
        while(i < len - rotateNum){
            t = t->next;
            i++;
        }
        // cout << t->val << endl;
        // cout << "here" << endl;
        ListNode * r = t->next;
        pt->next = head;
        t->next = NULL;
    //     while(r){
    //     cout << "**" << endl;
    //     cout << r->val << " ";
    //     r = r->next;
    // }
        return r;
    }
};

int main(){
    Solution s;
    int k;
    cin >> k;
    ListNode * head = new ListNode{0, new ListNode{1, new ListNode{2}}};
    ListNode * result = s.rotateRight(head, k); 
    while(result){
        // cout << "**" << endl;
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}