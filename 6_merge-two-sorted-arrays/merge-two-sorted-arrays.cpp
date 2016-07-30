/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/merge-two-sorted-arrays
@Language: C++
@Datetime: 16-05-26 14:00
*/

#include <algorithm>
class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        int indexa=0,indexb=0;
        vector<int> result(A.size()+B.size(), 0);
        int index = 0;
        while(indexa < A.size() &&  indexb < B.size()){
            if(A[indexa] < B[indexb]){
                result[index++] = A[indexa++];
                
            }else{
                result[index++] = B[indexb++];
            }
        }
        if(indexa < A.size()){
            copy(A.begin()+indexa, A.end(), result.begin()+index);
        }
        if (indexb < B.size()){
            copy(B.begin()+indexb, B.end(), result.begin()+index);
        }
        return result;
    }
};