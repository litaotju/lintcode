/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/fast-power
@Language: C++
@Datetime: 16-02-22 02:30
*/

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        long long r = 1 ;
        long long base = a;
        if(b==0){
            return 0;
        }
        while(n!=0){
            if( n&1){
                r =(r*base) %b;
            }
            base = (base*base)%b;
            n = n>>1;
        }
        return (int)(r%b);
    }
};