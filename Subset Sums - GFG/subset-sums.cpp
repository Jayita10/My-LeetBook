//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void subset(vector<int> arr, int idx, int sum, int n, vector<int>&ans){
        
        if(idx >= n){
            ans.push_back(sum);
            return;
        }
        
        sum += arr[idx];
        subset(arr, idx+1, sum, n, ans);
        sum -= arr[idx];
        subset(arr, idx+1, sum, n, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        subset(arr, 0, 0, N, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends