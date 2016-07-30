/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/backpack
@Language: C++
@Datetime: 16-07-20 03:46
*/

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        if(A.empty()|| m<=0)
            return 0;
            
        vector<vector<int> > bp(2, vector<int>(m+1, 0) );
        
        for(int j=1; j<=m; j++){
            bp[0][j] = j>A[0]? A[0]:0;
        }
        
        int i=0;
        for(int row=1; row<A.size(); row++){
            for(int j=1; j<=m; j++){
                i = row%2==0 ? 0: 1;
                bp[i][j] =  j >= A[row] ? max(A[row]+bp[1-i][j-A[row]], bp[1-i][j]):
                                        bp[1-i][j];
            }
        }
        
        return bp[i].back();
    }
};