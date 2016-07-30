/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii
@Language: C++
@Datetime: 16-06-08 03:44
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if(nums.empty())
            return 0;
        if(nums.size() < 3)
            return nums.size();
        for(auto iter = begin(nums)+2; iter!=end(nums); iter++){
            while( *iter== *(iter-1) && *iter== *(iter-2) && iter!=end(nums)){
                iter = nums.erase(iter)-1;
            }
        }
        return nums.size();
    }
};