/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/best-time-to-buy-and-sell-stock-iii
@Language: C++
@Datetime: 16-06-13 02:27
*/

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
     
     
    int maxProfit(vector<int> &prices) {
        if(prices.empty())
            return 0;
        vector<int> profit_front(prices.size(),0);
        vector<int> profit_back(prices.size(), 0);

        // i天之前交易一次或者不交易的最大利润
        int lowest = prices[0];
        for(size_t i = 1; i<prices.size(); i++){
            //i天之前卖出能获得的最大利润是，之前能获得的最大利润和 如果今天卖出，则今天的价格和之前的最低价格之间的价差
            profit_front[i] = max(profit_front[i-1], prices[i]-lowest);
            lowest = min(lowest, prices[i]);
        }
        
    
        int highest = prices[prices.size()-1];
        ///如果把这里面的循环变量i改为size_t类型，就会出错
        //因为，变为0之后，size_t类型的数--，还是会得到一个正整数值
        for(int i = prices.size()-2; i>=0; i--){
            //假设i天之后买入的最大利润是，在之后的最高价格的一天卖出
            profit_back[i] = max(profit_back[i+1], highest-prices[i]);
            //更新最高价格
            highest = max(highest, prices[i]);
        }
        
        int result = 0;
        for(size_t i =0; i<prices.size(); i++){
           result = max(result, profit_front[i]+profit_back[i]);
        }
        return result;
    }
};