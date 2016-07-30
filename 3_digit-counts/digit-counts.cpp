/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/digit-counts
@Language: C++
@Datetime: 16-03-03 10:50
*/

class Solution {
public:
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        int cnt = 0;
        for(int i = 0; i<= n; i++){
            cnt += numberofK(i, k);
        }
        return cnt;
    }
    
    int numberofK(int i, int k){
        char * s = new char[100];
        sprintf(s, "%d", i);
        int cnt = 0;
        for(;*s!='\0';s++){
            if( (*s - '0') == k)
                cnt ++;
        }
        return cnt;
    }
};