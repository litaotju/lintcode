/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/palindrome-partitioning
@Language: C++
@Datetime: 16-06-18 03:39
*/

class Solution {
public:
    /**
     * @param s: A string
     * @return: A list of lists of string
     */
    vector<vector<string>> partition(string s) {
        // write your code here
        vector<vector<string> > result;
        vector<string> prefix;
        if(s.empty())
            return result;
        partition(prefix, s, result );
        return result;
    }
    
private:
    void partition(vector<string> prefix, string remained, vector<vector<string> > &result){
        if(remained.empty()){
            result.push_back(prefix);
            return;
        }
        for(int i=1; i<=remained.size(); i++){
            string last = remained.substr(0,i);
            if(isH(last)){
                prefix.push_back(last);
                partition(prefix, remained.substr(i), result);
                prefix.pop_back();
            }
        }
    }

private:
    bool isH(string s){
        if(s.empty())
            return true;
        for(int i=0, j = s.size()-1; i<s.size(); i++, j--){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
};