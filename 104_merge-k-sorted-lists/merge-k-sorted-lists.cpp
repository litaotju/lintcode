/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/merge-k-sorted-lists
@Language: C++
@Datetime: 16-06-18 04:22
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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(lists.empty())
            return NULL;
        return mergeKLists(lists, 0, lists.size()-1);
    }
private:
    ListNode *mergeKLists(vector<ListNode *> & lists, int start, int end){
        if(start < end){
            int mid = start + (end-start)/2;
            ListNode *left, *right;
            left = mergeKLists(lists, start, mid);
            right = mergeKLists(lists, mid+1, end);
            return merge(left, right);    
        }
        if(start==end){
            return lists[start];
        }
    }
    
    ListNode * merge(ListNode *l, ListNode *r){
        if(l==NULL)
            return r;
        if(r==NULL)
            return l;
        if(l->val < r->val){
            l->next = merge(l->next, r);
            return l;
        }else{
            r->next = merge(r->next, l); 
            return r;
        }
    }
};


