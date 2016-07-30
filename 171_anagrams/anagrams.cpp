/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 16-03-07 14:33
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        map<string, int> fre;
        for(int i =0; i <strs.size(); i++){
            fre[ hashOfString(strs[i]) ] += 1;
        }
        vector<string> ret;
        map<string, int>::iterator it = fre.begin();
        
        for( ; it != fre.end(); it++){
            for(int i=0; i<strs.size(); i++){
                if(it ->second > 1 && it->first == hashOfString(strs[i])){
                    ret.push_back( strs[i]);
                }
            }
        }
        return ret;
    }
    
    string hashOfString(string s){
        string result;
        int * fre= new int[26];
        for(int i = 0; i< 26; i++){
            fre[i] = 0;
        }
        for(int i = 0; i < s.size(); i++){
            fre[ s[i] -'a'] += 1;
        }
        for(int i = 0; i< 26; i++){
            if(fre[i] != 0){
                result.append(fre[i], 'a'+i);
            }
        }
        return result;
    }
};
