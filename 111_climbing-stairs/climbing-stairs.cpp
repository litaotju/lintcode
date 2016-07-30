/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/climbing-stairs
@Language: C++
@Datetime: 16-02-22 02:35
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        int fn_1 = 1;
        int fn_2 = 2;
        int fn;
        if(n<=0){
            return 1;
        }
        if( n <= 2){
            return n;
        }
        for(int i=3; i<=n; i++){
            fn = fn_1 + fn_2;
            fn_1 = fn_2;
            fn_2 = fn;
        }
        return fn;
    }
};
