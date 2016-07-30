/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/majority-number-iii
@Language: C++
@Datetime: 16-06-06 03:15
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        if(nums.empty())
            return 0;
        sort(nums.begin(), nums.end());
        int length = nums.size();
        int start =0;
        int cnt =0;
        for(int i =0; i<length; i++){
            if(nums[i]==nums[start]){
                if(++cnt*k > length){
                    return nums[i];
                }
            }else{
                start = i;
                cnt =1;
            }
        }
        return -1;
    }
};
