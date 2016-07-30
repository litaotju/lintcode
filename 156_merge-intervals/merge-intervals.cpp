/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 16-05-24 08:08
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    static bool compare(const Interval & a, const Interval &b){
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        vector<Interval> result;
        if(intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), compare);
        result.push_back(intervals[0]);
        for(int i =1; i < intervals.size(); ++i){
            if(intervals[i].start <= result.back().end){
                Interval temp(result.back().start, max(intervals[i].end, result.back().end));
                result.pop_back();
                result.push_back(temp);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    
};