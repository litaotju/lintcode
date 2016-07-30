/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/decode-ways
@Language: C++
@Datetime: 16-06-29 08:11
*/

class Solution {
public:
    /**
     * @param s a string,  encoded message
     * @return an integer, the number of ways decoding
     */
    int numDecodings(string& s) {
        if(s.empty()|| s[0]=='0')
            return 0;
        int N = s.size();
        vector<int> A(N,0);
        A[0] = 1;
        
        int i = 1;
        for( ; i<N; i++ ){
            if( s[i]=='0' ){
                // 检查合法性，如果出现非 10, 20而是其他 *0情况，则直接输出0
                if(s[i-1]!='1' && s[i-1]!='2'){
                    return 0;
                }
                if(i>=2)
                    A[i] = A[i-2];
                else
                    A[i] = 1;
                continue;
            }
            if(s[i-1]=='1'|| s[i-1]=='2'&& s[i] <='6'){
                if(i-2>=0)
                    A[i] = A[i-2] + A[i-1];
                else
                    A[i] = 2;
            }
            else{
                A[i] = A[i-1];
            }
        }
        return A[i-1];
    }
};