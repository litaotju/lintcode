/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/search-for-a-range
@Language: C++
@Datetime: 16-03-03 16:04
*/

class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        vector<int> range;
        range.push_back(getFirstK(A, 0 , A.size()-1, target));
        range.push_back(getLastK(A, 0 , A.size()-1, target));
        return range;
    }
    
    int getFirstK(vector<int> & A, int start, int end, int target){
        if(start > end)
            return -1;
        int mid = (start+end)/2;
        if(A[mid] == target){
            if(A[mid-1] != target){
                return mid;
            }
            else{
                end = mid-1;
            }
        } else if(A[mid] > target){
            end = mid - 1;
        } else{
            start = mid + 1;
        }
        return getFirstK(A, start, end, target);
    }
    int getLastK(vector<int> & A, int start, int end, int target){
        if(start > end)
            return -1;
        int mid = (start+end)/2;
        
        if(A[mid] == target){
            if(A[mid + 1] != target){
                return mid;
            }
            else{
                start = mid+1;
            }
        } else if(A[mid] > target){
            end = mid - 1;
        } else{
            start = mid + 1;
        }
        return getLastK(A, start, end, target);
    }

};