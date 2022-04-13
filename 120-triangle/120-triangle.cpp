class Solution {
    int solve(int i, int j, int r, int c, vector<vector<int>> &triangle, vector<vector<int>> &dp){

        if(i>=r || j>=c) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        int bottom = triangle[i][j] + solve(i+1,j,r,c,triangle,dp);
        int diago = triangle[i][j] + solve(i+1,j+1,r,c,triangle,dp);
        
        return dp[i][j] = min(bottom,diago);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int col = triangle[row-1].size();
        vector<vector<int>> dp(row, vector<int>(col,-1));
        return solve(0,0,row,col,triangle,dp);
    }
};