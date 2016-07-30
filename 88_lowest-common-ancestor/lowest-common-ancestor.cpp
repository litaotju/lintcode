/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/lowest-common-ancestor
@Language: C++
@Datetime: 16-03-04 06:53
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
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        deque<TreeNode *> AnceA, AnceB;
        
        getAncestors(AnceA, root, A);
        getAncestors(AnceB, root, B);
        
        deque<TreeNode *>::iterator  itA, itB;
        
        itA = AnceA.begin();
        itB = AnceB.begin();
        
        while( *itA == *itB){
            itA ++;
            itB ++;
        }
        return *(--itA);
        
    }
    
    
    void getAncestors( deque<TreeNode *> & Ancestors, TreeNode *root, TreeNode *A){
        if(root == NULL|| A== NULL){
            return;
        }
        if( root == A){
            Ancestors.push_back(root);
            return;
        } else if( root ->left == NULL && root->right == NULL){
            return;
        } 
        getAncestors(Ancestors, root->left, A);
        if( !Ancestors.empty() ){
            Ancestors.push_front(root);
            return;
        }
        getAncestors(Ancestors, root->right, A);
        if( !Ancestors.empty() ){
            Ancestors.push_front(root);
            return;
        }
    }
};