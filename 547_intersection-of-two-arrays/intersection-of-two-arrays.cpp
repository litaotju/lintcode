/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/intersection-of-two-arrays
@Language: C++
@Datetime: 16-07-26 14:43
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
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> result;
        while(index1 < length1 && index2 < length2){
            if(nums1[index1]==nums2[index2]){
                if(result.empty() || result.back() != nums1[index1])
                    result.push_back(nums1[index1]);
                index1++;
                index2++;
            }
            else if(nums1[index1] < nums2[index2]){
                index1++;
            }else{
                index2++;
            }
        }
        return result;
    }
};