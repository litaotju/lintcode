/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/intersection-of-two-linked-lists
@Language: C++
@Datetime: 16-03-03 08:59
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
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * itersectionNode = NULL;
        if(headA == NULL || headB == NULL){
            return itersectionNode;
        }
        ListNode * p = headA;
        int lengthA = 0, lengthB = 0;
        while( p != NULL){
            p = p-> next;
            lengthA ++;
        }
        p = headB;
        while( p != NULL){
            p = p-> next;
            lengthB ++;
        }
        ListNode * pAnother;
        p = lengthA > lengthB ? headA:headB;
        pAnother = lengthA > lengthB ? headB:headA;
        
        int diff = lengthA > lengthB? (lengthA-lengthB): (lengthB-lengthA);
        for(int i =0; i < diff; i++){
            p = p->next;
        }
        
        while(p != NULL){
            if( p == pAnother){
                itersectionNode = p;
                break;
            } else {
                p = p->next;
                pAnother = pAnother->next;
            }
        }
        return itersectionNode;
    }
};