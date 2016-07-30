/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/permutation-index
@Language: C++
@Datetime: 16-05-28 07:52
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        // Write your code here
        if(A.empty()){
            return 1;
        }
        long long index = 1;
        int position  = 2;
        long long  factor = 1;
        for(int p = A.size()-2; p>=0; p--){
            int successors  = 0;
            for( int j = p+1; j < A.size(); j++){
                if(A[j] < A[p]){
                    successors ++;
                }
            }
            index += factor*successors;
            factor *= position;
            position ++;
        }
        return index;
    }
};