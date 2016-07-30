/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/product-of-array-exclude-itself
@Language: C++
@Datetime: 16-03-07 04:19
*/

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long > result;
        for(int i = 0; i < nums.size(); i++){
            result.push_back( getProduct(nums, 0, i-1)* getProduct(nums, i+1, nums.size()-1));
        }
        return result;
    }
    
    long long getProduct(vector<int> & nums, int start, int end){
        if(start > nums.size()-1){
            return 1;
        }
        if(start > end){
            return 1;
        }
        if(start == end){
            return nums[start];
        }
        long long result = 1;
        for(int i = start; i <= end; i++){
            result *= nums[i];
        }
        return result;
    }
};