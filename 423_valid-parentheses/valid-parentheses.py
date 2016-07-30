# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/valid-parentheses
@Language: Python
@Datetime: 15-12-04 14:51
'''

class Solution:
    # @param {string} s A string
    # @return {boolean} whether the string is a valid parentheses
    def isValidParentheses(self, s):
        l = []
        match = {')': '(', "}": "{", "]": "["}
        for i in s:
            if len(l) == 0:
                l.append(i)
            elif match.has_key(i) and l[-1] == match[i]:
                l.pop()
            else:
                l.append(i)
        return len(l) == 0