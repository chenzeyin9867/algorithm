/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "head.h"
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B==nullptr)return false;
        if(A==nullptr)return false;
        if(A->val==B->val){
            if(equal(A,B))return true;
        }
        return isSubStructure(A->left,B)||isSubStructure(A->right,B);        
    }
    bool equal(TreeNode*a,TreeNode*b){
            TreeNode* A=a;TreeNode*B=b;
            if(B==nullptr)return true;
            queue<TreeNode*>Bque;
            queue<TreeNode*>Aque;
            Aque.emplace(A);
            Bque.emplace(B);
            while(!Bque.empty()&&!Aque.empty()){
                //如果Aque，Bque大小不相等，则返回false（说明B的子结构中有A没有的部分，具体原因见下方注释）
                if(Bque.size()!=Aque.size())return false;
                B=Bque.front();Bque.pop();
                A=Aque.front();Aque.pop();
                if(A->val!=B->val)return false;

                //如果B有左子树，则左子树入Bque，继续判断A是否有左子树，有，则入Aque
                if(B->left){
                    Bque.emplace(B->left);
                    if(A->left)Aque.emplace(A->left);
                }
                //如果B有右子树，则右子树入Bque，继续判断A，有则入队
                if(B->right){
                    Bque.emplace(B->right);
                    if(A->right)Aque.emplace(A->right);
                }
            }
            //退出while循环的时候如果两个队列大小不相等，则返回false；
            if(!Bque.empty()||!Aque.empty())return false;
            //两个queue都为空说明顺利完成循环，B中有的结构在A中都有，返回true
            return true;
        }
};

