/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-list
@Language: C++
@Datetime: 16-03-07 04:07
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
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode * behind = head;
        ListNode * before = head;
        
        while(before != NULL ){
            while( before -> val == behind->val){
                ListNode * tmp = before ->next;
                if(before != behind){
                    delete before;
                }
                before = tmp;
                if(before == NULL){
                    break;
                }
            }
            behind -> next =  before;
            behind = behind ->next;
        }
        return head;
    }

};