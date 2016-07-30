/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/longest-increasing-continuous-subsequence
@Language: C++
@Datetime: 16-07-20 02:27
*/

class Solution {
public:
    /**
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        int a = lics(A);
        reverse(A.begin(), A.end());
        int b = lics(A);
        return max(a, b);
    }
    
private:
    int lics( vector<int> A){
        if(A.empty())
            return 0;
        vector<int> l(A.size(), 1);
        int max = 1;
        for(int i=1; i<A.size(); i++){
            l[i] = A[i]>A[i-1] ? l[i-1]+1: l[i];
            if(l[i]>max)
                max = l[i];
        }
        return max;
    }
};