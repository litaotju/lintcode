/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/add-two-numbers
@Language: C++
@Datetime: 16-05-24 09:14
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
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
     ListNode *addLists(ListNode *l1, ListNode *l2){
        if(l1 == NULL || l1 == NULL)
            return NULL;
        ListNode * head = NULL;
        ListNode * last = NULL;
        int sum = 0;
        int carry = 0;
        while(l1!=NULL || l2!=NULL){
            sum = 0;
            if(l1){
                sum += l1->val;
                
            }
            if(l2){
                sum += l2->val;
            }
            sum += carry;
            carry = sum /10;
            ListNode * x = new ListNode(sum %10);
            if(head == NULL){
                head = x;
                last = x;
            }else{
                last->next = x;
                last = x;
            }
            if(l1!=NULL){
                l1 = l1->next;
            }
            if(l2!=NULL){
                l2 = l2->next;
            }
        }
        if(carry != 0){
            ListNode *x = new ListNode(carry);
            last ->next = x;
        }
        return head;
     }
    /*
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        // write your code here
        ListNode ** temp = new ListNode*;
        int c = _addLists(l1, l2, temp);
        if( c != 0){
            ListNode * real_head = new ListNode(c);
            real_head -> next = *temp;
            *temp = real_head;
        }
        return *temp;
    }
 
    int _addLists(ListNode *l1, ListNode *l2, ListNode **result){
        if(l1->next== NULL && l2->next == NULL){
            ListNode * last = new ListNode;
            last->next = NULL;
            last->val = (l1->val + l2->val) % 10;
            *result = last;
            return (l1->val + l2->val) / 10;
        }
        ListNode *last = new ListNode;
        int sum = l1->val + l2->val + _addLists(l1->next, l2->next, result);
        last->val = sum % 10;
        last->next = *result;
        *result = last;
        return sum/10;
    }
    */
};