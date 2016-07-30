/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/happy-number
@Language: C++
@Datetime: 16-03-01 03:27
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return true if this is a happy number or false
     */
    bool isHappy(int n) {
        if(n < 1){
            return false;
        }
        unordered_set<int> showedNums;
        showedNums.insert(n);
        
        int s;
        while(true){
            s = 0;
            while(n){
                s += (n%10) * (n%10);
                n /= 10;
            }
            if( s == 1){
                return true;
            } else if( showedNums.find(s) != showedNums.end() ){
                return false;
            }
            n = s;
            showedNums.insert(s);
        }
    }
};