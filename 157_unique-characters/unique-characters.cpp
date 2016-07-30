/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/unique-characters
@Language: C++
@Datetime: 16-07-29 13:13
*/

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        if(str.empty())
            return true;
        vector<bool> has_one(128, false);
        for(int i =0; i <str.size(); i++){
            int key =  static_cast<int>(str[i]);
            if(has_one[key])
                return false;
            has_one[key] = true;
        }
        return true;
    }
};