/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/minimum-path-sum
@Language: C++
@Datetime: 16-06-02 12:20
*/

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
            return 0;
        
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        int i=0, j=0;
        for(j=1; j <= col; j++){
            grid[i][j] += grid[i][j-1];
        }
        j = 0;
        for(i = 1; i <= row; i++){
            grid[i][j] += grid[i-1][j];
        }
        i = 0;
        for( i = 1; i<= row; i++){
            for(j = 1; j<= col; j++){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[row][col];
    }
};
