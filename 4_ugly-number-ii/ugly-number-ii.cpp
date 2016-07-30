/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/ugly-number-ii
@Language: C++
@Datetime: 16-03-03 10:01
*/

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        vector<long long > nums;
        int p3 =0;
        int p5 = 0;
        int p7 = 0;
        nums.push_back(1LL);
        long long cur;
        int index = 0;
        while(index < k){
            cur = min(min(nums[p3] *3 , nums[p5]*5), nums[p7]*7) ;
            nums.push_back(cur);
            while(nums[p3]*3 <= cur ) p3++;
            while(nums[p5]*5 <= cur ) p5++;
            while(nums[p7]*7 <= cur ) p7++;
            index ++;
        }
        return cur;
    }
};