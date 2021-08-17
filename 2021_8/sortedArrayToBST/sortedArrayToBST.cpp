//Definition for a binary tree node.
#include <iostream>
#include <vector>
using namespace std;
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 1){
            TreeNode *rt = new TreeNode(nums[0]);
            return rt;
        }
        // or cut the nums into two slides
        int mid = nums.size() / 2;
        if (nums.size() % 2 == 0){
            mid = mid - 1;
        }
        TreeNode *head = new TreeNode(nums[mid]);
        if (mid >= 1){
            vector <int> numsl(nums.begin(), nums.begin() + mid);
            TreeNode *left = sortedArrayToBST(numsl); 
            head->left = left;
        }
        if (mid < nums.size() - 1){
            vector <int> numsr(nums.begin()+mid+1, nums.end());
            head->right = sortedArrayToBST(numsr);
        }
        
        return head;
    }
};


void inorderTraversal(TreeNode * node){
    if(!node){
        return;
    }
    inorderTraversal(node->left);
    cout << node->val << " ";
    inorderTraversal(node->right);

}

int main(){
    Solution s;
    vector<int> nums{-10,-3,0,5,9};
    TreeNode * head = s.sortedArrayToBST(nums);
    inorderTraversal(head);
    return 0;
}