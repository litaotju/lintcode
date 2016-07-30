/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/singleton
@Language: Java
@Datetime: 16-04-26 01:51
*/

class Solution {
    /**
     * @return: The same instance of this class every time
     */
    private static Solution s=null;
    public static Solution getInstance() {
        // write your code here
        if( s!=null){
            return s;
        }else{
            s = new Solution();
            return s;
        }
    }
    
    private Solution(){
        return;
    }
};