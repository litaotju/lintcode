/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/remove-linked-list-elements
@Language: C++
@Datetime: 16-07-17 14:45
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        if(head == NULL)
            return NULL;
        while( head && head->val == val){
            ListNode * temp = head->next;
            delete head;
            head = temp;
        }
        ListNode * p = head;
        while(p && p->next){
            while(p->next->val == val){
                ListNode * temp = p ->next;
                p->next = p->next->next;
                delete temp;
                if(p->next == NULL)
                    break;
            }
            if(p->next != NULL){
                p = p->next;
            }
        }
        return head;
    }
};