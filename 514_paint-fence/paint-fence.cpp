/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/paint-fence
@Language: C++
@Datetime: 16-06-28 07:53
*/

class Solution {
public:
    /**
     * @param n non-negative integer, n posts
     * @param k non-negative integer, k colors
     * @return an integer, the total number of ways
     */
    int numWays(int n, int k) {
        if(n==0)
            return 0;
        if(n==1)
            return k;
        if(n==2)
            return k*k;
        vector<int> result(n, 0);
        result[0] = k;
        result[1] = k*k;
        
        int i;
        for( i =2; i<n; i++){
            result[i] = (k-1)*(result[i-1]+result[i-2]);
        }
        return result[i-1];
    }
};