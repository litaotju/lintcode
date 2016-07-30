/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/interleaving-string
@Language: C++
@Datetime: 16-07-20 01:56
*/

class Solution {
public:
    /**
     * Determine whether s3 is formed by interleaving of s1 and s2.
     * @param s1, s2, s3: As description.
     * @return: true of false.
     */
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.empty())
            return s2==s3;
        if(s2.empty())
            return s1==s3;
        if(s3.size() != s1.size()+s2.size())
            return false;
        
        vector<vector <bool> > result(s1.size()+1, vector<bool>(s2.size()+1, false));
        
        result[0][0] = true;
        for(int j=1; j<= s2.size(); j++){
            result[0][j] = result[0][j-1] && (s3[j-1]==s2[j-1]);
        }
        
        for(int i=1; i<=s1.size(); i++){
            result[i][0] = result[i-1][0] &&(s3[i-1]==s1[i-1]);
        }
        
        for(int i = 1; i<= s1.size(); i++){
            for(int j=1; j<=s2.size(); j++){
                result[i][j] = (s3[i+j-1]==s2[j-1]) && result[i][j-1]
                                || (s3[i+j-1]==s1[i-1] && result[i-1][j]);
            }
        }
        return result[s1.size()][s2.size()];
    }
};