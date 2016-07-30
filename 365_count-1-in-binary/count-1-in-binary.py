# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/count-1-in-binary
@Language: Python
@Datetime: 15-10-05 15:49
'''

class Solution:
    # @param num: an integer
    # @return: an integer, the number of ones in num
    def countOnes(self, num):
        # write your code here
        x = 0
        while(num):
            if (num%2):
                x +=1
            num = num / 2
        return x