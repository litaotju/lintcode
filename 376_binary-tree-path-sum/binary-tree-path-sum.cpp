/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-path-sum
@Language: C++
@Datetime: 16-02-23 02:34
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
     * @param root the root of binary tree
     * @param target an integer
     * @return all valid paths
     */
    vector<vector<int>> binaryTreePathSum(TreeNode *root, int target) {
        vector<vector <int> > ret;
        if(root==NULL){
            return ret;
        }
        vector<int> path;
        binaryTreeSum(ret, path, root, target);
        return ret;
    }
    
     void binaryTreeSum(vector<vector<int> >& ret, vector<int> path, TreeNode * root, int target ){
        if(root ->left ==NULL && root ->right == NULL){
            if(root->val == target){
                path.push_back(root->val);
                ret.push_back(path);
            }
            else{
                return;
            }
        }
        path.push_back(root->val);
        if(root -> left != NULL){
            binaryTreeSum(ret, path, root->left, target - (root->val));
        }
        if(root->right != NULL){
            binaryTreeSum(ret, path, root->right, target - (root->val));
        }
    }
};