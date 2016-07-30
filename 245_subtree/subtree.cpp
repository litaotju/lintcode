/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/subtree
@Language: C++
@Datetime: 16-02-21 14:44
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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        bool result = false;
        if(T2==NULL){
            return true;
        }
        if(T1 !=NULL && T2!=NULL){
            if( T1->val == T2->val ){
                result =  doesT1HasT2(T1, T2);
            }
            if(!result){
                result = isSubtree(T1->left, T2);
            }
            if(!result){
                result = isSubtree(T1->right, T2);
            }
        }
        return result;
    }
    
    bool doesT1HasT2(TreeNode *T1, TreeNode *T2){
        if(T2==NULL){
            if(T1==NULL)
                return true;
            else
                return false;
        }
        if(T1==NULL){
            return false;
        }
        if(T1->val != T2->val){
            return false;
        }
        else{
            return doesT1HasT2(T1->left, T2->left) && doesT1HasT2(T1->right, T2->right);
        }
    }
};