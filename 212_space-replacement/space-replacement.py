# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/space-replacement
@Language: Python
@Datetime: 15-10-05 15:42
'''

class Solution:
    # @param {char[]} string: An array of Char
    # @param {int} length: The true length of the string
    # @return {int} The true length of new string
    def replaceBlank(self, string, length):
        # Write your code here
        i = 0
        current = 0
        if not string:
            return 0
        while (i <= length):
            if string[current] == " ":
                string[current] = "%"
                string.insert(current+1, "2")
                string.insert(current+2, "0")
                current += 2
                continue
            current += 1
            i += 1
        return current