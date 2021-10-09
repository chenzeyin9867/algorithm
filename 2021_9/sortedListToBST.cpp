#include "head.h"
class Solution {
public:
    vector<int> vList;
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* cur = head;
        while(cur){
            vList.emplace_back(cur->val);
            cur = cur->next;
        }
        
        // int len = vList.size();
        // int mid = len / 2;
        // TreeNode* resultHead = new TreeNode(vList[mid]);
        TreeNode* resultHead = subTree(0, vList.size() - 1);
  
        return resultHead;
    }
    
    TreeNode* subTree(int l, int r){
        if(l > r) return nullptr;
        if(l == r) return new TreeNode(vList[l]);
        int mid = l + (r - l) / 2;
        TreeNode* curHead = new TreeNode(vList[mid]);
        curHead->left = subTree(l, mid - 1);
        curHead->right = subTree(mid + 1, r);
        return curHead;
    }
};