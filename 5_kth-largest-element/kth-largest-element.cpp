/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 16-03-03 09:38
*/

class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        int start = 0;
        int end =nums.size() -1;
        if(end == 0 || k-1 > end){
            return 0;
        }
        int index = Partition(nums, start, end);
        while( index != nums.size()-k ) {
            if(index > nums.size() -k ){
                end = index -1;
                index = Partition(nums, start, end);
            }else{
                start = index + 1;
                index = Partition(nums, start, end);
            }
        }
        return nums[index];
    }
    
    int Partition(vector<int> & data, int start, int end){
        int i = start -1;
        int x = data[end];
        int tmp;
        for(int j = start; j <=end -1; j++){
            if( data[j] <= x){
                i++;
                tmp = data[j];
                data[j] = data[i];
                data[i] = tmp;
            }
        }
        ++i;
        tmp = data[i];
        data[i] = data[end];
        data[end] = tmp;
        return i;
    }
};