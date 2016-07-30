/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/convert-binary-search-tree-to-doubly-linked-list
@Language: C++
@Datetime: 16-02-24 03:23
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
 * Definition of Doubly-ListNode
 * class DoublyListNode {
 * public:
 *     int val;
 *     DoublyListNode *next, *prev;
 *     DoublyListNode(int val) {
 *         this->val = val;
           this->prev = this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of tree
     * @return: the head of doubly list node
     */
    DoublyListNode* bstToDoublyList(TreeNode* root) {
        
        DoublyListNode * head =NULL; 
        if(root == NULL){
            return head;
        }
        DoublyListNode * last_node = NULL;
        convert( root, & last_node);
        while( last_node !=NULL && last_node -> prev != NULL){
            last_node = last_node -> prev;
        }
        return last_node;
    }
    
    void convert(TreeNode * root, DoublyListNode **pLastNode){
        if(root == NULL){
            return;
        }
        if( root ->left != NULL){
            convert(root->left, pLastNode);
        }
        DoublyListNode * current = new DoublyListNode(root->val);
        current -> prev = (*pLastNode);
        if (*pLastNode!=NULL ){
            (*pLastNode)->next = current;
        }
        (*pLastNode) = current;
        if(root ->right != NULL){
            convert(root->right, pLastNode);
        }
        
    }
};


