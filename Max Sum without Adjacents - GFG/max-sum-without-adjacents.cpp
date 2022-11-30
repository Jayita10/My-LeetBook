//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    int f(int idx, int *arr, vector<int>& dp){
        if(idx == 0) return arr[0];
        
        if(dp[idx] != -1) return dp[idx];
        if(idx < 0) return 0;
        int pick = arr[idx] + f(idx-2, arr, dp);
        int notpick = f(idx-1, arr, dp);
        return dp[idx] = max(pick, notpick);
    }
    
    int f_bottom(int *arr, int n){
        int dp[n] = {0};
	    dp[0] = arr[0];
	   
	    for(int i=1;i<n;i++){
	       int maxi = INT_MIN;
	       
	       int pick = arr[i];
	       if(i > 1) pick += dp[i-2];
	       int notpick = dp[i-1];
	       
	       dp[i] = max(pick, notpick);
	    }
	   
	   return dp[n-1];
    }
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	   // vector<int> dp(n, -1);
	   // return f_top(n-1, arr, dp);
	   
	   // return f_bottom(arr, n);
	   
	   if(n == 1) return arr[0];
	   if(n == 2) return max(arr[1], arr[0]);
	   
	   int prev1 = max(arr[1], arr[0]);
	   int prev2 = arr[0];
	   
	   for(int i=2;i<n;i++){
	       int op1 = arr[i] + prev2;
	       int op2 = prev1;
	       
	       int curri = max(op1, op2);
	       prev2 = prev1;
	       prev1 = curri;
	   }
	   return prev1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends