/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/string-permutation
@Language: C++
@Datetime: 16-02-23 04:14
*/

class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        
        map<char, int> freA, freB;

        bool ret = false;
        
        if( A.size() == B.size() ){
            ret = true;
            for(int i =0; i< A.size(); i++){
                freA[ A[i] ] += 1;
                freB[ B[i] ] += 1;
            }
        
            map<char, int>::iterator it;
            for(it = freA.begin(); it != freA.end(); ++it ){
                if( freB[it->first] != it->second){
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }
};