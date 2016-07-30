/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: C++
@Datetime: 16-06-13 14:18
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
    typedef vector<int>::iterator NodeIter;
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        if(inorder.empty()|| postorder.empty()|| inorder.size()!= postorder.size())
            return NULL;
        return buildTree(inorder, inorder.begin(), inorder.end()-1, 
                        postorder, postorder.begin() , postorder.end()-1);
    }
    
private:
    TreeNode *buildTree(vector<int> & inorder, NodeIter  inFront, NodeIter inEnd,
            vector<int> & postorder, NodeIter postFront, NodeIter postEnd
            )
    {
        if(inFront > inEnd || postFront > postEnd )
            return NULL;
            
        //根节点一定在 postorder的末尾
        TreeNode *root = new TreeNode(*postEnd);
        //根节点在inorder中的位置
        NodeIter rootIndexInorder = find(inFront, inEnd+1, *postEnd);
        //assert rootIndexInorder != inEnd+1 一定能找到
        
        //右子树的长度
        int lengthR = inEnd - rootIndexInorder;
        //右子树的长度
        int lengthL = rootIndexInorder  - inFront;
        
        //右子树为空  
        if(rootIndexInorder == inEnd){
            root->right = NULL;
        //右子树非空时
        }else{
            root ->right = buildTree(inorder, rootIndexInorder+1, inEnd,
                                postorder, postEnd-lengthR, postEnd-1
                            );
        }
        
        //左子树为空
        if(rootIndexInorder == inFront){
            root->left = NULL;
        }
        //左子树不空
        else{
            root->left = buildTree(inorder, inFront, rootIndexInorder-1,
                                    postorder, postFront, postFront + lengthL -1
                        );
        }

        return root;
    }
};