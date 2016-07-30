/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/coins-in-a-line
@Language: C++
@Datetime: 16-06-30 03:18
*/

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
         if( n==0) return false;
         vector<bool> result(4, true);
         result[2] = false;
        
         if(n<=4)
            return result[n-1];
        
         bool last_result;
         for(int i=5; i <= n; i++){
             
             last_result =  (result[0]&& result[1]) || (result[1]&&result[2]);
             
             result[0] = result[1];
             result[1] = result[2];
             result[2] = result[3];
             result[3] = last_result;
         }
         
         return last_result;
    }
};