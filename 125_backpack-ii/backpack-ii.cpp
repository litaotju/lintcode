/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/backpack-ii
@Language: C++
@Datetime: 16-06-08 05:13
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> A, vector<int> V) {
        vector<int> prev(m+1,0), cur(m+1, 0);
        if(A.empty()|| m<=0|| V.empty()|| A.size()!=V.size())
            return 0;
        int j=0;
        for(; j<= m; j++){
            if(A[0]<=j)
                prev[j] = V[0];
        }
        
        for(int i=1; i<A.size(); i++){
            for(int j=0; j<=m; j++){
                if(A[i]<=j)
                    cur[j] = max(V[i]+ prev[j-A[i]], prev[j]);
                else
                    cur[j] = prev[j];
            }
            prev = cur;
        }
        return prev[m];
    }
};