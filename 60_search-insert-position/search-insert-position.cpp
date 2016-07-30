/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/search-insert-position
@Language: C++
@Datetime: 16-05-26 16:05
*/

class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if(A.empty())
            return 0;
        return _searchInsert(A, 0, (int)(A.size()-1), target);
    }
    int _searchInsert(const vector<int> & A, int start, int end, int target){
        if(target < A[start])
            return start;
        if(target > A[end])
            return end+1;
        if( end - start == 1){
            if(start == 0 )
                return start;
            else
                return start +1;
        }
        int mid = start + (end-start)/2;
        if(A[mid] == target)
            return mid;
        if(A[mid] > target){
            return  _searchInsert(A, start, mid, target);
        }else{
            return  _searchInsert(A, mid, end, target);
        }
    }
};