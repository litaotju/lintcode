/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/combination-sum-ii
@Language: C++
@Datetime: 16-06-13 03:05
*/

class Solution {
public:
	/**
	 * @param num: Given the candidate numbers
	 * @param target: Given the target number
	 * @return: All the combinations that sum to target
	 */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // write your code here
        vector<vector<int> > result;
        vector<int> prefix;
        sort(num.begin(), num.end());
        comCore(num, 0, target, prefix, result);
        return result;
    }
private:
    void comCore(vector<int> & nums, int pos, int gap, vector<int> prefix, vector<vector<int> > & result){
        if(gap==0){
            result.push_back(prefix);
            return;
        }
        for(int i =pos; i<nums.size(); i++){
            if(gap < nums[i])
                return ;
            if(i!=pos && nums[i]== nums[i-1])
                continue;
            prefix.push_back(nums[i]);
            comCore(nums, i+1, gap-nums[i], prefix, result);
            prefix.pop_back();
        }
    }
};