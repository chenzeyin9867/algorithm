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
        while(head){
            s1.push(head->val);
            head = head->next;
        }
        head = l2;
        while(head){
            s2.push(head->val);
            head = head->next;
        }
        ListNode *result = (ListNode*)malloc(sizeof(struct ListNode));
        ListNode *ret = result;
        stack<int> r;
        int prev = 0;
        while(!s1.empty() || !s2.empty()){
            int a = 0;
            int b = 0;

            if(!s1.empty()){
                a = s1.top();   
                s1.pop(); 
            }
            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            r.push((a + b + prev)%10);
            prev = (a + b + prev) / 10;
            cout << "a + b + prev" <<  (a + b + prev) << endl;
        }
        result->val = r.top();
        r.pop();
        while(!r.empty()){
            ListNode * cur =(ListNode*)malloc(sizeof(struct ListNode));
            cur->val = r.top();
            cur->next = nullptr;
            r.pop();
            result->next = cur;
            result = cur;
        }
        return ret;
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
    ListNode * result = s.addTwoNumbers(&x1, &x2);
    // while(result){
    //     cout << result->val << " ";
    //     result = result ->next;
    // }
    return 0;
}