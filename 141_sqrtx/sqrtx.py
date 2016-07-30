# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/sqrtx
@Language: Python
@Datetime: 15-10-06 13:07
'''

class Solution:
    """
    @param x: An integer
    @return: The sqrt of x
    """
    def sqrt(self, x):
        # write your code here
            a = 0
            b = x
            m = 0
            while( a+1 < b):
                m = (a+b)/2
                if m**2 == x:
                    return m
                elif m**2 > x:
                    b = m-1
                else:
                    a = m
                #print "a:%d m:%d b:%d" %(a, m, b)
            if b == a+1 and b**2 <= x:
                return b
            else:
                return a
