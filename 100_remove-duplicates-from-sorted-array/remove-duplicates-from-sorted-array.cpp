/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/remove-duplicates-from-sorted-array
@Language: C++
@Datetime: 16-03-11 12:46
*/

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        
        if(nums.size() == 0){
            return 0;
        }
        vector<int>::iterator slow, fast;
        fast = nums.begin();
        slow = nums.begin();
        
        while(fast != nums.end()){
            while( fast != nums.end() && *fast == *slow ){
                fast ++;
            }
            if(fast != slow){
               fast = nums.erase(slow + 1 , fast);
               slow = fast;
            }
        }
        return nums.size();
    }
};