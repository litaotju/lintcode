/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/invert-binary-tree
@Language: Java
@Datetime: 15-12-04 14:44
*/

/**
 * Definition of TreeNode:
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left, right;
 *     public TreeNode(int val) {
 *         this.val = val;
 *         this.left = this.right = null;
 *     }
 * }
 */
public class Solution {
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    public void invertBinaryTree(TreeNode root) {
        TreeNode tmp = root.left;
        root.left= root.right;
        root.right = tmp;
        if (root.left != null)
        this.invertBinaryTree(root.left);
        if (root.right != null)
        this.invertBinaryTree(root.right);
    }
}
