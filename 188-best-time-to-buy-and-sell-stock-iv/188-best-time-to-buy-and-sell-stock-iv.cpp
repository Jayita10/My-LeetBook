class Solution {
    int solve(int idx, bool buy, int cap, vector<int> &prices, vector<vector<vector<int>>>& dp){
        int n = prices.size();
        if(cap == 0 || idx == n) return 0;
        int profit = 0;
        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];
        
        if(buy){
            profit = max(-prices[idx] + solve(idx+1, 0, cap, prices, dp),
                        0 + solve(idx+1, 1, cap, prices, dp));
        }
        else{
            profit = max(prices[idx] + solve(idx+1, 1, cap-1, prices, dp),
                        0 + solve(idx+1, 0, cap, prices, dp));
        }
        return dp[idx][buy][cap] = profit;
    }
public:
    int maxProfit(int k , vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, 
                                      vector<vector<int>> (2, vector<int> (k+1 , -1)));
        return solve(0,1,k,prices,dp);
    }
};