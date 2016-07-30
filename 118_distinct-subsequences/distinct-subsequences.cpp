/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/distinct-subsequences
@Language: C++
@Datetime: 16-06-13 07:22
*/

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if(T.empty())
            return 1;
            
        if(S.empty()||S.size()<T.size())
            return 0;
        
        //N[i][j] 表示已 S[:i]中为 N[:j] 的不同字串的个数
        //如果 S[i]==N[j] N += S[:i-1] N[:j-1]
        // N 
        vector<vector<int> > N(S.size(), vector<int>(T.size(),0));
        
        int n = S.size()-1;
        int m = T.size()-1;
        
        int indexS = 0;
        int indexT = 0;
        N[0][0] = S[0]==T[0]?1:0;
        
        for(indexS = 1; indexS<=n; indexS++){
            N[indexS][0] = S[indexS]==T[0]?1 :0;
            N[indexS][0] += N[indexS-1][0];
        }
        for(indexS = 1; indexS<=n; indexS++){
            for(indexT = 1; indexT<=m; indexT++){
                if(indexS < indexT)
                    continue;
                if(indexS == indexT){
                    N[indexS][indexT] = (S[indexS]==T[indexT])? N[indexS-1][indexT-1]:0;
                    continue;
                }else{
                    N[indexS][indexT] = (S[indexS]==T[indexT])? N[indexS-1][indexT-1] : 0;
                    N[indexS][indexT] += N[indexS-1][indexT];
                }
            }
        }
        return N[n][m];
    }
};
