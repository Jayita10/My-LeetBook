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
    
    
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n, -1);
	    return f(n-1, arr, dp);
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