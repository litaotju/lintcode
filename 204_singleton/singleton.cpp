/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/singleton
@Language: C++
@Datetime: 16-04-26 02:05
*/

class Solution {
private:
    Solution(){
    }
    

public:
    /**
     * @return: The same instance of this class every time
     */
    
    static Solution* getInstance() {
        // write your code here
        static Solution instance;
        return &instance;
    }

};