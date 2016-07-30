/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/number-of-islands
@Language: C++
@Datetime: 16-05-26 07:22
*/

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        if(grid.empty()){
            return 0;
        }
        int count = 0;
        int row = grid.size();
        
        int col = grid[0].size();
        
        for(int i =0; i<row; i++){
            for(int j = 0; j<col ; j++){
                if(grid[i][j]==1){
                    merge(grid,i,j);
                    ++count;
                }
            }
        }
        return count;
    }
    
    
private:
    void merge(vector<vector<bool>> & grid, int row ,int col){
        if(grid.empty()){
            return;
        }
        if(row <0 || row>grid.size()-1 || col <0 || col>grid[0].size()-1){
            return;
        }
        if(grid[row][col] == 0)
            return;
        grid[row][col] =0;
        merge(grid, row-1, col);
        merge(grid, row, col-1);
        merge(grid, row, col+ 1);
        merge(grid, row+1, col);
    }    
};