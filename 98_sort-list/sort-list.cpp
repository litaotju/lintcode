/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/sort-list
@Language: C++
@Datetime: 16-05-28 08:21
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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if(head ==NULL || head ->next == NULL){
            return head;
        }
        
        ListNode *mid = findMid(head);
        ListNode *right = NULL;
        if(mid!=NULL){
            right = mid->next;
            mid->next = NULL;
        }
        ListNode *left = sortList(head);
        ListNode *new_right = sortList(right);
        return mergeList(left, new_right);
    }
    
    
    //找出中间节点
    ListNode *findMid(ListNode *head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode *slow = head, *fast = head->next;
        while(fast != NULL && fast ->next !=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    
    
    
    //对链表进行归并的空间复杂度为1
    ListNode *mergeList(ListNode *left, ListNode *right){
        if(left == NULL){
            return right;
        }
        if(right == NULL){
            return left;
        }
        ListNode *temp;
        if(left->val >= right->val){
            //保存right的下一个
            temp = right->next;
            //把right插入到left的最前面
            right ->next = left;
            //重新定义right和left
            left = right;
            right =temp; 
        }
        //left的第一个一定是最小的，所以只用归并出过left之外剩余的两个链表
        left ->next = mergeList(left->next, right);
        
        //返回最小的节点，也就是left
        return left;
    }
};


