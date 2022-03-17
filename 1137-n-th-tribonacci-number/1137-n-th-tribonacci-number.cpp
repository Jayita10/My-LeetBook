class Solution {
    /**
    //bottom up space  optimaization
        if(n<=1)
            return n;
        if(n == 2)
            return 1;
        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
        
        for(int i=3;i<=n;i++){
            int curr_i = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr_i;
        }
        return prev1;
        **/
    int solve(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(n == 2 || n == 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = solve(n-1,dp) + solve(n-2,dp) + solve(n-3,dp);
    }
public:
    int tribonacci(int n) {
        //top dowm memoisation
        vector<int> dp(n+1, -1);
        return solve(n,dp);
    }
};