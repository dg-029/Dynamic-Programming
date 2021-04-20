/*
Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:

i - k <= r <= i + k,
j - k <= c <= j + k, and
(r, c) is a valid position in the matrix.
 

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
Output: [[12,21,16],[27,45,33],[24,39,28]]
Example 2:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
Output: [[45,45,45],[45,45,45],[45,45,45]]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n, k <= 100
1 <= mat[i][j] <= 100
*/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
     
        int r=mat.size();
        int c=mat[0].size();
      
        vector<vector<int>> res(r, vector<int>(c, 0));
        vector<vector<int>> presum = mat;
        
        for(int i=0; i<r-1; i++)
            presum[i+1][0] += presum[i][0]; 
        
        for(int j=0; j<c-1; j++)
            presum[0][j+1] += presum[0][j];
        
        for(int i=1; i<r; i++)
            for(int j=1; j<c; j++)
                presum[i][j] = presum[i-1][j] + presum[i][j-1] + presum[i][j] - presum[i-1][j-1];
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int north=i-k>=0?i-k:0;
                int south=i+k<r?i+k:r-1;
                int west=j-k>=0?j-k:0;
                int east=j+k<c?j+k:c-1;
                
                res[i][j]=presum[south][east];
                if(north!=0)
                    res[i][j]-=presum[north-1][east];
                if(west!=0)
                    res[i][j]-=presum[south][west-1];
                if(west!=0 && north!=0)
                    res[i][j]+=presum[north-1][west-1];
            }
        }
        
        return res;
    }
};