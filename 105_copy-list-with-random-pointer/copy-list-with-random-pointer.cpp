/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/copy-list-with-random-pointer
@Language: C++
@Datetime: 16-02-24 08:50
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if( head== NULL){
            return head;
        }
        
        RandomListNode * p_node;
        
        p_node = head;
        while( p_node != NULL ){
            RandomListNode * p_new_node = new RandomListNode(p_node -> label);
            p_new_node -> next = p_node -> next;
            p_node ->next      = p_new_node;
            p_node = p_new_node -> next;
        }
        
        p_node = head;
        while( p_node != NULL){
            RandomListNode * p_new_node = p_node -> next;
            if(p_node->random != NULL)
                p_new_node -> random = p_node->random-> next;
            p_node = p_new_node->next;
        }
        
        p_node = head;
        RandomListNode * new_head, *coloned_node;
        if(p_node != NULL){
            new_head = head->next;
            coloned_node = head->next;
            p_node -> next = coloned_node -> next;
            p_node = p_node->next;
        }
        
        while(p_node != NULL ){
            coloned_node->next = p_node ->next;
            coloned_node = coloned_node -> next;
            p_node-> next = coloned_node ->next;
            p_node = p_node->next;
        }
        return new_head;
    }
    
};