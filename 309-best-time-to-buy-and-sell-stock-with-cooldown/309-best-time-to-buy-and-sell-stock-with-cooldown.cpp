class Solution {
    int solve(int idx, bool buy, vector<int> &prices, vector<vector<int>> &dp){
        int n = prices.size();
        if(idx >= n) return 0;
        int profit = 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy){
            profit = max((-prices[idx] + solve(idx+1,0,prices,dp)),
                        (0 + solve(idx+1,1,prices,dp)));
        }
        else{
            profit = max((prices[idx] + solve(idx+2,1,prices,dp)),
                        (0 + solve(idx+1,0,prices,dp)));
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};