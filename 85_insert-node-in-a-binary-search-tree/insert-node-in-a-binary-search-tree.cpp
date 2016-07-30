/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/insert-node-in-a-binary-search-tree
@Language: C++
@Datetime: 16-05-24 08:16
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
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        // write your code here
        TreeNode *original_root = root;
        TreeNode *parent = NULL;
        while(root){
            parent = root;
            if(node->val >= root->val){
                root = root ->right;
            }else{
                root = root->left;
            }
        }
        if(parent == NULL){
            return node;
        }
        if(node->val >= parent ->val){
            parent -> right = node;
            
        }else{
            parent ->left = node;
        }
        return original_root;
    }
};