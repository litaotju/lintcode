/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/a-b-problem
@Language: C++
@Datetime: 16-07-17 15:14
*/

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // write your code here, try to do it without arithmetic operators.
        bool carry = false;
        int sum = 0;
        for(int i =0; i<32; i++){
            bool A = static_cast<bool>((1<<i)&a);
            bool B = static_cast<bool>((1<<i)&b);
            if (A^B^carry)
                sum = sum | (1<<i);
            carry = A&B | A&carry | B&carry;
        }
        return sum;
    }
};