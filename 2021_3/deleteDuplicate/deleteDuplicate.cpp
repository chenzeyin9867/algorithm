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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode * t = head;
        int cnt = 0;
        while(t){
            cnt ++;
            t = t->next;
        }
        if(cnt == 1) return head;
        int curVal = head->val;
        ListNode * next = head->next;
        ListNode * prev = head;
        while(next){
            if(next->val == curVal){ // value of the next duplicated with the curVal
                prev->next = next->next;
                next = next->next;
                // prev = prev->next;
            }else{
                curVal = next->val;
                next = next->next;                                                        
                prev = prev->next;
            }
        }      
        return head;                              
    }
};

int main(){
    Solution s;
    ListNode head(1,new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    ListNode h(1, new ListNode(1, new ListNode(2)));
    ListNode* result = s.deleteDuplicates(&h);
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}