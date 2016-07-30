/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/left-pad
@Language: C++
@Datetime: 16-04-26 02:24
*/

class StringUtils {
public:
    /**
     * @param originalStr the string we want to append to
     * @param size the target length of the string
     * @param padChar the character to pad to the left side of the string
     * @return a string
     */
    static string leftPad(string& originalStr, int size, char padChar=' ') {
        // Write your code here
        string ret;
        int fillLength = size - originalStr.size();
        int i = 0;
        while(i++ < fillLength){
            ret.push_back(padChar);
        }
        ret.append(originalStr);
        return ret;
    }
};
