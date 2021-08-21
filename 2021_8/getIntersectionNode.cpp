#include "head.h"
// #include "treenode.h"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        set<ListNode*> nodeset;
        ListNode* l = headA;
        while(l){
            nodeset.emplace(l);
            l = l->next;
        }
        l = headB;
        while(l){
            if(nodeset.find(l)!= nodeset.end())
                return l;
            l = l->next;
        }
        return nullptr;
    }
};

int main(){
    Solution s;
    ListNode* common = new ListNode(8, new ListNode(4, new ListNode(5)));
    ListNode* h1 =     new ListNode(4, new ListNode(1, common));
    ListNode* h2 =     new ListNode(5, new ListNode(0, new ListNode(1,common)));
    cout << s.getIntersectionNode(h1, h2)->val << endl;
    return 0;
}