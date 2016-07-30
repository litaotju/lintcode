/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/two-sum
@Language: C++
@Datetime: 16-03-04 06:26
*/

class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        int one;
        int another;
        vector<int> result;
        
        for(int i =0; i< nums.size(); i++){
            if ( (target-nums[i])!= nums[i]){
                one = i;
                another = find_forth(nums, target - nums[i]);
            } else {
                one = i;
                another = find_back(nums, target - nums[i]);
            }
            
            if( another != -1 ){
                    result.push_back( min(one, another)+1 );
                    result.push_back( max(one, another)+1 );
                    break;
                }
        }
        return result;
    }
    
    
    
    int find_forth(vector<int> &nums, int target){
        for(int index = 0; index < nums.size(); index ++ )
            if(nums[index] == target)
                return index;
        return -1;
    }
    
    int find_back(vector<int> &nums, int target){
        for(int index = nums.size() -1; index >= 0; index -- )
            if(nums[index] == target)
                return index;
        return -1;
    }

};
