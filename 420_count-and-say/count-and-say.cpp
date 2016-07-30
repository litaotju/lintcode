/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/count-and-say
@Language: C++
@Datetime: 16-06-08 06:58
*/

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string str = "1";
        for(int i=1; i< n; i++){
            str = countAsScore(str);
        }
        return str;
    }
    
    string countAsScore(string str){
        string result;
        if(str.empty())
            return result;
        char init = str[0];
        int cnt = 1;
        int i = 1;
        bool same = false;
        for(; i<str.size(); i++){
            if(str[i] == init){
                ++cnt;
                same = true;
            }else{
                result += (char)('0' + cnt);
                result += init;
                init = str[i];
                cnt = 1;
                same = false;
            }
        }
        if(i==1){
            result += '1';
            result += init;
        }else{
            if(same == true){
                result += (char)('0' + cnt);
                result += str[i-1];
            }else{
                result += '1';
                result += str[i-1];
            }
        }
        return result;
    }
};