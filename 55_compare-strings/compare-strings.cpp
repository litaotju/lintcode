/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/compare-strings
@Language: C++
@Datetime: 16-03-07 13:37
*/

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int * fre = new int[26];
        for(int i = 0; i<26;i++){
            fre[i] = 0;
        }
        for(int index = 0; index < A.size(); index ++){
            fre[ A[index]-'A' ] += 1;
        }
        for(int index = 0; index < B.size(); index ++){
            if( --fre[ B[index] - 'A'] < 0)
                return false;
        }
        return true;
    }
};
