# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/o1-check-power-of-2
@Language: Python
@Datetime: 15-10-06 12:22
'''

class Solution:
    """
    @param n: An integer
    @return: True or false
    """
    def checkPowerOf2(self, n):
        # write your code here
        if n<=0:
            return False
        return 0<n<=1 or n&(n-1)==0