/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/container-with-most-water
@Language: C++
@Datetime: 16-06-13 04:01
*/

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: an integer
     */
    
    //n^2复杂度
    /*
    int maxArea(vector<int> &heights) {
        // write your code here
        if(heights.empty())
            return 0;
        int area = 0;
        for(int i = 0; i<heights.size()-1; i++){
            //如果后面是递增的，那就让它一直增加，反正不会损失
            for(int j = i+1; j < heights.size(); j++){
                while(j < heights.size()-1 && heights[j+1]>heights[j]){
                    ++j;
                }
                int minH = min(heights[i], heights[j]);
                area = max(area, (j-i)*minH);
            }
        }
        return area;
    }
    */
    
    int maxArea(vector<int> & heights){
        int ret = 0;
        if(heights.empty())
            return ret;
        int l = 0;
        int r = heights.size()-1;
        while(l<r){
            ret = max(ret, min(heights[r], heights[l])*(r-l));
            
            //谁是瓶颈，就改变谁
            if(heights[l] < heights[r])
                l++;
            else
                r--;
        }
        return ret;   
    }
};