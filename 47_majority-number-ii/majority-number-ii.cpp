/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/majority-number-ii
@Language: C++
@Datetime: 16-06-06 03:12
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        if(nums.empty())
            return 0;
        int major;
        int length = nums.size();
        sort(nums.begin(), nums.end());
        
        int start = 0;
        int cnt = 0;
        for(int i =0; i<length; i++){
            if(nums[i] == nums[start]){
                if(++cnt * 3 > length){
                    return nums[i];
                }
            }else{
                start = i;
                cnt = 1;
            }
        }
        return -1;
    }
};
