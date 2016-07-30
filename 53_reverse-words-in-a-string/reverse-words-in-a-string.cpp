/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/reverse-words-in-a-string
@Language: C++
@Datetime: 16-03-03 14:23
*/

class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        stack<string> sentence;
        string tmp;
        int size = s.size();
        
        bool  appending = false;
        for(int i = 0; i < size; i++){
            if( s[i] == ' '){
                if(appending){
                    appending = false;
                    sentence.push(tmp);
                    tmp.clear();
                }
            }else {
                if(!appending){
                    appending = true;
                }
                tmp.append(1, s[i]);
            }
        }
        
        if(appending){
            sentence.push(tmp);
            tmp.clear();
        }
        string ret;
        while(!sentence.empty()){
            ret += sentence.top();
            sentence.pop();
            ret.append(1,' ');
        }
        return ret;
    }
};