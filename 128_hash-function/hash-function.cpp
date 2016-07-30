/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/hash-function
@Language: C++
@Datetime: 16-06-05 05:35
*/

class Solution {
public:
    /**
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        // write your code here
        long hash = 0;
        int index = 0;
        int length = key.size();
        while(index < length ){
            hash = hash*33 + (int)key[index++];
            hash %= HASH_SIZE;
        }
        return hash% HASH_SIZE;
    }
};