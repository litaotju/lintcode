/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/powx-n
@Language: C++
@Datetime: 16-06-18 04:28
*/

class Solution {
public:
    /**
     * @param x the base number
     * @param n the power number
     * @return the result
     */
    double myPow(double x, int n) {
        if(x==0){
            return 0;
        }
        if(x==1 || n==0){
            return 1;
        }
        if(n == 1)
            return x;
        if(n > 0 ){
            int mid = n/2;
            return myPow(x, mid)*myPow(x, n-mid);
        }else{
            return 1/myPow(x, -n);
        }
    }
};