/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/triangle
@Language: C++
@Datetime: 16-06-29 07:37
*/

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        if(triangle.empty())
            return 0;
        vector<vector<int> > M;
        int i, j;
        for(i =0; i<triangle.size(); i++){
            M.push_back(vector<int>(triangle[i].size(), 0));
            if(i==0){
                M[0][0] = triangle[0][0];
                continue;
            }
            for(j=0; j<=i; j++){
                if(j==0){
                    M[i][j] = triangle[i][j] + M[i-1][j];
                }else if(j==i){
                    M[i][j] = triangle[i][j] + M[i-1][j-1];
                }else{
                    M[i][j] = triangle[i][j] + min(M[i-1][j-1], M[i-1][j]);
                }
            }
        }
        int minimumLength = M[i-1][0];
        for(int col = 1; col < i; col ++){
            minimumLength = min(minimumLength, M[i-1][col]);
        }
        return minimumLength;
    }
};
