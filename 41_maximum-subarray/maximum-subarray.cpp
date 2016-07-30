/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/maximum-subarray
@Language: C++
@Datetime: 16-02-29 01:52
*/

class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        int CurSum = 0;
        int GreatestSum = 0x80000000;
        
        for (int i = 0; i < nums.size(); i++) {
            if (CurSum <= 0) {
                CurSum = nums[i];
            } else {
                CurSum += nums[i];
            }
            if (CurSum > GreatestSum) {
                GreatestSum = CurSum;
            }
        }
        return GreatestSum;
    }
};
