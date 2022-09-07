/*
Given an m x n matrix, return all elements of the matrix in spiral order.
Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        
        int startingrow = 0;
        int endingcol=col-1;
        int startingcol=0;
        int endingrow=row-1;
        
        int count =0;
        int total=row*col;
        
        while(count<total){
        for(int i=startingcol;count<total&&i<=endingcol;i++ ){
            ans.push_back(matrix[startingrow][i]);
            count++;
        }
           startingrow++;
            
        for(int i=startingrow;count<total&&i<=endingrow;i++ ){
            ans.push_back(matrix[i][endingcol]);
            count++;
        }
           endingcol--;
            
        for(int i=endingcol;count<total&&i>=startingcol;i-- ){
            ans.push_back(matrix[endingrow][i]);
            count++;
        }
           endingrow--;
            
        for(int i=endingrow;count<total&&i>=startingrow;i-- ){
            ans.push_back(matrix[i][startingcol]);
            count++;
        }
           startingcol++;
            
        }
        return ans;
    }
};
/*
TC : O(N)
SC : O(N)
*/
