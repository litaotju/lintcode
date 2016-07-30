/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock
@Language: C++
@Datetime: 16-06-08 03:58
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        int maxProfit = 0;
        if(prices.empty())
            return maxProfit;
        int init = prices[0];
        for(int i = 1; i<prices.size(); i++){
            if(prices[i]>init){
                maxProfit = max(maxProfit, prices[i]-init);
            }
            else{
                init = prices[i];
            }
        }
        return maxProfit;
    }
};
