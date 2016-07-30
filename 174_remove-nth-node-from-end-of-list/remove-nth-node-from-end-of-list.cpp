/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/remove-nth-node-from-end-of-list
@Language: C++
@Datetime: 16-02-21 05:51
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
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // write your code here
        if(head == NULL || n < 0){
            return head;
        }
        ListNode * slow;
        ListNode * fast;
        slow = NULL;
        fast = head;
        for(int i = 0; i < n; i++){
            fast = fast-> next;
        }
        while(fast != NULL){
            if(slow==NULL){
                slow = head;
            }
            else{
                slow = slow->next;
            }
            fast = fast->next;
        }
        
        if(slow == NULL){
            ListNode *new_head;
            new_head = head->next;
            delete head;
            return new_head;
        }
        
        if(slow->next != NULL){
            slow -> next = slow ->next ->next;
        }else{
            slow ->next = NULL;
        }
        return head;
    }
};


