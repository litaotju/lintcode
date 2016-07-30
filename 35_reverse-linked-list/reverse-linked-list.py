# coding:utf-8
'''
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/reverse-linked-list
@Language: Python
@Datetime: 15-10-05 16:23
'''

"""
Definition of ListNode

class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: The first node of the linked list.
    @return: You should return the head of the reversed linked list. 
                  Reverse it in-place.
    """
    def reverse(self, head):
        # write your code here
        reverse = None
        while(head):
            tmp = head
            head = head.next
            tmp.next = reverse
            reverse = tmp
        return reverse