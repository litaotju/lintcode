/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/evaluate-reverse-polish-notation
@Language: C++
@Datetime: 16-06-13 06:35
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if(tokens.empty())
            return 0;
        stack<int> numbers;
        for(int i =0; i< tokens.size(); i++){
            string & cur = tokens[i];
            if(cur== "+"||cur=="-"||cur=="*" || cur=="/" ){
                int second = numbers.top();
                numbers.pop();
                int first = numbers.top();
                numbers.pop();
                int result;
                if(cur=="+") result = first+second;
                else if(cur=="-") result = first-second;
                else if(cur=="/") result = first/second;
                else result = first*second;
                numbers.push(result);
            }else{
                numbers.push(stoi(cur));
            }
        }
        return numbers.top();
    }
};