class Solution {
    int solve(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp){
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(j<0 || j>=m) return 1e9;
        if(i == 0) return matrix[0][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int top = matrix[i][j] + solve(i-1,j,matrix,dp);
        int ld = matrix[i][j] + solve(i-1,j-1,matrix,dp);
        int rd = matrix[i][j] + solve(i-1,j+1,matrix,dp);
        
        return dp[i][j] = min(top,min(rd,ld)); 
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        int mini = 1e9;
        for(int j=0;j<n;j++){
            mini = min(mini, solve(m-1,j,matrix,dp));
        }
        
        return mini;
    }
};