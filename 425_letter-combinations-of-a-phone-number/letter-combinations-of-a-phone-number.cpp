/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/letter-combinations-of-a-phone-number
@Language: C++
@Datetime: 16-06-13 07:39
*/

class Solution {
public:
    /**
     * @param digits A digital string
     * @return all posible letter combinations
     */
    Solution(){
        asString['1'] = "";
        asString['2'] = "abc";
        asString['3'] = "def";
        asString['4'] = "ghi";
        asString['5'] = "jkl";
        asString['6'] = "mno";
        asString['7'] = "qprs";
        asString['8'] = "tuv";
        asString['9'] = "wxyz";
    }
    vector<string> letterCombinations(string& digits) {
        // Write your code here
        vector<string> result;
        string prefix;
        if(digits.empty())
            return result;
        combCore(digits, 0, prefix, result);
        return result;
    }
    
private:
    map<char, string> asString;
    void combCore(string &digits, int pos, string prefix, vector<string> &result){
        if(pos == digits.size()){
            result.push_back(prefix);
            return;
        }
        //找到当前位置的可能值为cur
        string cur = asString[digits[pos]];
        for(int i = 0; i<cur.size(); i++ ){
            prefix.push_back(cur[i]);
            combCore(digits, pos+1, prefix, result);
            prefix.pop_back();
        }
    }
};