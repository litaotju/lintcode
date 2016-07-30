/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/restore-ip-addresses
@Language: C++
@Datetime: 16-06-18 04:08
*/

class Solution {
public:
    /**
     * @param s the IP string
     * @return All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string& s) {
        vector<string> result;
        string prefix;
        if(s.empty() || s.size()<4)
            return result;
        restoreIpAddress(prefix, 0, s, result);
        return result;
    }
    
private:
   void  restoreIpAddress(string prefix, int n, string s, vector<string> & result){
        if(s.empty())
            return;
        if(n==3){
            if(isLeagalIPSec(s)){
                //关键还要检验IP的某一段的合法性
                result.push_back(prefix+s);
            }
            return;
        }
        for(int i=1; i<=3 && i <= s.size(); i++){
            //分别取前1位，2位，3位
            string append = s.substr(0,i);
            if(isLeagalIPSec(append)){
                restoreIpAddress(prefix+append+'.', n+1, s.substr(i), result);
            }else{
                break;
            }
        }
    }
    
    inline bool isLeagalIPSec (string s){
        return !s.empty() && stoi(s)<=255 && stoi(s)>=0 && (s[0]=='0'&&s.size()==1 ||s[0]!='0');
    }
};