/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-ii
@Language: C++
@Datetime: 16-06-08 04:04
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int maxProfit =0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1])
                maxProfit += (prices[i]-prices[i-1]);
        }
        return maxProfit;
    }
};