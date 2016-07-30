/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/3sum-closest
@Language: C++
@Datetime: 16-06-08 07:25
*/

class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        if(nums.size()<=3)
            return accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for(int i =0; i<nums.size()-2; i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                int temp = nums[i]+nums[j]+nums[k];
                if(abs(temp-target) < abs(result-target))
                    result = temp;
                if(result == target)
                    return result;
                temp > target ? --k: ++j;
            }
        }
        return result;
    }
};
