class Solution {
    int solve(int n, vector<int> &dp){
        if(n<=1)
            return n;
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
public:
    int fib(int n) {
        //top-down
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};