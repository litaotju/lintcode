/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/flip-bits
@Language: C++
@Datetime: 16-05-26 16:17
*/

class Solution {
public:
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int bitSwapRequired(int a, int b) {
        // write your code here
        int c  = a ^ b;
        int cnt =0;
        while(c){
             c &= (c -1) ;
                cnt++;
        }
        return cnt;
    }
};