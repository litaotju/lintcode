/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/maximum-product-subarray
@Language: C++
@Datetime: 16-06-14 13:50
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int maxProduct(vector<int>& nums) {
        // write your code here
        if(nums.empty())
            return 0;
        int Max = nums.front(), Min = nums.front();
        int result = Max;
        for(int i =1; i<nums.size(); i++){
            //因为数字中有负数，所以需要记录已nums[i]结尾的连续子序列的最小值。
            // 最小值可能再乘上后来的就变最大值了
            //状态转移方程
            //不论是最大最小值都必须包含 nums[i]， 如果乘上前面的比nums[i]还小，那么就等于nums自己
            int tempMax = max(nums[i], max(nums[i]*Max, nums[i]*Min));
            int tempMin = min(nums[i], min(nums[i]*Max, nums[i]*Min));
            Max = tempMax;
            Min = tempMin;
            if(Max > result)
                result = Max;
        }
        return result;
    }
};