/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/valid-sudoku
@Language: C++
@Datetime: 16-05-26 09:02
*/

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<vector<char>>& board) {
        set<char > has;
        for(int i =0; i <9; i++){
            for(int j = 0; j <9; j++){
                if(board[i][j] != '.' && has.find(board[i][j]) != has.end())
                    return false;
                else
                    has.insert(board[i][j]);
            }
            has.clear();
        }
        
        for(int j =0; j <9; j++){
            for(int i = 0;  i<9; i++){
                if(board[i][j] != '.' && has.find(board[i][j]) != has.end())
                    return false;
                else
                    has.insert(board[i][j]);
            }
            has.clear();
        }
        
        for(int i =0; i<3; i++){
            for(int j=0; j<3; j++){
                int index =0;
                int x, y;
                for(index = 0; index <9; index++){
                    x = i*3+ index/3;
                    y = j*3+ index%3;
                    if(board[x][y] != '.' && has.find(board[x][y])!=has.end())
                        return false;
                    else
                        has.insert(board[x][y]);
                }
                has.clear();
            }
        }
        return true;
    }
};