# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: Python
@Datetime: 15-10-05 16:07
'''

class Solution:
    # @param n: an integer
    # @return an integer f(n)
    def fibonacci(self, n):
        # write your code here
        f = [0, 1, 1]
        if n <= 2:
            return f[n-1]
        for i in range(2, n):
            f[2] = f[0] + f[1]
            f[0] = f[1]
            f[1] = f[2]
        return f[2]
        
