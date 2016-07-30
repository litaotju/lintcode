/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/house-robber-ii
@Language: C++
@Datetime: 16-06-14 13:18
*/

class Solution {
public:
    /**
     * @param nums: An array of non-negative integers.
     * return: The maximum amount of money you can rob tonight
     */
    int houseRobber2(vector<int>& nums) {
        // write your code here
        if(nums.empty())
            return 0;
        if(nums.size() ==1 )
            return nums[0];
        int max12 = max(nums[0], nums[1]);
        if(nums.size()==2)
            return max12;
        if(nums.size()==3)
            return max(max12, nums[2]);
        return max(nums.back()+houseRobber(nums, 1, nums.size()-3), 
                                houseRobber(nums, 0, nums.size()-2));
    }
    
private:
    int houseRobber(vector<int>& nums, int start, int end){
        if(end<start|| start <0 || end>nums.size()-1)
            return 0;
        if(end-start==1)
            return nums[start];
        if(end-start==2)
            return max(nums[start], nums[end]);
        int lastLast = nums[start], last = max(lastLast, nums[start+1]);
        int final;
        for(int i = start+2; i <=end; i++){
            final = max(nums[i]+lastLast, last);
            lastLast = last;
            last = final;
        }
        return final;
    }
};