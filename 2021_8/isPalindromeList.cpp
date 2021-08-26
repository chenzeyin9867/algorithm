#include "head.h"
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        string tmp;
        ListNode *cur = head;
        while(cur){
            tmp += cur->val - 0 + '0';
            cur = cur->next;
        }
        string cmp = tmp;
        reverse(tmp.begin(), tmp.end());
        return tmp == cmp;

    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    cout << s.isPalindrome(head) << endl;
    return 0;
}