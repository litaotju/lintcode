/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/partition-list
@Language: C++
@Datetime: 16-06-08 03:29
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if(head== NULL)
            return head;
        ListNode *less, *gless, *bigger, *gbigger;
        gless = new ListNode;
        gbigger = new ListNode;
        less = gless;
        bigger = gbigger;
        while(head){
            if(head->val < x){
                less->next = head;
                less = less->next;
                head = head->next;
                less->next = NULL;
            }else{
                bigger->next = head;
                bigger = bigger->next;
                head = head->next;
                bigger->next = NULL;
            }

        }
        less->next = gbigger->next;
        head = gless->next;
        delete gless;
        delete gbigger;
        return head;
    }
};


