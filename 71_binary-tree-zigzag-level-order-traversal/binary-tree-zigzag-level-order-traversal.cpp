/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-zigzag-level-order-traversal
@Language: C++
@Datetime: 16-03-07 05:24
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
     * @return: A list of lists of integer include 
     *          the zigzag level order traversal of its nodes' values 
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > val_order;
        deque<TreeNode *> node_order;
        if(root != NULL){
            node_order.push_back(  root);
            val_order.push_back(vector<int>(1,root->val));
            zigzagLevelOrder_R(val_order, node_order, false);
        }
        return val_order;
    }
    void zigzagLevelOrder_R(vector<vector<int> > & order, deque<TreeNode *> node_order , bool                                  is_odd_level){
        if(node_order.empty()){
            return;
        }
        deque<TreeNode *> last_level = node_order;
        deque<TreeNode *>  current_level;
        vector<int> current_level_val;
        
        if(is_odd_level){
            deque<TreeNode *> ::iterator it;
            for( it = last_level.begin();it != last_level.end(); it++){
                if( (*it)->left ){
                    current_level_val.push_back( (*it)->left->val);
                    current_level.push_back( (*it)->left);
                }
                if( (*it)->right){
                    current_level_val.push_back( (*it)->right->val );
                    current_level.push_back( (*it)->right);
                }
            }
        } else{
            deque<TreeNode *> ::reverse_iterator it;
            for( it = last_level.rbegin();it != last_level.rend(); it++){
                if( (*it)->right){
                    current_level_val.push_back( (*it)->right->val );
                    current_level.push_front( (*it)->right);
                }
                if( (*it)->left ){
                    current_level_val.push_back( (*it)->left->val);
                    current_level.push_front( (*it)->left);
                }
            }
        }
        if(!current_level_val.empty()){
            order.push_back(current_level_val);
            node_order = current_level;
            zigzagLevelOrder_R(order, node_order, !is_odd_level);
        }
        return;
    }
    
};