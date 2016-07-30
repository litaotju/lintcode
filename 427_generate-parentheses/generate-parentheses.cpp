/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/generate-parentheses
@Language: C++
@Datetime: 16-07-17 12:20
*/

class Solution {
public:
    /**
     * @param n n pairs
     * @return All combinations of well-formed parentheses
     */
    vector<string> generateParenthesis(int n) {
        // Write your code here
        vector<string> result;
        if(n <= 0)
            return result;
        string prefix;
        MAXROUND = n;
        int numLeft = 0, numRight = 0, round = 0;
        generateParenthesis(result, prefix, numLeft, numRight, round);
        return result;
        
    }

private:
    void generateParenthesis(vector<string> & result, string prefix, 
                int numLeft, int numRight, int round){
        if(round > 2*MAXROUND)
            return;
        if(numRight > numLeft)
            return;
        if(numLeft == numRight && round == 2*MAXROUND){
            result.push_back(prefix);
            return;
        }
        prefix.push_back('(');
        generateParenthesis(result, prefix, numLeft+1, numRight, round+1);
        prefix.pop_back();
        prefix.push_back(')');
        generateParenthesis(result, prefix, numLeft, numRight+1, round+1);
    }
    
    int MAXROUND;
};
