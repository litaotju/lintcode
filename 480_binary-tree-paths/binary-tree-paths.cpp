/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-paths
@Language: C++
@Datetime: 16-05-23 16:34
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string s;
        binaryTreePaths(root, paths, s);
        return paths;
    }
    
    void binaryTreePaths(TreeNode *root, vector<string> & paths, string s){
        if( root == NULL){
            return;
        } 
        if( root ->left == NULL && root->right == NULL){
            char *cs = new char[100];
            sprintf(cs, "%d", root->val);
            paths.push_back( s.append(cs) );
            return;
        }
        char *cs = new char[100];
        sprintf(cs, "%d->", root->val);
        
        if(root -> left != NULL){
            string prefix = s;
            binaryTreePaths( root->left, paths, prefix.append(cs) );
        }
        if(root->right != NULL){
            string prefix = s;
            binaryTreePaths( root->right, paths, prefix.append(cs) );
        }
    }
};