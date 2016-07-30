# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: Python
@Datetime: 16-06-13 14:40
'''

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    """
    @param inorder : A list of integers that inorder traversal of a tree
    @param postorder : A list of integers that postorder traversal of a tree
    @return : Root of a tree
    """
    def buildTree(self, inorder, postorder):
        # write your code here
        if not inorder:
            return None
        if len(inorder) == 1:
            return TreeNode(inorder[0])
        root = TreeNode(postorder[-1])
        rootIndexInorder = inorder.index(root.val)
        if rootIndexInorder != 0:
            root.left = self.buildTree(inorder[:rootIndexInorder], postorder[:rootIndexInorder])
        if rootIndexInorder != len(inorder)-1:
            root.right = self.buildTree(inorder[rootIndexInorder+1: ], postorder[rootIndexInorder:-1])
        return root