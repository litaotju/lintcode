/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: C++
@Datetime: 16-07-17 14:56
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        if(A.empty())
            return;
        for(int i=0; i < A.size(); i++){
            for(int j=0; j < A.size()-i-1; j++){
                if(A[j]>A[j+1]){
                    int temp = A[j];
                    A[j] = A[j+1];
                    A[j+1] = temp;
                }
            }
        }
    }
};