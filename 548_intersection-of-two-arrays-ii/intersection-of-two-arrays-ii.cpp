/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays-ii
@Language: C++
@Datetime: 16-07-28 16:18
*/

class Solution {
public:
    /**
     * @param nums1 an integer array
     * @param nums2 an integer array
     * @return an integer array
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Write your code here
        vector<int> result;
        if(nums1.empty() || nums2.empty())
            return result;
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
    
        int index1 = 0, index2 =0;
        
        while(index1<nums1.size() && index2 < nums2.size()){
            if(nums1[index1]==nums2[index2]){
                result.push_back(nums1[index1]);
                index1++;
                index2++;
                continue;
            } 
            if(nums1[index1]<nums2[index2]) {
                index1++;
            }else{
                index2++;
            }
        }
        return result;
    }
};