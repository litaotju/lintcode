/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/move-zeroes
@Language: C++
@Datetime: 16-07-29 13:05
*/

class Solution {
public:
    /**
     * @param nums an integer array
     * @return nothing, do this in-place
     */
    typedef vector<int>::iterator viter;
    void moveZeroes(vector<int>& nums) {
        if(nums.empty())
            return;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]==0)
                continue;
            int j  = i-1;
            int value = nums[i];
            for(; j>=0; j--){
                if(nums[j]!=0)
                    break;
                nums[j+1] = nums[j];
            }
            nums[j+1] = value;
        }
    }
};