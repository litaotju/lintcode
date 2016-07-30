/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/majority-number
@Language: C++
@Datetime: 16-02-24 12:55
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
        if(nums.empty())
            return 0;

        int middle = nums.size()/2;
        int start = 0;
        int end = nums.size()-1;
        int index = partition(nums, start, end);
        
        while(index != middle){
            if(index < middle ){
                start = index + 1;
                index = partition(nums, start, end);
            }
            else{
                end = index - 1;
                index = partition(nums, start, end);
            }
        }
        return nums[index];
    }
    
    int partition( vector<int> & nums, int start, int end){
        if(start > end)
            return 0;
        int i = start - 1;
        int x = nums[end];
        
        int tmp;
        for(int j= start; j < end; j++){
            if( nums[j] <= x ){
                i++;
                tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
        }
        tmp = nums[ ++i ];
        nums[i] = x;
        nums[end] = tmp;
        return i;
    }
};
