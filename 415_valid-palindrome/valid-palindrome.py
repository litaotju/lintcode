# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/valid-palindrome
@Language: Python
@Datetime: 15-10-06 14:23
'''

class Solution:
    # @param {string} s A string
    # @return {boolean} Whether the string is a valid palindrome
    def isPalindrome(self, s):
        # Write your code here
        begin = 0
        end = len(s)-1
        aZ = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM"
        while(begin+1 <= end):
            while(1):
                #print "begin:%d ,%s" % (begin, s[begin])
                if begin == end:
                    break
                if s[begin] not in aZ:
                    begin += 1
                else:
                    break
            while(1):
                #print "end: %d, %s" % (end, s[end] )
                if end == begin:
                    break
                if s[end] not in aZ:
                    end -=1
                else:
                    break
            if s[begin] in [s[end].lower(), s[end].upper()]:
                begin += 1
                end -=1
            else:
                return False
        return True
        