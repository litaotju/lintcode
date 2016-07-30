/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/3sum
@Language: C++
@Datetime: 16-06-06 02:56
*/

class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> >result;
        
        if(nums.size()<3)
            return result;
        
        sort(nums.begin(), nums.end());
        for(int i =0; i< nums.size()-2; i++){
            if( i>0 && nums[i] == nums[i-1])
                continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k){
                int ans = nums[i]+nums[j]+nums[k];
                if(ans == 0){
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    result.push_back(temp);
                    ++j;
                    while( j< nums.size() && nums[j]==nums[j-1])
                        ++j;
                    --k;
                    while(k>=0 && nums[k]== nums[k+1])
                        --k;
                }
                else if(ans >0){
                    --k;
                }
                else{
                    ++j;
                }
            }
            
        }
        return result;
    }
};
