/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/longest-common-prefix
@Language: C++
@Datetime: 16-03-10 14:48
*/

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
    string result;
    if( strs.empty()){
        return result;
    }
    int min_length  = strs[0].size();
    for(int i = 0 ; i < strs.size(); i++){
        if( strs[i].size() < min_length){
            min_length = strs[i].size();
        }
    }
    
    if(min_length == 0){
        return result;
    }
    int lcp_length = 0;
    for( int j = 0; j < min_length; j++){
        char s = strs[0][j];
        for( int i = 1; i < strs.size(); i++){
            if( s != strs[i][j]){
                lcp_length = j;
                return strs[0].substr(0, lcp_length);
            }
        }
    }
    return strs[0].substr(0, min_length);
}
};