/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: C++
@Datetime: 16-02-24 09:29
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int rows = matrix.size();
        if(rows == 0 ){
            return ret;
        }
        int columns = matrix[0].size();
        int start = 0;
        while( columns > start * 2 && rows > start * 2){
            PrintMatrix(ret, matrix, start);
            ++ start;
        }
    }
    
    void PrintMatrix(vector<int> & ret, vector<vector<int> > & matrix, int start){
        int endX = matrix.size() - 1 - start;
        int endY = matrix[0].size() -1 - start;
        
        for(int i = start; i <= endY; i++){
            ret.push_back(matrix[start][i]);
        }
        
        if( start < endX){
            for(int i = start + 1; i <= endX; i++){
                ret.push_back(matrix[i][endY]);
            }
        }
        
        if( start < endY && start < endX ){
            for(int i = endY - 1; i >= start; i--){
                ret.push_back(matrix[endX][i]);
            }
        }
        
        if(start < endX-1 && start < endY ){
            for(int i = endX-1; i > start; i--){
                ret.push_back(matrix[i][start]);
            }
        }
            
    }
};