/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/ugly-number
@Language: C++
@Datetime: 16-05-23 15:44
*/

class Solution {
public:
    /**
     * @param num an integer
     * @return true if num is an ugly number or false
     */
    bool isUgly(int num) {
        int n= num;
        if(n==0)
            return false;
        while(n%2==0){
            n /=2;
        }
        while(n%3==0){
            n /=3;
        }
        while(n%5==0){
            n /= 5;
        }
        return n==1;
    }
};