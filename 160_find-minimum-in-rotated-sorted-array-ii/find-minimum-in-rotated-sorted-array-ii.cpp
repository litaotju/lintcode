/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/find-minimum-in-rotated-sorted-array-ii
@Language: C++
@Datetime: 16-05-28 09:20
*/

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        if(num.empty()){
            return 0;
        }
        int index1 = 0;
        int index2 = num.size()-1;
        //当数组没有旋转，也就是第0个元素小于最后一个元素时，返回0，所以mid初始化为0
        int mid = index1;
        while(num[index2]<=num[index1]){
            if(index2-index1 == 1){
                return num[index2];
            }
            mid = index1+ (index2-index1)/2;
            if(num[index1]== num[index2] && num[index1] == num[mid]){
                //三个全相等，直接找最小值
                return findMinInorder(num, index1, index2);
            }
            
            if(num[mid] >= num[index1]){
                index1 = mid;
            }
            if(num[mid] <= num[index2]){
                index2 = mid;
            }
        }
        return num[mid];
    }
    
    
    int findMinInorder(const vector<int> & num, int start, int end){
        int result = num[start];
        for(int i = start+1; i<=end; i++){
            if(num[i] < result){
                result = num[i];
            }
        }
        return result;
    }
};