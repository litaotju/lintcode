/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/longest-common-subsequence
@Language: C++
@Datetime: 16-07-20 02:12
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if(A.empty() || B.empty())
            return 0;
        vector<vector<int> > matrix (A.size(), vector<int>(B.size(), 0));
        
        matrix[0][0] = A[0]==B[0]? 1:0;
        
        for(int i=1; i<A.size();i++){
            matrix[i][0] = A[i]==B[0]? 1: matrix[i-1][0];    
        }
        for(int j=1; j<B.size(); j++){
            matrix[0][j] = B[j]==A[0]? 1: matrix[0][j-1];
        }
        
        for(int i =1; i<A.size(); i++){
            for(int j=1; j<B.size(); j++){
                matrix[i][j] = A[i]==B[j] ? matrix[i-1][j-1]+1 :
                            max(matrix[i-1][j], matrix[i][j-1]);
            }
        }
        
        return matrix.back().back();
    }
};
