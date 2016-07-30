/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix-ii
@Language: C++
@Datetime: 16-02-20 02:05
*/

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        vector<vector<int> >:: size_type rows, row;
        vector<int>::size_type columns, column;
        
        rows = matrix.size();
        if(rows==0){
            return 0;
        }
        columns = matrix[0].size();
        row = 0;
        column = columns -1;
        
        int ret =0;
        
        while(row < rows && column >=0 ){
            if(matrix[row][column] == target){
                ++ ret;
                ++ row;
                --column;
            }
            else if(matrix[row][column] < target){
                ++ row;
            }
            else{
                -- column;
            }
        }
        
        return ret;
    }
};
