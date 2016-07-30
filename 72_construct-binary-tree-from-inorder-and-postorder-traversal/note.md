```
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/construct-binary-tree-from-inorder-and-postorder-traversal
@Language: Markdown
@Datetime: 16-06-13 14:40
```

X序遍历指的是， root节点在X。

前序遍历： 中-左子树-右子树
中序遍历：左子树-中-右子树
后序遍历：左子树-右子树-中


所以 inorder =  [ <左子树inorde> root <右子树inorder> ]
       postinoder = [<左子树postorder> <右子树postorder> root]

