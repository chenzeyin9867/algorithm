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
#include <stack>
#include <malloc.h>   
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(0), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        std::stack <int> s1;
        std::stack <int> s2; 
        ListNode *head = l1;
        // while(head){
        //     s1.push(head->val);
        //     head = head->next;
        // }
        // head = l2;
        // while(head){
        //     s2.push(head->val);
        //     head = head->next;
        // }
        ListNode *result = new ListNode();
        ListNode *ret = result;
        stack<int> r;
        int prev = 0;
        while(l1 || l2){
            int a = 0;
            int b = 0;

            if(l1){
                a = l1->val;   
                l1 = l1->next; 
                //cout << a;
            }
            if(l2){
                b = l2->val;
                l2 = l2->next;
                //cout << b;
            }
            //cout << endl;
            //cout << "a + b + prev" <<  (a + b + prev) << endl;
            ListNode * cur = new ListNode();
            cur->val = (a + b + prev) % 10;
            cur->next = nullptr;
            result->next = cur;
            result = cur;
            prev = (a + b + prev) / 10;
        }
        if(prev != 0){
            ListNode *cur = new ListNode(prev);
            result->next = cur;
        }
        // result->val = r.top();
        // r.pop();
        // while(!r.empty()){
        //     ListNode * cur = new ListNode();
        //     cur->val = r.top();
        //     cur->next = nullptr;
        //     r.pop();
        //     result->next = cur;
        //     result = cur;
        // }
        return ret->next;
    }
};

int main(){
    Solution s;
    struct ListNode x1,x2,x3;
    struct ListNode y1,y2,y3;
    x1.val = 2;
    x2.val = 4;
    x3.val = 3;
    y1.val = 5;
    y2.val = 6;
    y3.val = 4;
    x1.next = &x2;
    x2.next = &x3;
    y1.next = &y2;
    y2.next = &y3;
    ListNode * result = s.addTwoNumbers(&x1, &y1);
    while(result){
        cout << result->val << " ";
        result = result ->next;
    }
    return 0;
}