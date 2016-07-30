/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/plus-one
@Language: C++
@Datetime: 16-05-26 08:09
*/

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        // Write your code her
        vector<int> result;
        if(digits.empty()){
            result.push_back(1);
            return result;
        }
        deque<int> result_deque;
        int carry = 1;
        int sum;
        int index = digits.size()-1;
        while(carry != 0 && index >=0){
            sum = (digits[index] + carry) %10;
            result_deque.push_front(sum);
            carry =(digits[index] +carry) >= 10 ? 1: 0;
            --index;
        }
        if(carry != 0){
            result_deque.push_front(carry);
        }
        while(index >= 0){
            result_deque.push_front(digits[index--]);
        }
        for(int i=0; i<result_deque.size(); i++){
            result.push_back(result_deque[i]);
        }
        
        return result;
    }
};