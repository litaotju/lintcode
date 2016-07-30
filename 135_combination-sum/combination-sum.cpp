/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/combination-sum
@Language: C++
@Datetime: 16-07-17 12:06
*/

class Solution {
public:
    /**
     * @param candidates: A list of integers
     * @param target:An integer
     * @return: A list of lists of integers
     */
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // write your code here
        vector<vector<int> > result;
        if(candidates.empty())
            return result;
        int start= 0;
        sort(candidates.begin(), candidates.end());
        vector<int > prefix;
        combinationSum(result, prefix, candidates, 0, target);
    }
    
private:
    void combinationSum(vector<vector <int> > & result, vector<int > prefix, 
            vector<int> & candidates, int start, int target){
        if(start == candidates.size())
            return;
        if(0==target){
            if(!prefix.empty())
                result.push_back(prefix);
            return;
        }
        //如果目标已经比第一个数小了，那么后面的每一个数都大于目标数据，可以直接返回
        if(target < candidates[start]){
            return;
        }
        
        int first = candidates[start];
        //包含第一个数的情况
        prefix.push_back(first);
        combinationSum(result, prefix, candidates, start, target-first);
        prefix.pop_back();
        
        //不包含第一个数的情况
        combinationSum(result, prefix, candidates, start+1, target);
    }
};