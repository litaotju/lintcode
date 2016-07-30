/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/search-a-2d-matrix
@Language: C++
@Datetime: 16-02-22 02:40
*/

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rows = matrix.size();
        if (rows == 0) {
            return false;
        }
        int cols = matrix[0].size();
        int row = 0;
        int col = cols-1;
        bool ret = false;
        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                ret = true;
                break;
            } else if (matrix[row][col] > target) {
                col--;
            } else {
                row++;
            }
        }
        return ret;
    }
};
