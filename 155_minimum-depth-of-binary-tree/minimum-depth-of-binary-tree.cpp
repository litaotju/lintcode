/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/minimum-depth-of-binary-tree
@Language: C++
@Datetime: 16-06-05 05:47
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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        int ldepth = 0;
        int rdepth = 0;
        
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left ==NULL)
            return minDepth(root->right) + 1 ;
        if(root->right == NULL)
            return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right))+1;
        
    } 
};