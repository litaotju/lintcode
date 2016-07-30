# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/unique-paths
@Language: Python
@Datetime: 15-10-06 16:21
'''

class Solution:
    """
    @param n and m: positive integer(1 <= n , m <= 100)
    @return an integer
    """
    def uniquePaths(self, m, n):
        # write your code here
        x = [1]*n
        for i in range(1, m):
            for j in range(1, n):
                x[j] = x[j] + x[j-1]
        return x[n-1]