//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int, int>> q;
        vector<int> dist(100000, INT_MAX);
        dist[start] = 0;
        q.push({0, start});
        int mod = 100000;
        
        while(!q.empty()){
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();
            
            for(auto it : arr){
                int new_start = (node*it) % mod;
                
                if(dis + 1 < dist[new_start]){
                    dist[new_start] = dis + 1;
                    
                    if(new_start == end) return dis+1;
                    q.push({dis+1, new_start});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends