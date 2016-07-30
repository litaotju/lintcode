/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/balanced-binary-tree
@Language: C++
@Datetime: 16-06-08 03:22
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        if(!root)
            return true;
        return backTrace(root)!= -1;
    }
    
    int backTrace(TreeNode * root){
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        int L, R;
        L = backTrace(root->left);
        R = backTrace(root->right);
        if(L == -1 || R == -1)
            return -1;
        if(abs(L-R)>1)
            return -1;
        return max(L, R)+1;
    }
};