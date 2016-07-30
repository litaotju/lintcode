/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/assignment-operator-overloading-c-only
@Language: C++
@Datetime: 16-02-22 02:56
*/

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution & operator=(const Solution &object) {
        if(this != &object){
            char * tmp;
            if(object.m_pData != NULL){
                tmp = new char[ strlen(object.m_pData) + 1 ];
                strcpy(tmp, object.m_pData);
            } else {
                tmp = NULL;
            }
            delete m_pData;
            m_pData = NULL;
            m_pData = tmp;
        }
        return *this;
    }
};