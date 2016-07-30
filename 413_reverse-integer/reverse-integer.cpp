/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/reverse-integer
@Language: C++
@Datetime: 16-05-26 07:40
*/

#include<cmath>
#include<limits>
class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        long long result = 0;
        long long max = std::numeric_limits<int>::max();
        bool ispos = (n>=0);
        n = abs(n);
        int lastdigit = 0;
        while(n !=0 ){
            lastdigit = n%10;
            n /= 10;
            result = result*10 + lastdigit;
            if(result > max)
                return 0;
        }
        return (ispos == true)? result : (0-result);
    }
};