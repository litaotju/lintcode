/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-preorder-traversal
@Language: C++
@Datetime: 16-05-26 14:37
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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        _preorderTraversal(result, root);
        return result;
    }
    void _preorderTraversal(vector<int> & result, TreeNode *root){
        if(root == NULL)
            return;
        result.push_back(root->val);
        if(root->left != NULL){
            _preorderTraversal(result, root->left);
        }
        if(root->right != NULL){
            _preorderTraversal(result, root->right);
        }
    }
};
