# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/cosine-similarity
@Language: Python
@Datetime: 15-10-05 15:16
'''

class Solution:
    """
    @param A: An integer array.
    @param B: An integer array.
    @return: Cosine similarity.
    """
    def cosineSimilarity(self, A, B):
        # write your code here
        A_B = 0
        LA = 0
        LB = 0
        for i in range(0, len(A) ):
            A_B += A[i]*B[i]
            LA += A[i]**2
            LB += B[i]**2
        if LA == 0 or LB == 0:
            return 2.0000
        from math import sqrt
        return A_B/( sqrt(LA) * sqrt(LB) )