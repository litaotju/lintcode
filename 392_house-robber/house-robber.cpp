/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/house-robber
@Language: C++
@Datetime: 16-06-14 12:54
*/

class Solution {
public:
    /**
     * @param A: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    long long houseRobber(vector<int> A) {
        if(A.empty())
            return 0;
        if(A.size()==1)
            return A[0];
        if(A.size()==2)
            return max(A[0], A[1]);
        long long lastLast = A[0], last = A[1], final = 0;
        for(int i =2; i < A.size(); i++){
            final = max(A[i]+lastLast, last);
            lastLast = last;
            last = final;
        }
        return final;
    }
};