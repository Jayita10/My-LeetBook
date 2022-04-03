class Solution {
    int solve(int idx, bool buy, vector<vector<int>> &dp, vector<int> &prices){
        int n = prices.size();
        if(idx == n)
            return 0;
        int profit = 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy){
            int take = -prices[idx] + solve(idx+1, 0, dp, prices);
            int nottake = 0 + solve(idx+1, 1, dp, prices);
            profit = max(take, nottake);
        }
        else{
            int sell = prices[idx] + solve(idx+1, 1, dp, prices);
            int notsell = 0 + solve(idx+1, 0, dp, prices);
            profit = max(sell,notsell);
        }
        return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2,-1));
        return solve(0,1,dp,prices);
    }
};