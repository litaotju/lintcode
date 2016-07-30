/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height
@Language: C++
@Datetime: 16-05-26 14:57
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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if(A.empty())
            return NULL;
        int mid = A.size()/2;
        TreeNode *root  = new TreeNode(A[mid]);
        root ->left = _sortedArrayToBST(A, 0, mid-1, root);
        root->right = _sortedArrayToBST(A, mid+1, static_cast<int>(A.size()-1), root);
        return root;
    }
    TreeNode * _sortedArrayToBST(const vector<int> &A, int start, int end, TreeNode *root){
        if(end < start){
            return NULL;
        }
        if(start == end){
            TreeNode *node = new TreeNode(A[start]);
            return node;
        }
        int mid = start + (end - start)/2;
        TreeNode * node = new TreeNode(A[mid]);
        node->left = _sortedArrayToBST(A, start, mid-1, root);
        node->right = _sortedArrayToBST(A, mid+1, end, root);
        return node;
    }
};


