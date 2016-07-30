/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-level-order-traversal-ii
@Language: C++
@Datetime: 16-06-08 05:30
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int> >result;
        if(root==NULL)
            return result;
        deque<vector<int> > result_d;
        queue<TreeNode *> cur;
        cur.push(root);
        while(!cur.empty()){
            queue<TreeNode *> next;
            vector<int> curval;
            while(!cur.empty()){
                if(cur.front()->left!=NULL){
                    next.push(cur.front()->left);
                }
                if(cur.front()->right!=NULL){
                    next.push(cur.front()->right);
                }
                curval.push_back(cur.front()->val);
                cur.pop();
            }
            result_d.push_front(curval);
            cur = next;
        }
        
        while(!result_d.empty()){
            result.push_back(result_d.front());
            result_d.pop_front();
        }
        return result;
    }
};