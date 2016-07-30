/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/combinations
@Language: C++
@Datetime: 16-06-13 03:22
*/

class Solution {
public:
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        // write your code here
        vector<vector<int> >result;
        vector<int> prefix;
        if(n <= 0 || k <=0 )
            return result;
        
        combine(n, 1, k, prefix, result);
        return result;
    }
    
    
private:
    /*
    * int n, 总共的数的个数
    * int start, 起始点
      int needed，还需要的数的个数
      int prefix, 前缀
      result，结果
    */
    //从start ~ n中选 选出needed个数，加上前缀prefix，推入到result中
    void combine(int n, int start, int needed, vector<int> prefix, vector<vector<int> > & result ){
        if(needed <= 0){
            result.push_back(prefix);
            return;
        }
        for(int i = start; i<=n; i++){
            prefix.push_back(i);
            combine(n, i+1, needed-1, prefix, result);
            prefix.pop_back();
        }
    }
};