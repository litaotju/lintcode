/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/print-numbers-by-recursion
@Language: C++
@Datetime: 16-02-21 15:14
*/

class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        vector<int> res;
        if(n == 0){
            return res;
        }
        char *number = new char[n+1];
        number[n] = '\0';
        
        for(int i=0; i< 10; i++){
            number[0] = '0'+ i;
            recursion(number, res, n, 0);
        }
        return res;
    }
    
    void recursion(char * number, vector<int> & res, int length, int index){
        if(index == (length -1)){
            int a = atoi(number);
            if(a !=0 ){
                res.push_back(a);
            }
            return;
        }
        for(int i =0; i< 10; i++){
            number[index+1] = '0' +i;
            recursion(number, res, length, index+1);
        }
    }
};