# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/longest-words
@Language: Python
@Datetime: 15-10-06 13:44
'''

class Solution:
    # @param dictionary: a list of strings
    # @return: a list of strings
    def longestWords(self, dictionary):
        # write your code here
        max_length = 0
        dictdict = {}
        for i in range(0, len(dictionary)):
            length = len(dictionary[i])
            if length > max_length:
                max_length = length
            if not dictdict.has_key(length):
                dictdict[length]=[]
            dictdict[length].append(dictionary[i])
        return dictdict[max_length]
            