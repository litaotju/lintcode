/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/partition-array-by-odd-and-even
@Language: C++
@Datetime: 16-02-21 02:21
*/

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        // write your code here
        vector<int>::size_type i,j;
        i = 0;
        j = nums.size();
        while(i != j){
            if(nums[i]%2 == 1 && nums[j]%2==0){
                ++i;
                ++j;
            }
            else if(nums[i]%2 == 0 && nums[j]%2 == 1){
                int tmp;
                tmp = nums[i];
                nums[i++]=nums[j];
                nums[j++]=tmp;
            }
            else if(nums[i]%2 == 0){
                --j;
            }
            else{
                ++i;
            }
        }
    }
};