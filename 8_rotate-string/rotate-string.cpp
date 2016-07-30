/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/rotate-string
@Language: C++
@Datetime: 16-03-03 14:39
*/

class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
        int length = str.length();
        if(length == 0 || offset == 0){
            return;
        }
        char c;
        offset = offset % length;
        while(offset > 0 ){
            for(int i = length-1; i > 0 ; i --){
               c = str[i];
               str[i] = str[i-1];
               str[i-1] = c;
            }
            offset --;
        }
    }
};
