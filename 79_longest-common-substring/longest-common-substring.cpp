/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/longest-common-substring
@Language: C++
@Datetime: 16-03-10 13:51
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
            string s1(A), s2(B);
            size_t size1 = s1.size();
            size_t size2 = s2.size();
            if(size1 == 0 || size2 ==0){
                return 0;
            }
            vector< vector<int> > table(size1, vector< int >(size2, 0) );
            
            // for(int i = 0; i < size1; i++){
            //     for(int j =0; j< size2; j++){
            //         cout << table[i][j] <<" ";
            //     }
            //     cout << endl;
            // }
            
            size_t i,j;
            int longest = 0;
            
             for(j = 0; j <size2; j++){
                 table[0][j] = (s1[0] == s2[j])? 1:0;
             }
             for(i = 1; i < size1; i++){
                 table[i][0] = ( (s1[i]==s2[0]) ? 1:0 );
                 for(j =1; j< size2; j++){
                     table[i][j] = (s1[i] == s2[j] ) ? ( table[i-1][j-1] + 1 ) : 0;
                 }
             }
             
                 
            // for(int i = 0; i < size1; i++){
            //     for(int j =0; j< size2; j++){
            //         cout << table[i][j] <<" ";
            //     }
            //     cout << endl;
            // }
             
             for( i =0; i< size1; i ++){
                 for( j = 0; j< size2; j++){
                     if(table[i][j] > longest ){
                         longest = table[i][j];
                     }
                 }
             }
             
             return longest;
    }
};
