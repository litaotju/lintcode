/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/flatten-binary-tree-to-linked-list
@Language: C++
@Datetime: 16-07-17 12:54
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        if(root == NULL)
            return;
        flattenR(root);
    }
    
private:
    void flattenR(TreeNode * root){
        //到底了
        if(root==NULL)
            return;
        if(root->left == NULL && root ->right==NULL){
            mLast = root;
            return;
        }
        TreeNode *right = root->right;
        
        if(root->left != NULL){
            flattenR(root->left);
            root->right = root->left;
            root->left  = NULL;
            //深度优先访问左边，最左边的最后一个叶子节点为mLast
            if(right != NULL){
                mLast->right = right;
                flattenR(right);
            }
            return;
        }
        flattenR(root->right);
    }
    
    TreeNode *mLast;
};