# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/length-of-last-word
@Language: Python
@Datetime: 15-10-06 14:39
'''

class Solution:
    # @param {string} s A string
    # @return {int} the length of last word
    def lengthOfLastWord(self, s):
        # Write your code here
        last = 0
        current = 0
        first = True
        for i in range(0, len(s)):
            if s[i] == " ":
                if first:
                    last = current
                    current = 0
                    first = False
                else:
                    pass
            else:
                first = True
                current += 1
        if current != 0:
            last = current
        return last