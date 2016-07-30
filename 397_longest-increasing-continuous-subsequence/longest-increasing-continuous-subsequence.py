# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: Python
@Datetime: 15-10-06 17:06
'''

class Solution:
    # @param {int[]} A an array of Integer
    # @return {int}  an integer
    def longestIncreasingContinuousSubsequence(self, A):
        # Write your code here
        l = len(A)
        if l < 2:
            return l
        up = True if A[1] > A[0] else False
        current = 2
        longest = 2
        for i in range(2, l):
            if up:
                if A[i] > A[i-1]:
                    current += 1
                else:
                    current = 2
                    up = False
            else:
                if A[i] < A[i-1]:
                    current += 1
                else:
                    current = 2
                    up = True
            longest = current if (current > longest) else longest
        return longest