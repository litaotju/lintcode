/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: C++
@Datetime: 16-05-23 16:59
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
 #include <deque>
 using namespace std;
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        /*
        //递归版本
        if(root ==NULL)
            return;
        TreeNode *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        */
        //非递归版本
        if(root == NULL)
            return;
        deque<TreeNode *> d;
        d.push_back(root);
        TreeNode *front, *temp;
        while(!d.empty()){
            front = d.front();
            if(front->left!=NULL)
                d.push_back(front->left);
            if(front->right!=NULL)
                d.push_back(front->right);
            temp = front->left;
            front->left = front->right;
            front->right =temp;
            d.pop_front();
        }
    }
};