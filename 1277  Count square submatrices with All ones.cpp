/*Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1*/


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        if(matrix.empty()){
            return 0;
        }
        
        vector<vector<int>> sides(matrix.size(),vector<int>(matrix[0].size(),0));
        int result = 0;
        
        for(int i = 0; i < matrix[0].size(); ++i){
            sides[0][i] = matrix[0][i];
            result += sides[0][i];
        }
        
        for(int i = 1; i < matrix.size(); ++i){
            sides[i][0] = matrix[i][0];
            result += sides[i][0];
        }
        
        for(int i = 1; i < matrix.size(); ++i){
            for(int j = 1; j < matrix[0].size(); ++j){
                if(matrix[i][j]){
                    sides[i][j] = min(sides[i - 1][j],min(sides[i][j - 1],sides[i - 1][j - 1])) + 1;
                    result += sides[i][j];
                }
            }
        }
        
        return result;
    }
};