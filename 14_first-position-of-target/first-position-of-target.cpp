/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/first-position-of-target
@Language: C++
@Datetime: 16-07-26 14:25
*/

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0. 
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        if(array.empty())
            return -1;
        return binarySearch(array, 0, array.size()-1, target);
    }
    
private:
    int binarySearch(const vector<int> & array, int start, int end, int target){
        if(start > end)
            return -1;
        int mid = start + (end-start)/2;
        if(array[mid]==target){
            while(mid>start){
                if(array[mid-1]!=target)
                    break;
                else
                    mid--;
            }
            return mid;
        }
        else if(array[mid]>target)
            return binarySearch(array, start, mid-1, target);
        else
            return binarySearch(array, mid+1, end, target);
    }
};