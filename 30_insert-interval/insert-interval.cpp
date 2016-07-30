/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: C++
@Datetime: 16-05-26 15:39
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        vector<Interval> result;
        int index = 0;
        while( index < intervals.size() ){
            if(newInterval.start <= intervals[index].start){
                break;
            }else{
                result.push_back(intervals[index]);
            }
            index ++;
        }
        if(index == 0){
            result.push_back(newInterval);
        }else if(newInterval.start <= result.back().end){
            result.back().end = max(result.back().end, newInterval.end);
        }else{
            result.push_back(newInterval);
        }
        while(index < intervals.size()){
            if(intervals[index].start <= result.back().end){
                result.back().end = max(result.back().end, intervals[index].end);
            }else{
                result.push_back(intervals[index]);
            }
            index ++;
        }
        return result;
    }
};