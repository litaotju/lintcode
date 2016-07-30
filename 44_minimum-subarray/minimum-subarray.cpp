/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/minimum-subarray
@Language: C++
@Datetime: 16-07-29 12:26
*/

class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        if(nums.empty())
            return 0;
        vector<int> result(nums.size(),0);
        result[0] = nums[0];
        int minSum = result[0];
        for(int i=1; i<nums.size(); i++){
            if(result[i-1] < 0){
                result[i] = result[i-1] + nums[i];
            }else{
                result[i] = nums[i];
            }
            minSum = min(minSum, result[i]);
        }
        return minSum;
    }
};
