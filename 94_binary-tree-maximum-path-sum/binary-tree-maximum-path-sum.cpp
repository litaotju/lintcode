/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/binary-tree-maximum-path-sum
@Language: C++
@Datetime: 16-06-12 08:33
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
 //问题的关键是在回溯的过程中比较目前已经有的最大的值。
 //可以利用solution的状态信息，算法不一定完全要使用纯函数来实现
class Solution {
public:
    
    int maxPathSum(TreeNode *root){
        maxPathSumCore(root);
        return MAX;
    }
    
private:
    int maxPathSumCore(TreeNode *root) {
        if(root == NULL)
            return 0;
        int maxA, maxB;
        maxA = maxPathSumCore(root->left);
        maxB = maxPathSumCore(root->right);
        
        //更新MAX的状态
        MAX  = max(maxA+maxB+root->val, MAX);
        MAX  = max(maxA+root->val, MAX);
        MAX = max(maxB+root->val, MAX);
        MAX = max(root->val, MAX);
        
        //返回包含当前节点，且路径没有完全终结，还需要向上延伸时最大的可能值
        return max(max(maxA,maxB)+root->val, root->val);
    }
private:
    int MAX = -99999999;
};