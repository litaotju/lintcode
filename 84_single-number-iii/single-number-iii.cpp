/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/single-number-iii
@Language: C++
@Datetime: 16-03-06 15:48
*/

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        map<int, int> fre;
        vector<int> ret;
        for(int i =0; i < A.size(); i++){
            fre[ A[i] ] += 1;
        }
        for(map<int, int>::iterator it = fre.begin(); it != fre.end(); it++){
            if( it ->second == 1){
                ret.push_back(it->first);
            }
        }
        if(ret.size()!= 2){
            printf("No only 2 single numbes");
        }
        return ret;
    }
};