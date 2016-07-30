/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/insertion-sort-list
@Language: C++
@Datetime: 16-05-26 12:52
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
     * @return: The head of linked list.
     */
    ListNode * insertionSortList(ListNode *head) {
        // write your code here
        if(head == NULL)
            return head;
        //ListNode *new_head =head; 注意这么写是会出错的，也不知道为什么。。。为什么？？？？？？？
        ListNode *new_head =new ListNode( head->val);
        new_head ->next = NULL;
        
        head = head->next;
        ListNode * next;
        while(head != NULL){
            next = head->next;
            if(head->val < new_head->val){
                ListNode *fuck = new ListNode(head->val);
                fuck->next = new_head;
                new_head = fuck;
            }else{
                ListNode *temp = new_head, *prev = new_head;
                while(temp != NULL && head->val >= temp->val ){
                    prev = temp;
                    temp = temp->next;
                }
                prev->next = head;
                head->next = temp;
            }
            head = next;
        }
        return new_head;
    }
};