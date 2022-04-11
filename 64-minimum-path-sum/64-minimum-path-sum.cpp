class Solution {
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i<0 || j<0) return 10000009; // huge value, so that that path wont consider
        
        if(dp[i][j] != -1) return dp[i][j];
        int up = grid[i][j] + solve(i-1,j,grid,dp);
        int left = grid[i][j] + solve(i,j-1,grid,dp);
        
        return dp[i][j] = min(up,left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0) temp[j] = grid[i][j];
                else{
                    int up = grid[i][j]; 
                    if(i>0) up += prev[j];
                    else up += 1e9; 
                    
                    int left = grid[i][j];
                    if(j>0) left += temp[j-1];
                    else left += 1e9;

                    temp[j] = min(up,left);
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};