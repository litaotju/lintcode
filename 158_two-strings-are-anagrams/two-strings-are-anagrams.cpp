/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/two-strings-are-anagrams
@Language: C++
@Datetime: 16-03-07 13:30
*/

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        map<char, int> fres, fret;
        for(int i = 0 ; i< s.size(); i++){
            fres[ s[i] ] += 1;
            fret[ t[i] ] += 1;
        }
        
        map<char, int>::iterator its = fres.begin() ;
        for( ; its != fres.end(); its++){
            if( fret[ its->first ] != its->second){
                return false;
            }
        }
        return true;
    }
};