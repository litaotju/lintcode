# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-preorder-and-inorder-traversal
@Language: Python
@Datetime: 16-02-18 17:13
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
    @param preorder : A list of integers that preorder traversal of a tree
    @param inorder : A list of integers that inorder traversal of a tree
    @return : Root of a tree
    """
    def buildTree(self, preorder, inorder):
        # write your code here
        assert len(preorder) == len(inorder)
        if len(preorder) == 0:
            return None
        tree = TreeNode( preorder[0] )
        if len(preorder) == 1:
            return tree
        c = inorder.index( preorder[0])
        tree.left = self.buildTree( preorder[1:1+c], inorder[:c])
        tree.right = self.buildTree( preorder[1+c: ], inorder[c+1:])
        return tree