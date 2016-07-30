/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/delete-node-in-the-middle-of-singly-linked-list
@Language: C++
@Datetime: 16-02-21 02:35
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        
        if (!node){
            return;
        }
        
        //将下一个元素复制当当前的元素的位置， 然后释放下一个元素的内存。
        ListNode * p_next;
        p_next = node->next;
        node->val = p_next->val;
        node->next = p_next->next;
        delete p_next;
        p_next = NULL;
    }
};