/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/strstr
@Language: C++
@Datetime: 16-03-07 13:53
*/

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if(source == NULL || target == NULL){
            return -1;
        }
        if(target[0]=='\0' ){
            return 0;
        }
        for(int index = 0; source[index] != '\0'; index++){
            if (sourceHasTarget(source+index, target) ){
                return index;
            }
        }
        return -1;
    }
    
    bool sourceHasTarget(const char* source, const char * target){
        if(target == NULL ||target[0]=='\0' ){
            return true;
        }
        if(source == NULL || source[0] == '\0'){
            return false;
        }
        for(int index = 0; target[index] != '\0'; index++){
            if(source[index] == '\0'){
                return false;
            }
            if(source[index] != target[index]){
                return false;
            }
        }
        return true;
    }
};
