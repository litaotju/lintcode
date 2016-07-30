/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 16-03-11 12:20
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        vector<int>::iterator it = A.begin();
        if(A.size() == 0){
            return 0;
        }
        for(; it!= A.end(); it ++ ){
            while( it != A.end() and *it == elem )
                it = A.erase(it);
            if( it == A.end())
                break;
        }
        return A.size();
    }
};