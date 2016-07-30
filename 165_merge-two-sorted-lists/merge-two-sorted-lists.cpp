/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-lists
@Language: C++
@Datetime: 16-02-21 06:06
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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL && l2==NULL){
            return NULL;
        }
        else if(l1 ==NULL){
            return l2;
        }
        else if(l2==NULL){
            return l1;
        }
        ListNode *head;
        if ((l1->val) > (l2->val)){
            head = l2;
            l2 = l2->next;
        }
        else{
            head = l1;
            l1 = l1->next;
        }
        
        ListNode *current, *next;
        current = head;
        
        while( l1!=NULL && l2 !=NULL) {
            if(l1->val > l2->val ){
                next = l2;
                l2 = l2->next;
            }
            else{
                next = l1;
                l1 = l1->next;
            }
            current->next = next;
            current = next;
        }
        if(l1 == NULL && l2!=NULL){
            current->next = l2;
        }
        else if(l1!=NULL && l2==NULL){
            current->next = l1;
        }
        return head;
    }
};