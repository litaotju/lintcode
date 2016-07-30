/*
@Copyright:LintCode
@Author:   taoleetju
@Problem:  http://www.lintcode.com/problem/spiral-matrix-ii
@Language: C++
@Datetime: 16-03-03 10:54
*/

class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(const int n) {
        // Write your code here
        bool **IsVisited;
        IsVisited = new bool*[n];
        vector<vector<int>> v;
        if (n==0)return v;
        for (int i = 0;i<n;i++){
            v.push_back(vector<int>());
        }
        for (int i = 0; i<n; i++)
        {
            IsVisited[i] = new bool[n];
        }
        for (int i = 0; i<n; i++)
        {
            for (int j = 0; j<n; j++)
            {
                IsVisited[i][j] = false;
                v[i].push_back(0);

            }
        }

        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};
        int dxyloc = 0;
        int ii = 0;
        int jj = 0;
        int tmpval = 1;
        while (true)
        {
            if (ii==-1||jj==-1||ii==n||jj==n||IsVisited[ii][jj]==true){
                ii = ii-dy[dxyloc];
                jj = jj-dx[dxyloc];
                dxyloc = (dxyloc+1)%4;
                if (IsVisited[ii+dy[dxyloc]][jj+dx[dxyloc]]==true){
                    return v;
                }
            }
            else{
                v[ii][jj] = tmpval;
                IsVisited[ii][jj] = true;
                tmpval++;
            }
            ii = ii+dy[dxyloc];
            jj = jj+dx[dxyloc];
        }

    }
};