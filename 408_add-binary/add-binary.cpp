/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/add-binary
@Language: C++
@Datetime: 16-05-26 08:36
*/

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        int indexa = a.size()-1;
        int indexb = b.size()-1;
        bool carry = false;
        char sum;
        string result;
        bool tempa, tempb;
        
        while(indexa >= 0 && indexb >=0){
            tempa = a[indexa]=='1';
            tempb = b[indexb]=='1';
            sum = (tempa ^ tempb ^ carry)? '1':'0';
            carry = (tempa && tempb) || (carry &&(tempa || tempb));
            result = sum + result;
            indexa --;
            indexb--;
        }
        while(indexa >= 0){
            if(carry){
                tempa = a[indexa]=='1';
                sum = (tempa ^ carry)? '1':'0';
                carry = carry &&tempa;
                result = sum + result;
                indexa --;
            }else{
                result = a[indexa--] + result;
            }
        }
        while(indexb >=0){
            if(carry){
                tempb = b[indexb]=='1';
                sum = (tempb ^ carry)? '1':'0';
                carry = carry &&tempb;
                result = sum + result;
                indexb --;
            }else{
                result = b[indexb--] + result;
            }
        }
        if(carry)
            result ='1'+result;
        return result;
    }
};