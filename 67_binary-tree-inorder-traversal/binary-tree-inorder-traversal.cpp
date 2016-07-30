/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-inorder-traversal
@Language: C++
@Datetime: 16-05-24 08:20
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        _inorderTraversal(root, result);
        return result;
    }
private:
    void _inorderTraversal(TreeNode *root, vector<int> & result){
        if(root == NULL)
            return;
        _inorderTraversal(root->left, result);
        result.push_back(root->val);
        _inorderTraversal(root->right, result);
    }
};