/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-postorder-traversal
@Language: C++
@Datetime: 16-02-23 09:51
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> post_order;
        if(root == NULL){
            return post_order;
        }
        postOrderSubTree(root, post_order);
        return post_order;
    }
    
    void postOrderSubTree(TreeNode *root, vector<int> & post_order){
        if(root == NULL){
            return;
        }
        if(root->left != NULL){
            postOrderSubTree(root->left, post_order);
        }
        if(root->right != NULL){
            postOrderSubTree(root->right, post_order);
        }
        post_order.push_back(root->val);
    }
};