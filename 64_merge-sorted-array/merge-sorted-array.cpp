/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/merge-sorted-array
@Language: C++
@Datetime: 16-03-11 12:56
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int curA = m-1;
        int curB = n-1;
        int tail = m + n - 1;
        
        while( curA >= 0 && curB >= 0){
                A[tail--] = (A[curA] >= B[curB]) ? A[curA--] : B[curB--];
        }
        
        if(curA < 0){
            while(curB >= 0){
                A[tail --] = B[curB--];
            }
        }
    }
};