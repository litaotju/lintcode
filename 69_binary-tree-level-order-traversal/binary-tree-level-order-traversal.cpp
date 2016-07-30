/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal
@Language: C++
@Datetime: 16-02-24 07:45
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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > vec;
        if( root == NULL){
            return vec;
        }
        
        deque <TreeNode *> dequeTreeNode;
        
        dequeTreeNode.push_back(root);
        
        while( dequeTreeNode.size() ){
            vector<int> current_level;
            deque<TreeNode *> next_level;
            
            while(dequeTreeNode.size()) {
                TreeNode * front = dequeTreeNode.front();
                dequeTreeNode.pop_front();
                current_level.push_back(front ->val );
                if(front -> left != NULL){
                    next_level.push_back(front ->left);
                }
                if(front ->right != NULL){
                    next_level.push_back(front->right);
                }
            }
            vec.push_back(current_level);
            dequeTreeNode = next_level;
        }
        return vec;
    }
};
