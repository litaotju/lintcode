# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array
@Language: Python
@Datetime: 15-12-14 03:26
'''

class Solution:
    # @param num: a rotated sorted array
    # @return: the minimum number in the array
    def findMin(self, num):
        p1 = 0
        p2 = len(num)-1
        pm = p1
        while( num[p1] >= num[p2] ):
            if (p2 - p1) == 1:
                pm = p2
                break
            else:
                pm = (p1+p2)/2
                if num[pm] >= num[p1]:
                    p1 = pm
                else:
                    p2 = pm
        return num[pm]
            