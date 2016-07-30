/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/reverse-linked-list-ii
@Language: C++
@Datetime: 16-06-13 05:08
*/

/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(n==m)
            return head;
        ListNode *guard = new ListNode;
        guard->next = head;
        
        //stable指向了要反转的第一个节点
        ListNode *stable = guard;
        int i = 1;
        for(; i < m; i++){
            stable = stable->next;
        }
        
        //反转后的尾巴
        ListNode *rtail = stable->next;
        
        //反转后的头
        ListNode *rhead = rtail->next;
        
        ListNode *p = rtail, *q;
        for(; i<n; i++){
            //保存头的下一个节点
            q = rhead->next;
            
            //反转头的指向
            rhead->next = p;
            
            //移动p
            p = rhead;
            
            //移动头
            rhead = q;
        }
        stable->next = p;
        rtail->next = q;
        
        if(m=1)
            head =  guard->next;
        delete guard;
        return head;
    }
};
