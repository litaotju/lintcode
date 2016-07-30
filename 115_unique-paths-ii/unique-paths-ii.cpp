/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/unique-paths-ii
@Language: C++
@Datetime: 16-06-28 08:19
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty())
            return 0;
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int> > unique (row, vector<int>(col, 0));
        if(1==obstacleGrid[0][0]){
            return 0;
        }
        unique[0][0] = 1;
        for(int j=1; j<col; j++ ){
            if(1 == obstacleGrid[0][j])
                unique[0][j] = 0;
            else
                unique[0][j] = unique[0][j-1];
        }
        for(int i=1; i<row; i++){
            if(1==obstacleGrid[i][0])
                unique[i][0] = 0;
            else
                unique[i][0] = unique[i-1][0];
        }
        for(int i=1; i<row; i++){
            for(int j=1; j<col; j++){
                if(1 ==obstacleGrid[i][j]){
                    unique[i][j] = 0;
                }else{
                    unique[i][j] = unique[i-1][j] + unique[i][j-1];
                }
            }
        }
        return unique[row-1][col-1];
    }
};