# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/single-number
@Language: Python
@Datetime: 15-10-06 06:41
'''

class Solution:
    """
    @param A : an integer array
    @return : a integer
    """
    def singleNumber(self, A):
        # write your code here
        x = 0
        for i in range(0, len(A)):
            x = x^A[i]
        return x